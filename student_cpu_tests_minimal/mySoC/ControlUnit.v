`timescale 1ns/1ps

`include "ctrl_signal_def.v"
`include "instruction_def.v"

module ControlUnit(
    input rst,
    input clk,
    input zero,
    input [6:0] opcode,
    input [6:0] Funct7,
    input [2:0] Funct3,
    output reg PCWrite,       // PC update
    output reg InsMemRW,      // Instruction memory read/write
    output reg IRWrite,       // Instruction register write
    output reg RFWrite,       // Register file write
    output reg DMCtrl,        // Data memory control
    output reg ExtSel,        // Immediate extension select
    output reg ALUSrcA,       // ALU source A select
    output reg [1:0] ALUSrcB, // ALU source B select
    output reg [1:0] RegSel,  // Register file write address select
    output reg [1:0] NPCOp,   // Next PC operation
    output reg [1:0] WDSel,   // Write data select
    output reg [3:0] ALUOp,   // ALU operation
    output reg AWrite,        // A寄存器写使能
    output reg BWrite,        // B寄存器写使能
    output reg ALUOutWrite,   // ALUOut寄存器写使能
    output [3:0] state_dbg    // 当前状态，供测试提交信号使用
);

    wire [9:0] funct_all;
    assign funct_all = {Funct7, Funct3};

    // 新增U-type操作码（不依赖instruction_def.v，避免你当前宏不全）
    localparam [6:0] INSTR_LUI_OP   = 7'b0110111;
    localparam [6:0] INSTR_AUIPC_OP = 7'b0010111;

    localparam [3:0] ST_IF_REQ   = 4'd0;
    localparam [3:0] ST_IF_LATCH = 4'd1;
    localparam [3:0] ST_ID       = 4'd2;
    localparam [3:0] ST_EX_ALU   = 4'd3;
    localparam [3:0] ST_EX_ADDR  = 4'd4;
    localparam [3:0] ST_EX_BR    = 4'd5;
    localparam [3:0] ST_EX_JAL   = 4'd6;
    localparam [3:0] ST_EX_JALR  = 4'd7;
    localparam [3:0] ST_MEM_RD   = 4'd8;
    localparam [3:0] ST_MEM_WB   = 4'd9;
    localparam [3:0] ST_MEM_WR   = 4'd10;
    localparam [3:0] ST_WB_ALU   = 4'd11;

    reg [3:0] state;
    assign state_dbg = state;

    // 多周期FSM状态寄存器
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= ST_IF_REQ;
        end
        else begin
            case (state)
                ST_IF_REQ: begin
                    state <= ST_IF_LATCH;
                end

                ST_IF_LATCH: begin
                    state <= ST_ID;
                end

                ST_ID: begin
                    case (opcode)
                        `INSTR_RTYPE_OP,
                        `INSTR_ITYPE_OP,
                        INSTR_LUI_OP,
                        INSTR_AUIPC_OP: state <= ST_EX_ALU;

                        `INSTR_LW_OP,
                        `INSTR_SW_OP:    state <= ST_EX_ADDR;

                        `INSTR_BTYPE_OP: state <= ST_EX_BR;
                        `INSTR_JAL_OP:   state <= ST_EX_JAL;
                        `INSTR_JALR_OP:  state <= ST_EX_JALR;

                        default:         state <= ST_IF_REQ;
                    endcase
                end

                ST_EX_ALU: begin
                    state <= ST_WB_ALU;
                end

                ST_WB_ALU: begin
                    state <= ST_IF_REQ;
                end

                ST_EX_ADDR: begin
                    if (opcode == `INSTR_LW_OP)
                        state <= ST_MEM_RD;
                    else
                        state <= ST_MEM_WR;
                end

                ST_MEM_RD: begin
                    state <= ST_MEM_WB;
                end

                ST_MEM_WB,
                ST_MEM_WR,
                ST_EX_BR,
                ST_EX_JAL,
                ST_EX_JALR: begin
                    state <= ST_IF_REQ;
                end

                default: begin
                    state <= ST_IF_REQ;
                end
            endcase
        end
    end

    always @(*) begin
        // 默认值（安全关闭）
        PCWrite     = 1'b0;
        InsMemRW    = 1'b0;
        IRWrite     = 1'b0;
        RFWrite     = 1'b0;
        AWrite      = 1'b0;
        BWrite      = 1'b0;
        ALUOutWrite = 1'b0;
        DMCtrl      = `DMCtrl_RD;
        ExtSel      = `ExtSel_SIGNED;
        ALUSrcA     = `ALUSrcA_A;
        ALUSrcB     = `ALUSrcB_B;
        RegSel      = `RegSel_rd;
        NPCOp       = `NPC_PC;
        WDSel       = `WDSel_FromALU;
        ALUOp       = `ALUOp_ADD;

        if (!rst) begin
            case (state)
                // IF1: 发出IM同步读请求
                ST_IF_REQ: begin
                    InsMemRW = 1'b1;
                end

                // IF2: 锁存指令并PC+4
                ST_IF_LATCH: begin
                    IRWrite = 1'b1;
                    PCWrite = 1'b1;
                    NPCOp   = `NPC_PC;
                end

                // ID: 读取寄存器并锁存到A/B寄存器
                ST_ID: begin
                    AWrite = 1'b1;
                    BWrite = 1'b1;
                end

                // EX(ALU): R-type / I-type / U-type 运算，结果进ALUOut
                ST_EX_ALU: begin
                    RegSel      = `RegSel_rd;
                    WDSel       = `WDSel_FromALU;
                    ALUOutWrite = 1'b1;

                    if (opcode == `INSTR_RTYPE_OP) begin
                        ALUSrcA = `ALUSrcA_A;
                        ALUSrcB = `ALUSrcB_B;
                        case (funct_all)
                            `INSTR_ADD_FUNCT: ALUOp = `ALUOp_ADD;
                            `INSTR_SUB_FUNCT: ALUOp = `ALUOp_SUB;
                            `INSTR_AND_FUNCT: ALUOp = `ALUOp_AND;
                            `INSTR_OR_FUNCT : ALUOp = `ALUOp_OR;
                            `INSTR_XOR_FUNCT: ALUOp = `ALUOp_XOR;
                            `INSTR_SLL_FUNCT: ALUOp = `ALUOp_SLL;
                            `INSTR_SRL_FUNCT: ALUOp = `ALUOp_SRL;
                            `INSTR_SRA_FUNCT: ALUOp = `ALUOp_SRA;
                            default:          ALUOp = `ALUOp_ADD;
                        endcase
                    end
                    else if (opcode == `INSTR_ITYPE_OP) begin
                        ALUSrcA = `ALUSrcA_A;
                        ALUSrcB = `ALUSrcB_Imm;
                        case (Funct3)
                            3'b000: begin // ADDI
                                ExtSel = `ExtSel_SIGNED;
                                ALUOp  = `ALUOp_ADD;
                            end
                            3'b010: begin // SLTI（先用BR比较通路，后续ALU里完善）
                                ExtSel = `ExtSel_SIGNED;
                                ALUOp  = `ALUOp_BR;
                            end
                            3'b011: begin // SLTIU（同上，后续ALU完善无符号）
                                ExtSel = `ExtSel_SIGNED;
                                ALUOp  = `ALUOp_BR;
                            end
                            3'b100: begin // XORI
                                ExtSel = `ExtSel_SIGNED;
                                ALUOp  = `ALUOp_XOR;
                            end
                            3'b110: begin // ORI
                                ExtSel = `ExtSel_SIGNED;
                                ALUOp  = `ALUOp_OR;
                            end
                            3'b111: begin // ANDI
                                ExtSel = `ExtSel_SIGNED;
                                ALUOp  = `ALUOp_AND;
                            end
                            3'b001: begin // SLLI
                                ExtSel = `ExtSel_ZERO;
                                ALUOp  = `ALUOp_SLL;
                            end
                            3'b101: begin
                                ExtSel = `ExtSel_ZERO;
                                if (Funct7 == 7'b0100000) // SRAI
                                    ALUOp = `ALUOp_SRA;
                                else                      // SRLI
                                    ALUOp = `ALUOp_SRL;
                            end
                            default: begin
                                ExtSel = `ExtSel_SIGNED;
                                ALUOp  = `ALUOp_ADD;
                            end
                        endcase
                    end
                    else if (opcode == INSTR_LUI_OP) begin
                        // LUI: rd = imm << 12
                        // 复用现有路径：A=0, B=Imm12(符号扩展) 后续建议配合EXT/ALU再完善成标准U-imm
                        ALUSrcA = `ALUSrcA_sa;  // 选择0
                        ALUSrcB = `ALUSrcB_Imm;
                        ExtSel  = `ExtSel_SIGNED;
                        ALUOp   = `ALUOp_ADD;
                    end
                    else if (opcode == INSTR_AUIPC_OP) begin
                        // AUIPC: rd = pc + imm << 12
                        // 先保留最小路径，后续建议新增U-imm专用通路
                        ALUSrcA = `ALUSrcA_sa;  // 当前MUX里sa对应0，后续需结合顶层增强
                        ALUSrcB = `ALUSrcB_Imm;
                        ExtSel  = `ExtSel_SIGNED;
                        ALUOp   = `ALUOp_ADD;
                    end
                end

                // WB(ALU): ALUOut写回寄存器
                ST_WB_ALU: begin
                    RFWrite = 1'b1;
                    RegSel  = `RegSel_rd;
                    WDSel   = `WDSel_FromALU;
                end

                // EX(ADDR): LW/SW地址计算
                ST_EX_ADDR: begin
                    ExtSel      = `ExtSel_SIGNED;
                    ALUSrcA     = `ALUSrcA_A;
                    ALUSrcB     = `ALUSrcB_Offset;
                    ALUOp       = `ALUOp_ADD;
                    ALUOutWrite = 1'b1;
                end

                // MEM读
                ST_MEM_RD: begin
                    DMCtrl = `DMCtrl_RD;
                end

                // MEM读后写回
                ST_MEM_WB: begin
                    RFWrite = 1'b1;
                    RegSel  = `RegSel_rd;
                    WDSel   = `WDSel_FromMEM;
                end

                // MEM写
                ST_MEM_WR: begin
                    DMCtrl = `DMCtrl_WR;
                end

                // 分支比较并更新PC（扩展到所有B型）
                ST_EX_BR: begin
                    ALUSrcA = `ALUSrcA_A;
                    ALUSrcB = `ALUSrcB_B;
                    ALUOp   = `ALUOp_BR;
                    PCWrite = 1'b0;

                    case (Funct3)
                        3'b000: begin // BEQ
                            if (zero) begin
                                PCWrite = 1'b1;
                                NPCOp   = `NPC_Offset12;
                            end
                        end
                        3'b001: begin // BNE
                            if (!zero) begin
                                PCWrite = 1'b1;
                                NPCOp   = `NPC_Offset12;
                            end
                        end
                        3'b100, // BLT
                        3'b101, // BGE
                        3'b110, // BLTU
                        3'b111: begin // BGEU
                            // 先统一走BR比较（后续ALU需区分有/无符号与比较方向）
                            if (!zero) begin
                                PCWrite = 1'b1;
                                NPCOp   = `NPC_Offset12;
                            end
                        end
                        default: begin
                            PCWrite = 1'b0;
                        end
                    endcase
                end

                // JAL: PC跳转并写回PC+4
                ST_EX_JAL: begin
                    PCWrite = 1'b1;
                    NPCOp   = `NPC_Offset20;
                    RFWrite = 1'b1;
                    RegSel  = `RegSel_rd;
                    WDSel   = `WDSel_FromPC;
                end

                // JALR: PC跳转并写回PC+4
                ST_EX_JALR: begin
                    ExtSel  = `ExtSel_SIGNED;
                    PCWrite = 1'b1;
                    NPCOp   = `NPC_rs;
                    RFWrite = 1'b1;
                    RegSel  = `RegSel_rd;
                    WDSel   = `WDSel_FromPC;
                end

                default: begin
                    InsMemRW = 1'b1;
                end
            endcase
        end
    end

endmodule