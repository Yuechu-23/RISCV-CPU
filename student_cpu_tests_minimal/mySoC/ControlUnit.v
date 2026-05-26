`timescale 1ns/1ps

`include "ctrl_signal_def.v"
`include "instruction_def.v"

module ControlUnit(
    input rst,
    input clk,
    input zero,
    input less,
    input lessu,

    // From Decode: instruction classification
    input is_rtype,
    input is_itype,
    input is_lw,
    input is_sw,
    input is_btype,
    input is_jal,
    input is_jalr,
    input is_lui,
    input is_auipc,
    input illegal_inst,

    // From Decode: memory access intent
    input MemRead,
    input MemWrite,

    // From Decode: write-back intent
    input RFWE,

    // From Decode: default control flow
    input [1:0] dec_NPCOp,

    // Branch resolution needs Funct3
    input [2:0] Funct3,

    // === FSM enable signals ===
    output reg PCWrite,
    output reg InsMemRW,
    output reg IRWrite,
    output reg RFWrite,
    output reg AWrite,
    output reg BWrite,
    output reg ALUOutWrite,

    // === Memory control (state-gated) ===
    output reg DMCtrl,

    // === Control flow (FSM may override for branches) ===
    output reg [1:0] NPCOp,

    // === State for debug ===
    output [3:0] state_dbg
);

    localparam [3:0] ST_IF       = 4'd0;
    localparam [3:0] ST_ID       = 4'd1;
    localparam [3:0] ST_EX_ALU   = 4'd2;
    localparam [3:0] ST_EX_ADDR  = 4'd3;
    localparam [3:0] ST_EX_BR    = 4'd4;
    localparam [3:0] ST_EX_JAL   = 4'd5;
    localparam [3:0] ST_EX_JALR  = 4'd6;
    localparam [3:0] ST_MEM_RD   = 4'd7;
    localparam [3:0] ST_MEM_WB   = 4'd8;
    localparam [3:0] ST_MEM_WR   = 4'd9;
    localparam [3:0] ST_WB_ALU   = 4'd10;

    reg [3:0] state;
    assign state_dbg = state;

    // === FSM state transitions ===
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= ST_IF;
        end
        else begin
            case (state)
                ST_IF: begin
                    state <= ST_ID;
                end

                ST_ID: begin
                    if (illegal_inst)
                        state <= ST_IF;
                    else if (is_rtype || is_itype)
                        state <= ST_EX_ALU;
                    else if (is_lw || is_sw)
                        state <= ST_EX_ADDR;
                    else if (is_btype)
                        state <= ST_EX_BR;
                    else if (is_jal)
                        state <= ST_EX_JAL;
                    else if (is_jalr)
                        state <= ST_EX_JALR;
                    else if (is_lui || is_auipc)
                        state <= ST_WB_ALU;
                    else
                        state <= ST_IF;
                end

                ST_EX_ALU: begin
                    state <= ST_WB_ALU;
                end

                ST_WB_ALU: begin
                    state <= ST_IF;
                end

                ST_EX_ADDR: begin
                    if (is_lw)
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
                    state <= ST_IF;
                end

                default: begin
                    state <= ST_IF;
                end
            endcase
        end
    end

    // === Output logic: enable signals + NPCOp override ===
    always @(*) begin
        // Safe defaults
        PCWrite     = 1'b0;
        InsMemRW    = 1'b0;
        IRWrite     = 1'b0;
        RFWrite     = 1'b0;
        AWrite      = 1'b0;
        BWrite      = 1'b0;
        ALUOutWrite = 1'b0;
        DMCtrl      = `DMCtrl_RD;
        NPCOp       = dec_NPCOp;

        if (!rst) begin
            case (state)
                ST_IF: begin
                    InsMemRW = 1'b1;
                    IRWrite  = 1'b1;
                end

                ST_ID: begin
                    AWrite = 1'b1;
                    BWrite = 1'b1;
                end

                ST_EX_ALU: begin
                    ALUOutWrite = 1'b1;
                end

                ST_WB_ALU: begin
                    PCWrite = 1'b1;
                    RFWrite = RFWE;
                end

                ST_EX_ADDR: begin
                    ALUOutWrite = 1'b1;
                end

                ST_MEM_RD: begin
                    DMCtrl = `DMCtrl_RD;
                end

                ST_MEM_WB: begin
                    PCWrite = 1'b1;
                    RFWrite = RFWE;
                end

                ST_MEM_WR: begin
                    PCWrite = 1'b1;
                    DMCtrl = MemWrite ? `DMCtrl_WR : `DMCtrl_RD;
                end

                ST_EX_BR: begin
                    PCWrite = 1'b1;
                    NPCOp   = `NPC_PC;

                    case (Funct3)
                        `INSTR_BEQ_FUNCT:  if (zero)         NPCOp = `NPC_Offset12;
                        `INSTR_BNE_FUNCT:  if (!zero)        NPCOp = `NPC_Offset12;
                        `INSTR_BLT_FUNCT:  if (less)         NPCOp = `NPC_Offset12;
                        `INSTR_BGE_FUNCT:  if (!less)        NPCOp = `NPC_Offset12;
                        `INSTR_BLTU_FUNCT: if (lessu)        NPCOp = `NPC_Offset12;
                        `INSTR_BGEU_FUNCT: if (!lessu)       NPCOp = `NPC_Offset12;
                        default:           NPCOp = `NPC_PC;
                    endcase
                end

                ST_EX_JAL: begin
                    PCWrite = 1'b1;
                    RFWrite = RFWE;
                    NPCOp   = dec_NPCOp;
                end

                ST_EX_JALR: begin
                    PCWrite = 1'b1;
                    RFWrite = RFWE;
                    NPCOp   = dec_NPCOp;
                end

                default: begin
                    InsMemRW = 1'b1;
                end
            endcase
        end
    end

endmodule
