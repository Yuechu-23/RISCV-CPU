# RISCV-CPU

## 日志

- 260415：修改ControlUnit.v，有待验证与继续修改


## 其他待修改（总结钉钉问题）

- IM.v改为同步memory访问，添加clk端口，改为时序逻辑，用提供的memory替换（/home/library/tsmc65lp SRAM 2048*64 tt ? 后端时需要初赛不需要）
- IR.v可改为组合逻辑实现，可最后实现
- RF.v register修改为reg [31:0] register[1:31]，声明x0为reg[31:0] r0
- 添加模块最好加在子模块中
- 已有连线不再改动，可修改连线名字
- 不修改原有port位宽，可增加input/output
- 不修改`include内容，可新增