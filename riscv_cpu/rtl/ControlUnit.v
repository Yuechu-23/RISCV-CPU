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
    output reg MDRWrite       // MDR寄存器写使能
);

    wire [9:0] funct_all;
    assign funct_all = {Funct7, Funct3};

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
                        `INSTR_ITYPE_OP: state <= ST_EX_ALU;

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
        PCWrite  = 1'b0;
        InsMemRW = 1'b0;
        IRWrite  = 1'b0;
        RFWrite  = 1'b0;
        AWrite   = 1'b0;
        BWrite   = 1'b0;
        ALUOutWrite = 1'b0;
        MDRWrite = 1'b0;
        DMCtrl   = `DMCtrl_RD;
        ExtSel   = `ExtSel_SIGNED;
        ALUSrcA  = `ALUSrcA_A;
        ALUSrcB  = `ALUSrcB_B;
        RegSel   = `RegSel_rd;
        NPCOp    = `NPC_PC;
        WDSel    = `WDSel_FromALU;
        ALUOp    = `ALUOp_ADD;

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

                // EX(ALU): R-type / I-type 运算，结果进ALUOut
                ST_EX_ALU: begin
                    ALUSrcA = `ALUSrcA_A;
                    RegSel  = `RegSel_rd;
                    WDSel   = `WDSel_FromALU;
                    ALUOutWrite = 1'b1;

                    if (opcode == `INSTR_RTYPE_OP) begin
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
                    else begin
                        ALUSrcB = `ALUSrcB_Imm;
                        case (Funct3)
                            `INSTR_ADDI_FUNCT: begin
                                ExtSel = `ExtSel_SIGNED;
                                ALUOp  = `ALUOp_ADD;
                            end
                            `INSTR_ORI_FUNCT : begin
                                ExtSel = `ExtSel_ZERO;
                                ALUOp  = `ALUOp_OR;
                            end
                            default: begin
                                ExtSel = `ExtSel_SIGNED;
                                ALUOp  = `ALUOp_ADD;
                            end
                        endcase
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
                    ExtSel  = `ExtSel_SIGNED;
                    ALUSrcA = `ALUSrcA_A;
                    ALUSrcB = `ALUSrcB_Imm;
                    ALUOp   = `ALUOp_ADD;
                    ALUOutWrite = 1'b1;
                end

                // MEM读: 数据存入MDR
                ST_MEM_RD: begin
                    DMCtrl   = `DMCtrl_RD;
                    MDRWrite = 1'b1;
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

                // 分支比较并更新PC
                ST_EX_BR: begin
                    ALUSrcA = `ALUSrcA_A;
                    ALUSrcB = `ALUSrcB_B;
                    ALUOp   = `ALUOp_BR;
                    PCWrite = 1'b0;
                    case (Funct3)
                        `INSTR_BEQ_FUNCT: begin
                            if (zero) begin
                                PCWrite = 1'b1;
                                NPCOp   = `NPC_Offset12;
                            end
                        end

                        `INSTR_BNE_FUNCT: begin
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

                // JALR: PC跳转并写回PC+4（PC目标由NPC模块的rs输入提供）
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
