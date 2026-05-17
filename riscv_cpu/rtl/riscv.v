`timescale 1ns/1ps

`include "ctrl_signal_def.v"
`include "instruction_def.v"

module riscv(
    clk,
    rst,
    debug_wb_have_inst,
    debug_wb_pc,
    debug_wb_ena,
    debug_wb_reg,
    debug_wb_value
);
    input clk, rst;
    output reg debug_wb_have_inst;
    output reg [31:0] debug_wb_pc;
    output reg debug_wb_ena;
    output reg [4:0] debug_wb_reg;
    output reg [31:0] debug_wb_value;

    wire RFWrite, DMCtrl, PCWrite, IRWrite, InsMemRW, ExtSel, zero, ALUSrcA;
    wire AWrite, BWrite, ALUOutWrite;
    wire [1:0] ALUSrcB;
    wire [1:0] NPCOp, WDSel, RegSel;
    wire [3:0] ALUOp;
    wire [6:0] opcode;
    wire [2:0] Funct3;
    wire [6:0] Funct7;
    wire [31:0] PC, NPC, PCA4;
    wire [31:0] in_ins, out_ins, RD, DR_out;
    wire [4:0] rs1, rs2, rd;
    wire [11:0] Imm12;
    wire [31:0] Imm32;
    wire [20:1] Offset20;
    wire [11:0] Offset;
    wire [4:0] WR;
    wire [31:0] WD;
    wire [31:0] RD1, RD1_r, RD2, RD2_r;
    wire [31:0] A, B, ALU_result, ALU_result_r;
    wire [3:0] state_dbg;

    localparam [3:0] ST_ID       = 4'd2;
    localparam [3:0] ST_EX_BR    = 4'd5;
    localparam [3:0] ST_EX_JAL   = 4'd6;
    localparam [3:0] ST_EX_JALR  = 4'd7;
    localparam [3:0] ST_MEM_WB   = 4'd9;
    localparam [3:0] ST_MEM_WR   = 4'd10;
    localparam [3:0] ST_WB_ALU   = 4'd11;

    wire supported_opcode;
    wire commit_now;

    assign supported_opcode =
        (opcode == `INSTR_RTYPE_OP) ||
        (opcode == `INSTR_ITYPE_OP) ||
        (opcode == `INSTR_LW_OP)    ||
        (opcode == `INSTR_SW_OP)    ||
        (opcode == `INSTR_BTYPE_OP) ||
        (opcode == `INSTR_JAL_OP)   ||
        (opcode == `INSTR_JALR_OP);

    assign commit_now =
        (state_dbg == ST_WB_ALU)  ||
        (state_dbg == ST_MEM_WB)  ||
        (state_dbg == ST_MEM_WR)  ||
        (state_dbg == ST_EX_BR)   ||
        (state_dbg == ST_EX_JAL)  ||
        (state_dbg == ST_EX_JALR) ||
        ((state_dbg == ST_ID) && !supported_opcode);

    assign opcode = out_ins[6:0];
    assign Funct3 = out_ins[14:12];
    assign Funct7 = out_ins[31:25];
    assign rs1 = out_ins[19:15];
    assign rs2 = out_ins[24:20];
    assign rd = out_ins[11:7];
    assign Imm12 = out_ins[31:20];
    assign Offset20 = {out_ins[31], out_ins[19:12], out_ins[20], out_ins[30:21]};
    assign Offset = (opcode == `INSTR_BTYPE_OP) ? {out_ins[31], out_ins[7], out_ins[30:25], out_ins[11:8]} : (opcode == `INSTR_SW_OP) ? {out_ins[31:25], out_ins[11:7]} : Imm12;

    ControlUnit U_ControlUnit(
        .clk(clk),
        .rst(rst),
        .zero(zero),
        .opcode(opcode),
        .Funct7(Funct7),
        .Funct3(Funct3),
        .RFWrite(RFWrite),
        .DMCtrl(DMCtrl),
        .PCWrite(PCWrite),
        .IRWrite(IRWrite),
        .InsMemRW(InsMemRW),
        .ExtSel(ExtSel),
        .ALUOp(ALUOp),
        .NPCOp(NPCOp),
        .ALUSrcA(ALUSrcA),
        .WDSel(WDSel),
        .ALUSrcB(ALUSrcB),
        .RegSel(RegSel),
        .AWrite(AWrite),
        .BWrite(BWrite),
        .ALUOutWrite(ALUOutWrite),
        .state_dbg(state_dbg)
    );
    PC U_PC(
        .clk(clk),
        .rst(rst),
        .PCWrite(PCWrite),
        .NPC(NPC),
        .PC(PC)
    );
    NPC U_NPC(
        .PC(PC),
        .NPCOp(NPCOp),
        .Offset12(Offset),
        .Offset20(Offset20),
        .Imm12(Imm12),
        .rs(RD1),
        .PCA4(PCA4),
        .NPC(NPC)
    );
    IM U_IM(
        .clk(clk),
        .addr(PC[11:2]),
        .Ins(in_ins),
        .InsMemRW(InsMemRW)
    );
    IR U_IR(
        .clk(clk),
        .IRWrite(IRWrite),
        .in_ins(in_ins),
        .out_ins(out_ins)
    );
    RF U_RF(
        .RR1(rs1),
        .RR2(rs2),
        .WR(WR),
        .WD(WD),
        .clk(clk),
        .RFWrite(RFWrite),
        .RD1(RD1),
        .RD2(RD2)
    );
    MUX_3to1 U_MUX_3to1(
        .X(rd),
        .Y(5'd0),
        .Z(5'd31),
        .control(RegSel),
        .out(WR)
    );
    MUX_3to1_LMD U_MUX_3to1_LMD(
        .X(ALU_result_r),
        .Y(DR_out),
        .Z(PCA4),
        .control(WDSel),
        .out(WD)
    );
    Flopr U_A(
        .clk(clk),
        .rst(rst),
        .en(AWrite),
        .in_data(RD1),
        .out_data(RD1_r)
    );
    Flopr U_B(
        .clk(clk),
        .rst(rst),
        .en(BWrite),
        .in_data(RD2),
        .out_data(RD2_r)
    );
    EXT U_EXT(
        .imm_in(Imm12),
        .ExtSel(ExtSel),
        .imm_out(Imm32)
    );
    MUX_2to1_A U_MUX_2to1_A(
        .X(RD1_r),
        .Y(32'h0),
        .control(ALUSrcA),
        .out(A)
    );
    MUX_3to1_B U_MUX_3to1_B(
        .X(RD2_r),
        .Y(Imm32),
        .Z(Offset),
        .control(ALUSrcB),
        .out(B)
    );
    ALU U_ALU(
        .A(A),
        .B(B),
        .ALUOp(ALUOp),
        .ALU_result(ALU_result),
        .zero(zero)
    );
    Flopr U_ALU_result(
        .clk(clk),
        .rst(rst),
        .en(ALUOutWrite),
        .in_data(ALU_result),
        .out_data(ALU_result_r)
    );
    DM U_DM(
        .Addr(ALU_result_r[11:2]),
        .WD(RD2_r),
        .DMCtrl(DMCtrl),
        .clk(clk),
        .RD(RD)
    );

    assign DR_out = RD;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            debug_wb_have_inst <= 1'b0;
            debug_wb_pc        <= 32'b0;
            debug_wb_ena       <= 1'b0;
            debug_wb_reg       <= 5'b0;
            debug_wb_value     <= 32'b0;
        end else begin
            debug_wb_have_inst <= commit_now;
            debug_wb_pc        <= PC - 32'd4;
            debug_wb_ena       <= commit_now ? RFWrite : 1'b0;
            debug_wb_reg       <= commit_now ? WR : 5'b0;
            debug_wb_value     <= commit_now ? WD : 32'b0;
        end
    end
endmodule
