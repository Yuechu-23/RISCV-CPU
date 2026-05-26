`timescale 1ns/1ps

`include "ctrl_signal_def.v"
`include "instruction_def.v"

module Decode(
    input [6:0] opcode,
    input [2:0] Funct3,
    input [6:0] Funct7,

    // === Instruction classification ===
    output is_rtype,
    output is_itype,
    output is_lw,
    output is_sw,
    output is_btype,
    output is_jal,
    output is_jalr,
    output is_lui,
    output is_auipc,
    output illegal_inst,

    // === ALU control ===
    output reg [3:0] ALUOp,
    output reg ALUSrcA,
    output reg [1:0] ALUSrcB,

    // === Immediate selection ===
    output reg ExtSel,

    // === Memory access ===
    output reg MemRead,
    output reg MemWrite,

    // === Write-back control ===
    output reg RFWE,
    output reg [1:0] WDSel,
    output reg [1:0] RegSel,

    // === Control flow ===
    output reg is_branch,
    output reg is_jump,
    output reg [1:0] NPCOp
);

    wire [9:0] funct_all;
    assign funct_all = {Funct7, Funct3};

    // === Instruction classification ===
    assign is_rtype  = (opcode == `INSTR_RTYPE_OP);
    assign is_itype  = (opcode == `INSTR_ITYPE_OP);
    assign is_lw     = (opcode == `INSTR_LW_OP);
    assign is_sw     = (opcode == `INSTR_SW_OP);
    assign is_btype  = (opcode == `INSTR_BTYPE_OP);
    assign is_jal    = (opcode == `INSTR_JAL_OP);
    assign is_jalr   = (opcode == `INSTR_JALR_OP);
    assign is_lui    = (opcode == `INSTR_LUI_OP);
    assign is_auipc  = (opcode == `INSTR_AUIPC_OP);

    assign illegal_inst = !(
        is_rtype || is_itype || is_lw    || is_sw  ||
        is_btype || is_jal   || is_jalr  || is_lui || is_auipc
    );

    // === ALU control ===
    always @(*) begin
        // Defaults
        ALUOp   = `ALUOp_ADD;
        ALUSrcA = `ALUSrcA_A;
        ALUSrcB = `ALUSrcB_B;
        ExtSel  = `ExtSel_SIGNED;

        case (opcode)
            `INSTR_RTYPE_OP: begin
                ALUSrcA = `ALUSrcA_A;
                ALUSrcB = `ALUSrcB_B;
                case (funct_all)
                    `INSTR_ADD_FUNCT:  ALUOp = `ALUOp_ADD;
                    `INSTR_SUB_FUNCT:  ALUOp = `ALUOp_SUB;
                    `INSTR_AND_FUNCT:  ALUOp = `ALUOp_AND;
                    `INSTR_OR_FUNCT:   ALUOp = `ALUOp_OR;
                    `INSTR_XOR_FUNCT:  ALUOp = `ALUOp_XOR;
                    `INSTR_SLL_FUNCT:  ALUOp = `ALUOp_SLL;
                    `INSTR_SRL_FUNCT:  ALUOp = `ALUOp_SRL;
                    `INSTR_SRA_FUNCT:  ALUOp = `ALUOp_SRA;
                    `INSTR_SLT_FUNCT:  ALUOp = `ALUOp_SLT;
                    `INSTR_SLTU_FUNCT: ALUOp = `ALUOp_SLTU;
                    default:           ALUOp = `ALUOp_ADD;
                endcase
            end

            `INSTR_ITYPE_OP: begin
                ALUSrcA = `ALUSrcA_A;
                ALUSrcB = `ALUSrcB_Imm;
                case (Funct3)
                    `INSTR_ADDI_FUNCT: begin
                        ExtSel = `ExtSel_SIGNED;
                        ALUOp  = `ALUOp_ADD;
                    end
                    `INSTR_ANDI_FUNCT: begin
                        ExtSel = `ExtSel_SIGNED;
                        ALUOp  = `ALUOp_AND;
                    end
                    `INSTR_ORI_FUNCT: begin
                        ExtSel = `ExtSel_SIGNED;
                        ALUOp  = `ALUOp_OR;
                    end
                    `INSTR_XORI_FUNCT: begin
                        ExtSel = `ExtSel_SIGNED;
                        ALUOp  = `ALUOp_XOR;
                    end
                    `INSTR_SLTI_FUNCT: begin
                        ExtSel = `ExtSel_SIGNED;
                        ALUOp  = `ALUOp_SLT;
                    end
                    `INSTR_SLTIU_FUNCT: begin
                        ExtSel = `ExtSel_SIGNED;
                        ALUOp  = `ALUOp_SLTU;
                    end
                    `INSTR_SLLI_FUNCT: begin
                        ExtSel = `ExtSel_ZERO;
                        ALUOp  = `ALUOp_SLL;
                    end
                    `INSTR_SRLI_SRAI_FUNCT: begin
                        ExtSel = `ExtSel_ZERO;
                        if (Funct7 == 7'b0100000)
                            ALUOp = `ALUOp_SRA;
                        else
                            ALUOp = `ALUOp_SRL;
                    end
                    default: begin
                        ExtSel = `ExtSel_SIGNED;
                        ALUOp  = `ALUOp_ADD;
                    end
                endcase
            end

            `INSTR_LW_OP,
            `INSTR_SW_OP: begin
                ExtSel  = `ExtSel_SIGNED;
                ALUSrcA = `ALUSrcA_A;
                ALUSrcB = `ALUSrcB_Offset;
                ALUOp   = `ALUOp_ADD;
            end

            `INSTR_BTYPE_OP: begin
                ALUSrcA = `ALUSrcA_A;
                ALUSrcB = `ALUSrcB_B;
                case (Funct3)
                    `INSTR_BEQ_FUNCT,
                    `INSTR_BNE_FUNCT: ALUOp = `ALUOp_BR;
                    `INSTR_BLT_FUNCT,
                    `INSTR_BGE_FUNCT: ALUOp = `ALUOp_SLT;
                    `INSTR_BLTU_FUNCT,
                    `INSTR_BGEU_FUNCT: ALUOp = `ALUOp_SLTU;
                    default: ALUOp = `ALUOp_BR;
                endcase
            end

            `INSTR_JAL_OP: begin
                // JAL: ALU not used, pass-through
            end

            `INSTR_JALR_OP: begin
                ExtSel = `ExtSel_SIGNED;
            end

            `INSTR_LUI_OP,
            `INSTR_AUIPC_OP: begin
                // U-type: write-back bypasses ALU in multi-cycle
                // No ALU operation needed
            end

            default: begin
                ALUOp   = `ALUOp_ADD;
                ALUSrcA = `ALUSrcA_A;
                ALUSrcB = `ALUSrcB_B;
                ExtSel  = `ExtSel_SIGNED;
            end
        endcase
    end

    // === Memory access control ===
    always @(*) begin
        case (opcode)
            `INSTR_LW_OP: begin MemRead = 1'b1; MemWrite = 1'b0; end
            `INSTR_SW_OP: begin MemRead = 1'b0; MemWrite = 1'b1; end
            default:      begin MemRead = 1'b0; MemWrite = 1'b0; end
        endcase
    end

    // === Write-back control ===
    always @(*) begin
        // Defaults
        RFWE   = 1'b0;
        WDSel  = `WDSel_FromALU;
        RegSel = `RegSel_rd;

        case (opcode)
            `INSTR_RTYPE_OP,
            `INSTR_ITYPE_OP: begin
                RFWE  = 1'b1;
                WDSel = `WDSel_FromALU;
            end

            `INSTR_LW_OP: begin
                RFWE  = 1'b1;
                WDSel = `WDSel_FromMEM;
            end

            `INSTR_JAL_OP,
            `INSTR_JALR_OP: begin
                RFWE  = 1'b1;
                WDSel = `WDSel_FromPC;
            end

            `INSTR_LUI_OP,
            `INSTR_AUIPC_OP: begin
                RFWE  = 1'b1;
                WDSel = `WDSel_Else;
            end

            default: begin
                RFWE  = 1'b0;
                WDSel = `WDSel_FromALU;
            end
        endcase
    end

    // === Control flow ===
    always @(*) begin
        is_branch = 1'b0;
        is_jump   = 1'b0;
        NPCOp     = `NPC_PC;

        case (opcode)
            `INSTR_BTYPE_OP: begin
                is_branch = 1'b1;
                NPCOp     = `NPC_PC;   // default: not taken; FSM overrides on condition
            end

            `INSTR_JAL_OP: begin
                is_jump = 1'b1;
                NPCOp   = `NPC_Offset20;
            end

            `INSTR_JALR_OP: begin
                is_jump = 1'b1;
                NPCOp   = `NPC_rs;
            end

            default: begin
                is_branch = 1'b0;
                is_jump   = 1'b0;
                NPCOp     = `NPC_PC;
            end
        endcase
    end

endmodule
