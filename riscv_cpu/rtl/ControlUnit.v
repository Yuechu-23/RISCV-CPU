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
    output reg PCWrite,
    output reg InsMemRW,
    output reg IRWrite,
    output reg RFWrite,
    output reg DMCtrl,
    output reg ExtSel,
    output reg ALUSrcA,
    output reg [1:0] ALUSrcB,
    output reg [1:0] RegSel,
    output reg [1:0] NPCOp,
    output reg [1:0] WDSel,
    output reg [3:0] ALUOp
);

    wire [9:0] funct_all;
    assign funct_all = {Funct7, Funct3};

    always @(*) begin
        // 默认值
        PCWrite  = 1'b1;
        InsMemRW = 1'b1;
        IRWrite  = 1'b1;
        RFWrite  = 1'b0;
        DMCtrl   = `DMCtrl_RD;
        ExtSel   = `ExtSel_SIGNED;
        ALUSrcA  = `ALUSrcA_A;
        ALUSrcB  = `ALUSrcB_B;
        RegSel   = `RegSel_rd;
        NPCOp    = `NPC_PC;
        WDSel    = `WDSel_FromALU;
        ALUOp    = `ALUOp_ADD;

        if (rst) begin
            PCWrite  = 1'b0;
            InsMemRW = 1'b0;
            IRWrite  = 1'b0;
            RFWrite  = 1'b0;
            DMCtrl   = `DMCtrl_RD;
            ExtSel   = `ExtSel_SIGNED;
            ALUSrcA  = `ALUSrcA_A;
            ALUSrcB  = `ALUSrcB_B;
            RegSel   = `RegSel_rd;
            NPCOp    = `NPC_PC;
            WDSel    = `WDSel_FromALU;
            ALUOp    = `ALUOp_ADD;
        end
        else begin
            case (opcode)

                // R-type
                `INSTR_RTYPE_OP: begin
                    RFWrite = 1'b1;
                    DMCtrl  = `DMCtrl_RD;
                    ALUSrcA = `ALUSrcA_A;
                    ALUSrcB = `ALUSrcB_B;
                    RegSel  = `RegSel_rd;
                    WDSel   = `WDSel_FromALU;
                    NPCOp   = `NPC_PC;

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

                // I-type
                // 目前按 instruction_def.v
                // 只支持 addi / ori
                `INSTR_ITYPE_OP: begin
                    RFWrite = 1'b1;
                    DMCtrl  = `DMCtrl_RD;
                    ExtSel  = `ExtSel_SIGNED;
                    ALUSrcA = `ALUSrcA_A;
                    ALUSrcB = `ALUSrcB_Imm;
                    RegSel  = `RegSel_rd;
                    WDSel   = `WDSel_FromALU;
                    NPCOp   = `NPC_PC;

                    case (Funct3)
                        `INSTR_ADDI_FUNCT: ALUOp = `ALUOp_ADD;
                        `INSTR_ORI_FUNCT : begin
                            ALUOp  = `ALUOp_OR;
                            ExtSel = `ExtSel_ZERO;
                        end
                        default: ALUOp = `ALUOp_ADD;
                    endcase
                end

                // LW
                `INSTR_LW_OP: begin
                    RFWrite = 1'b1;
                    DMCtrl  = `DMCtrl_RD;
                    ExtSel  = `ExtSel_SIGNED;
                    ALUSrcA = `ALUSrcA_A;
                    ALUSrcB = `ALUSrcB_Imm;
                    RegSel  = `RegSel_rd;
                    WDSel   = `WDSel_FromMEM;
                    NPCOp   = `NPC_PC;
                    ALUOp   = `ALUOp_ADD;
                end

                // SW
                `INSTR_SW_OP: begin
                    RFWrite = 1'b0;
                    DMCtrl  = `DMCtrl_WR;
                    ExtSel  = `ExtSel_SIGNED;
                    ALUSrcA = `ALUSrcA_A;
                    ALUSrcB = `ALUSrcB_Imm;
                    NPCOp   = `NPC_PC;
                    ALUOp   = `ALUOp_ADD;
                end

                // Branch : beq / bne
                `INSTR_BTYPE_OP: begin
                    RFWrite = 1'b0;
                    DMCtrl  = `DMCtrl_RD;
                    ExtSel  = `ExtSel_SIGNED;
                    ALUSrcA = `ALUSrcA_A;
                    ALUSrcB = `ALUSrcB_B;
                    ALUOp   = `ALUOp_BR;

                    case (Funct3)
                        `INSTR_BEQ_FUNCT: begin
                            if (zero)
                                NPCOp = `NPC_Offset12;
                            else
                                NPCOp = `NPC_PC;
                        end

                        `INSTR_BNE_FUNCT: begin
                            if (!zero)
                                NPCOp = `NPC_Offset12;
                            else
                                NPCOp = `NPC_PC;
                        end

                        default: begin
                            NPCOp = `NPC_PC;
                        end
                    endcase
                end

                // JAL
                `INSTR_JAL_OP: begin
                    RFWrite = 1'b1;
                    DMCtrl  = `DMCtrl_RD;
                    RegSel  = `RegSel_rd;
                    WDSel   = `WDSel_FromPC;
                    NPCOp   = `NPC_Offset20;
                end

                // JALR
                `INSTR_JALR_OP: begin
                    RFWrite = 1'b1;
                    DMCtrl  = `DMCtrl_RD;
                    ExtSel  = `ExtSel_SIGNED;
                    ALUSrcA = `ALUSrcA_A;
                    ALUSrcB = `ALUSrcB_Imm;
                    RegSel  = `RegSel_rd;
                    WDSel   = `WDSel_FromPC;
                    NPCOp   = `NPC_rs;
                    ALUOp   = `ALUOp_ADD;
                end

                default: begin
                    PCWrite  = 1'b1;
                    InsMemRW = 1'b1;
                    IRWrite  = 1'b1;
                    RFWrite  = 1'b0;
                    DMCtrl   = `DMCtrl_RD;
                    ExtSel   = `ExtSel_SIGNED;
                    ALUSrcA  = `ALUSrcA_A;
                    ALUSrcB  = `ALUSrcB_B;
                    RegSel   = `RegSel_rd;
                    NPCOp    = `NPC_PC;
                    WDSel    = `WDSel_FromALU;
                    ALUOp    = `ALUOp_ADD;
                end
            endcase
        end
    end

endmodule
