`timescale 1ns/1ps

`include "ctrl_signal_def.v"
`include "instruction_def.v"

module riscv(clk, rst);
    input clk, rst;

    wire RFWrite, DMCtrl, PCWrite, IRWrite, InsMemRW, ExtSel, zero, ALUSrcA;
    wire AWrite, BWrite, ALUOutWrite, MDRWrite;
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
    wire [11:0] ImmI12;
    wire [11:0] ImmS12;
    wire [31:0] Imm32;
    wire [20:1] Offset20;
    wire [11:0] Offset;
    wire [4:0] WR;
    wire [31:0] WD;
    wire [31:0] RD1, RD1_r, RD2, RD2_r;
    wire [31:0] A, B, ALU_result, ALU_result_r;
    wire [31:0] MDR_r;
    wire [31:0] JALR_Target;

    assign opcode = out_ins[6:0];
    assign Funct3 = out_ins[14:12]; // R-type, I-type, S-type, B-type
    assign Funct7 = out_ins[31:25]; // R-type
    assign rs1 = out_ins[19:15];    // R-type, I-type, S-type, B-type
    assign rs2 = out_ins[24:20];    // R-type, S-type, B-type
    assign rd = out_ins[11:7];      // R-type, I-type, J-type
    assign ImmI12 = out_ins[31:20];  // I-type
    assign ImmS12 = {out_ins[31:25], out_ins[11:7]}; // S-type
    assign Imm12 = (opcode == `INSTR_SW_OP) ? ImmS12 : ImmI12;
    assign Offset20 = {out_ins[31], out_ins[19:12], out_ins[20], out_ins[30:21]}; // J-type
    assign Offset = {out_ins[31], out_ins[7], out_ins[30:25], out_ins[11:8]}; // B-type imm[12:1]
    assign JALR_Target = (RD1_r + Imm32) & 32'hFFFF_FFFE;

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
        .MDRWrite(MDRWrite)
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
        .rs(JALR_Target),
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
        .Y(MDR_r),
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
    DM U_ADM(
        .Addr(ALU_result_r[11:2]),
        .WD(RD2_r),
        .DMCtrl(DMCtrl),
        .clk(clk),
        .RD(RD)
    );

    Flopr U_MDR(
        .clk(clk),
        .rst(rst),
        .en(MDRWrite),
        .in_data(RD),
        .out_data(MDR_r)
    );

    assign DR_out = RD;
endmodule