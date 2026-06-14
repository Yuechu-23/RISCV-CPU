# RISC-V 五级流水线 CPU 实验报告



## 一、架构图

当前 CPU 采用经典 IF、ID、EX、MEM、WB 五级流水线结构。顶层 `miniRV_SoC` 只负责连接 FPGA 时钟复位和调试提交接口，核心流水线均在 `riscv.v` 内部实现。

![五级流水线 CPU 架构图](file:///C:/Users/14780/Desktop/RISCV-CPU/assets/pipeline_architecture.png)

*图 1 五级流水线 CPU 架构图。该图片由 ChatGPT 图像生成接口根据当前 `mySoC` RTL 结构生成。*

## 二、总体设计方案

CPU 的指令执行被划分为五个流水级：

| 流水级 | 主要功能 | 细化设计 |
|---|---|---|
| IF | 取指与预测下一 PC | `PC` 使用 `PC[14:2]` 访问 `IM`，同时根据当前指令和 BHT 生成 `if_predicted_pc`；redirect 优先级高于预测 PC，load-use 暂停时保持 PC |
| ID | 译码、读寄存器与冒险检测 | `Decode` 产生组合控制信号，`ImmGen` 生成各类立即数，`RF` 组合读 `rs1/rs2`；若 WB 级写回寄存器与当前读寄存器相同，则直接旁路 `wb_wdata` |
| EX | 运算、比较与真实控制流确认 | 先完成 EX/MEM 和 MEM/WB 前递选择，再由 `ALU` 执行运算或地址计算；分支、`jal`、`jalr` 在本级得到真实下一 PC，并通过 `redirect_taken` 校正错误预测 |
| MEM | 数据存储器访问 | `DM` 根据 `ex_mem_alu_result`、`Funct3` 和 `DMCtrl` 完成 load 扩展读或 store 局部写；当前仅访问 `Addr[31:16] == 16'h0000` 的内部数据空间 |
| WB | 写回与提交 | `mem_wb_wd_sel` 选择 ALU、MEM、PC+4 或 U 型数据写回；`mem_wb_valid` 同时驱动 `debug_wb_*` 提交接口 |

四组显式流水寄存器将各级隔开：`if_id_*`、`id_ex_*`、`ex_mem_*`、`mem_wb_*`。每组寄存器均携带 `valid` 位，用于区分真实指令与气泡。控制信号在 ID 阶段由 `Decode` 组合产生，随后随指令一起进入 `ID/EX`、`EX/MEM`、`MEM/WB`，避免旧多周期设计中依赖全局状态机分阶段驱动的方式。

PC 更新采用预测优先策略：正常情况下 `pc_next = if_predicted_pc`；若 EX 阶段发现分支或跳转预测错误，则 `pc_next = redirect_pc`，同时冲刷年轻指令。Load-use 冒险发生时暂停 PC 和 IF/ID，并向 ID/EX 插入气泡。

## 三、指令集说明

当前实现覆盖 RV32I 常用整数指令子集，支持算术逻辑、移位、比较、访存、条件分支、无条件跳转和 U 型立即数指令。

| 类型 | 支持指令 | 数据通路说明 |
|---|---|---|
| R 型算术逻辑 | `add`、`sub`、`and`、`or`、`xor`、`sll`、`srl`、`sra`、`slt`、`sltu` | `rs1` 与 `rs2` 经前递选择后进入 ALU，结果经 WB 写回 `rd` |
| I 型算术逻辑 | `addi`、`andi`、`ori`、`xori`、`slti`、`sltiu`、`slli`、`srli`、`srai` | `rs1` 与 I 型立即数进入 ALU；移位立即数使用零扩展，其余使用符号扩展 |
| Load | `lb`、`lh`、`lw`、`lbu`、`lhu` | EX 级计算 `rs1 + imm` 地址，MEM 级由 `DM` 按 `Funct3` 完成字节、半字、字读取及扩展 |
| Store | `sb`、`sh`、`sw` | EX 级计算地址，MEM 级按 `Funct3` 与地址低位写入字节、半字或字 |
| B 型分支 | `beq`、`bne`、`blt`、`bge`、`bltu`、`bgeu` | IF 级预测方向与目标，EX 级根据前递后的操作数计算真实方向并校正 PC |
| J 型跳转 | `jal` | IF 级直接预测跳转到 `PC + ImmJ`，WB 写回 `PC + 4` |
| I 型跳转 | `jalr` | EX 级计算 `(rs1 + ImmI) & 0xFFFF_FFFE`，WB 写回 `PC + 4` |
| U 型 | `lui`、`auipc` | `lui` 写回 `ImmU`，`auipc` 写回 `PC + ImmU` |

各类指令的立即数由 `ImmGen` 统一生成：

| 立即数 | 生成方式 | 使用场景 |
|---|---|---|
| `ImmI` | I 型符号扩展 | I 型算术、load、`jalr` |
| `ImmIZero` | I 型零扩展 | `slli`、`srli`、`srai` |
| `ImmS` | S 型符号扩展 | Store 地址偏移 |
| `ImmB` | B 型符号扩展并低位补 0 | 条件分支目标 |
| `ImmU` | 高 20 位立即数左移 12 位 | `lui`、`auipc` |
| `ImmJ` | J 型符号扩展并低位补 0 | `jal` 目标 |

## 四、关键技术说明

1. 流水线寄存器与有效位控制。当前实现使用显式五级流水线寄存器组织数据通路。`IF/ID` 保存取到的指令、PC 与预测 PC，`ID/EX` 保存源操作数、立即数、寄存器号和控制信号，`EX/MEM` 保存 ALU 结果、Store 数据和访存控制，`MEM/WB` 保存写回来源和提交信息。各流水级均带有 `valid` 位，气泡通过清零 `valid` 以及关闭 `mem_read`、`mem_write`、`rf_we` 等关键写使能实现。

2. 组合译码与控制信号流水化。控制信号采用“组合译码 + 流水传递”的方式生成。`Decode` 只根据 opcode、`Funct3` 和 `Funct7` 产生 ALU、访存、写回与控制流相关信号，不再依赖多周期 FSM；这些控制信号随指令进入后续流水级，使每条指令在自己的流水节拍中携带对应控制信息。

3. 数据冒险前递处理。数据冒险主要通过前递解决。EX 级优先从 EX/MEM 前递非 load 的可用结果，其次从 MEM/WB 前递最终写回结果，减少相邻 ALU 指令之间的等待。对于寄存器堆同周期写读同一寄存器的情况，ID 级还加入了 WB 到 ID 的旁路：当 `mem_wb_rd` 与当前 `rs1` 或 `rs2` 匹配时，直接使用 `wb_wdata` 覆盖 RF 读出的旧值。Store 指令的写入数据同样走 `ex_rs2_data`，因此也能复用这套前递机制。

4. Load-use 暂停机制。Load-use 冒险需要额外暂停。由于 load 数据要到 MEM/WB 阶段才稳定可用，当 ID 阶段指令立即依赖 ID/EX 阶段 load 的 `rd` 时，`load_use_stall` 置位：PC 保持不变，IF/ID 保持原指令，ID/EX 清空有效位并关闭写使能，从而插入一个气泡。这样既避免读取未完成的 load 结果，也保证流水线后续状态保持一致。

5. 控制冒险预测、校正与冲刷。控制冒险通过预测、校正和冲刷处理。IF 级使用 64 项 2-bit BHT 预测条件分支，未训练项采用后向分支预测 taken、前向分支预测 not taken，`jal` 默认预测跳转。条件分支、`jal` 和 `jalr` 在 EX 级得到真实下一 PC；如果 `id_ex_predicted_pc` 与 `ex_actual_next_pc` 不一致，则触发 `redirect_taken`，下一拍 PC 写入 `redirect_pc`，同时清空 IF/ID 和 ID/EX 中的错误路径指令。EX/MEM 与 MEM/WB 中更老的指令继续提交，因此不会破坏已经确定的执行结果。

6. 访存宽度处理与调试提交。访存模块 `DM` 以 32 位字为基本存储单元，通过 `Addr[1:0]` 选择字节或半字，并根据 `Funct3` 完成 `lb/lh` 的符号扩展、`lbu/lhu` 的零扩展以及 `sb/sh/sw` 的局部写入。提交接口以 `mem_wb_valid` 作为有效信号，在 WB 级统一输出 `debug_wb_pc`、`debug_wb_ena`、`debug_wb_reg` 和 `debug_wb_value`，便于测试框架按指令提交顺序观察结果。

## 五、数据流 / 控制流设计框图

![五级流水线数据流与控制流设计图](file:///C:/Users/14780/Desktop/RISCV-CPU/assets/pipeline_data_control_flow.png)

*图 2 五级流水线数据流与控制流设计图。该图片由 ChatGPT 图像生成接口根据当前 `mySoC` RTL 的前递、暂停、冲刷和 BHT 更新机制生成。*

### 主要数据路径

| 路径 | 流向 | 说明 |
|---|---|---|
| 取指路径 | `PC -> IM -> IF/ID.inst` | `IM` 为组合读，取出的指令与当前 PC、预测 PC 一起进入 IF/ID |
| 译码路径 | `IF/ID.inst -> Decode / ImmGen / RF` | 译码得到控制信号，立即数生成器得到各格式立即数，RF 读出源寄存器 |
| ALU 路径 | `ID/EX 操作数 -> 前递选择 -> ALU -> EX/MEM` | R/I 指令产生运算结果，Load/Store 产生有效地址 |
| Load 路径 | `EX/MEM.alu_result -> DM -> MEM/WB.mem_data -> WB` | `DM` 根据 `Funct3` 完成扩展，WB 写回 `rd` |
| Store 路径 | `EX/MEM.alu_result + store_data -> DM` | Store 数据在 EX 级经过前递后写入 `EX/MEM.store_data` |
| 跳转路径 | `ID/EX.pc + ImmJ` 或 `rs1 + ImmI` | `jal` 目标可在 IF 预测，`jalr` 目标必须在 EX 使用寄存器值计算 |
| 提交路径 | `MEM/WB -> debug_wb_*` | 所有有效指令在 WB 级以统一接口提交给测试框架 |

### 主要控制路径

| 控制信号 | 产生位置 | 作用 |
|---|---|---|
| `id_alu_op` | ID | 选择 ALU 运算，如 ADD、SUB、AND、SLT、SLTU、移位等 |
| `id_alu_src_b` | ID | 选择 ALU B 端来自寄存器、I 型立即数或访存偏移 |
| `id_mem_read` / `id_mem_write` | ID | 随流水进入 MEM 级后控制 `DM` 读写 |
| `id_rf_we` | ID | 随流水进入 WB 级后控制寄存器写回 |
| `id_wd_sel` | ID | 在 WB 级选择 ALU、MEM、PC+4 或 U 型数据 |
| `load_use_stall` | ID | 暂停 PC 和 IF/ID，并把 ID/EX 变为气泡 |
| `redirect_taken` | EX | 当预测 PC 与真实 PC 不一致时，改写 PC 并冲刷错误路径 |
| `pc_write` | IF/EX/ID 综合 | 正常情况下允许 PC 前进；load-use 时暂停；redirect 时强制更新 |

## 六、子模块时序说明

| 子模块或寄存器 | 时序类型 | 时序行为 |
|---|---|---|
| `PC` | `posedge clk or posedge rst` | 复位清零；`PCWrite` 为 1 时写入 `NPC` |
| `IF/ID` | `posedge clk or posedge rst` | 复位或 redirect 时清零；load-use 时保持；正常时锁存 `PC`、`in_ins`、`if_predicted_pc` |
| `ID/EX` | `posedge clk or posedge rst` | 复位清零；redirect 或 load-use 时插入气泡；正常时锁存 ID 级数据和控制信号 |
| `EX/MEM` | `posedge clk or posedge rst` | 锁存 EX 级 ALU 结果、Store 数据、U 型写回数据、访存控制和写回控制 |
| `MEM/WB` | `posedge clk or posedge rst` | 锁存 MEM 级读数据、ALU 结果、PC+4、U 型数据、目标寄存器和写回控制 |
| `branch_bht` | `posedge clk or posedge rst` | 复位时所有计数器置 `2'b01` 且 valid 清零；EX 级分支完成后按 taken/not taken 饱和更新 |
| `RF` | 读组合，写时序 | `RR1`、`RR2` 组合读；`RFWrite` 且 `WR != 0` 时上升沿写入；`x0` 保持为 0 |
| `IM` | 组合读，初始化装载 | `InsMemRW` 为 1 时输出 `memory[addr]`；仿真时可用 `PATH` 宏加载二进制并做字节序调整 |
| `DM` | 读组合，写时序 | 读按地址和 `Funct3` 组合产生；写在时钟上升沿完成，支持 `sb`、`sh`、`sw` |
| `ALU` | 组合逻辑 | 根据 `ALUOp` 立即产生算术逻辑、移位或比较结果 |
| `Decode` | 组合逻辑 | 根据 opcode、`Funct3`、`Funct7` 产生指令类别和控制信号 |
| `ImmGen` | 组合逻辑 | 并行生成 I、S、B、U、J 型立即数 |
| `debug_wb_*` | `posedge clk or posedge rst` | WB 级提交时更新调试端口；复位时清零 |

## 七、顶层接口与测试适配

`miniRV_SoC.sv` 作为测试框架需要的 SoC 顶层，端口包括：

| 信号 | 方向 | 说明 |
|---|---|---|
| `fpga_clk` | input | CPU 时钟 |
| `fpga_rst` | input | CPU 异步复位 |
| `debug_wb_have_inst` | output | WB 级存在有效提交指令 |
| `debug_wb_pc` | output | 提交指令 PC |
| `debug_wb_ena` | output | 提交指令是否写寄存器 |
| `debug_wb_reg` | output | 写回寄存器号 |
| `debug_wb_value` | output | 写回数据 |

当前实现将 `debug_wb_have_inst` 直接对应 `mem_wb_valid`，这与流水线提交点一致。对于 Store 和 Branch 这类不写寄存器的指令，`debug_wb_have_inst` 仍会有效，但 `debug_wb_ena` 为 0，用于表示指令已经完成。

## 八、附加要求：分支预测技术分析

当前实现包含明确的动态分支预测机制，核心数据结构为：

```verilog
localparam BHT_ENTRIES = 64;
reg [1:0] branch_bht [0:BHT_ENTRIES-1];
reg branch_bht_valid [0:BHT_ENTRIES-1];
```

### 预测索引与冷启动策略

BHT 使用 `PC[7:2]` 作为索引，共 64 项。每项包含一个 2-bit 饱和计数器和一个 valid 位。复位后所有计数器为 `2'b01`，即弱 not taken，同时 valid 为 0。

对于条件分支，IF 级采用如下策略：

| 情况 | 预测规则 |
|---|---|
| BHT 项 valid | 使用 2-bit 计数器最高位预测，`1` 表示 taken，`0` 表示 not taken |
| BHT 项 invalid | 使用静态后向分支预测，`if_imm_b[31] == 1` 时预测 taken，否则预测 not taken |
| `jal` | 总是预测 taken，目标为 `PC + ImmJ` |
| `jalr` | 不在 IF 级预测目标，默认沿 `PC + 4`，到 EX 级计算真实目标后 redirect |

后向分支通常对应循环，因此冷启动时预测 taken 可以提升循环类程序第一次执行时的效果；前向分支常用于条件跳过代码，因此默认 not taken 较合理。

### 2-bit 饱和计数器更新

条件分支到达 EX 级后，CPU 得到真实 `ex_branch_taken`。若该指令有效且确认为 B 型分支，则更新对应 BHT 项：

| 原状态 | 分支 taken 后 | 分支 not taken 后 | 含义 |
|---|---|---|---|
| `00` | `01` | `00` | 强 not taken |
| `01` | `10` | `00` | 弱 not taken |
| `10` | `11` | `01` | 弱 taken |
| `11` | `11` | `10` | 强 taken |

预测时只看最高位，因此 2-bit 计数器能够避免一次偶然反向就立刻改变强预测方向，适合循环最后一次退出这类常见模式。

### 预测正确性恢复

每条进入 IF/ID 的指令会保存 `if_id_predicted_pc`，并继续传到 `id_ex_predicted_pc`。当控制流指令在 EX 级算出 `ex_actual_next_pc` 后，CPU 比较：

```verilog
redirect_taken = id_ex_valid && ex_is_control_flow &&
                 (id_ex_predicted_pc != ex_actual_next_pc);
```

如果预测 PC 与真实 PC 不一致，就把 `redirect_pc` 设为真实下一 PC，并清空 IF/ID 与 ID/EX。这样可以保证错误路径指令不会产生写回或访存副作用。

### 技术特点与局限

| 项目 | 分析 |
|---|---|
| 优点 | BHT 小而简单，硬件代价低；2-bit 计数器对循环分支效果好；未训练项结合后向静态预测，冷启动行为优于单纯默认 not taken |
| 优点 | 分支目标在 IF 级由当前指令立即数计算，预测 taken 时不必等到 EX 才取目标路径 |
| 局限 | BHT 只有 64 项，使用 `PC[7:2]` 直接索引，存在不同分支互相覆盖的别名问题 |
| 局限 | 没有 BTB，当前只对 B 型和 `jal` 可在 IF 级形成目标；`jalr` 依赖寄存器值，仍需 EX 级 redirect |
| 局限 | 没有全局历史或局部历史，难以捕捉交替型、相关型分支模式 |
| 局限 | 分支真实结果在 EX 级确认，预测错误时仍需要冲刷流水线并损失若干周期 |

总体来看，本实现已经从“固定 PC+4，分支到 EX 后再改 PC”的简单流水线，提升为“IF 级预测取指，EX 级验证和恢复”的预测型流水线。该设计在控制复杂度和性能收益之间保持了较好的平衡，尤其适合本实验中的 RV32I 基础测试和循环程序。

## 九、总结与改进方向

本 CPU 当前实现为五级流水线 RV32I 子集处理器，核心特征包括：显式流水寄存器与 valid 位、组合译码与控制信号流水化、EX/MEM 和 MEM/WB 前递、load-use 单周期暂停、EX 级控制流恢复、64 项 2-bit BHT 分支预测，以及统一 WB 级调试提交接口。与旧版多周期报告中的 ControlUnit 状态机、IR/A/B/ALUOut 多周期寄存器叙述不同，当前实现已经以流水线并发推进多条指令为基本组织方式。

后续可以继续改进：

1. 增加 BTB 或返回地址栈，进一步优化 `jalr`、函数调用和返回。
2. 扩展 BHT 容量或加入局部/全局历史，降低别名冲突并提升复杂分支预测准确率。
3. 增加异常、非法指令和访存越界处理，使 CPU 更接近完整处理器。
4. 将 `IM`、`DM` 封装为更通用的总线接口，便于连接外设或缓存。
5. 增加随机指令测试、覆盖率统计和流水线断言，验证前递、暂停与冲刷边界情况。
