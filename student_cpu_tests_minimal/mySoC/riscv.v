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

    // ControlUnit outputs (FSM enable signals + state-gated memory control)
    wire RFWrite, PCWrite, IRWrite, InsMemRW, AWrite, BWrite, ALUOutWrite, DMCtrl;
    wire [1:0] NPCOp;
    wire [3:0] state_dbg;

    // Decode outputs — instruction semantics (wired directly to datapath)
    wire ExtSel, ALUSrcA;
    wire [1:0] ALUSrcB, WDSel, RegSel;
    wire [3:0] ALUOp;

    // Decode outputs — to ControlUnit for FSM decisions
    wire is_rtype, is_itype, is_lw, is_sw, is_btype, is_jal, is_jalr;
    wire is_lui, is_auipc, illegal_inst, RFWE, MemRead, MemWrite;
    wire [1:0] dec_NPCOp;

    // ALU status flags
    wire zero, less, lessu;

    // Instruction fields
    wire [6:0] opcode;
    wire [2:0] Funct3;
    wire [6:0] Funct7;
    wire [31:0] PC, NPC, PCA4;
    wire [31:0] in_ins, out_ins, RD, DR_out;
    wire [4:0] rs1, rs2, rd;
    wire [31:0] ImmI, ImmIZero, ImmS, ImmB, ImmU, ImmJ;
    wire [31:0] Imm32, ImmAddr, UTypeWD;
    wire [4:0] WR;
    wire [31:0] WD;
    wire [31:0] RD1, RD1_r, RD2, RD2_r;
    wire [31:0] A, B, ALU_result, ALU_result_r;

    localparam [3:0] ST_ID       = 4'd1;
    localparam [3:0] ST_EX_BR    = 4'd4;
    localparam [3:0] ST_EX_JAL   = 4'd5;
    localparam [3:0] ST_EX_JALR  = 4'd6;
    localparam [3:0] ST_MEM_WB   = 4'd8;
    localparam [3:0] ST_MEM_WR   = 4'd9;
    localparam [3:0] ST_WB_ALU   = 4'd10;

    wire commit_now;

    Decode U_Decode(
        .opcode(opcode),
        .Funct3(Funct3),
        .Funct7(Funct7),

        .is_rtype(is_rtype),
        .is_itype(is_itype),
        .is_lw(is_lw),
        .is_sw(is_sw),
        .is_btype(is_btype),
        .is_jal(is_jal),
        .is_jalr(is_jalr),
        .is_lui(is_lui),
        .is_auipc(is_auipc),
        .illegal_inst(illegal_inst),

        .ALUOp(ALUOp),
        .ALUSrcA(ALUSrcA),
        .ALUSrcB(ALUSrcB),

        .ExtSel(ExtSel),

        .MemRead(MemRead),
        .MemWrite(MemWrite),

        .RFWE(RFWE),
        .WDSel(WDSel),
        .RegSel(RegSel),

        .is_branch(),
        .is_jump(),
        .NPCOp(dec_NPCOp)
    );

    assign commit_now =
        (state_dbg == ST_WB_ALU)  ||
        (state_dbg == ST_MEM_WB)  ||
        (state_dbg == ST_MEM_WR)  ||
        (state_dbg == ST_EX_BR)   ||
        (state_dbg == ST_EX_JAL)  ||
        (state_dbg == ST_EX_JALR) ||
        ((state_dbg == ST_ID) && illegal_inst);

    assign opcode = out_ins[6:0];
    assign Funct3 = out_ins[14:12];
    assign Funct7 = out_ins[31:25];
    assign rs1 = out_ins[19:15];
    assign rs2 = out_ins[24:20];
    assign rd = out_ins[11:7];
    ImmGen U_ImmGen(
        .inst(out_ins),
        .ImmI(ImmI),
        .ImmIZero(ImmIZero),
        .ImmS(ImmS),
        .ImmB(ImmB),
        .ImmU(ImmU),
        .ImmJ(ImmJ)
    );

    assign Imm32   = ExtSel ? ImmI : ImmIZero;
    assign ImmAddr = (opcode == `INSTR_SW_OP) ? ImmS : ImmI;
    assign UTypeWD = (opcode == `INSTR_AUIPC_OP) ? (PC + ImmU) : ImmU;

    ControlUnit U_ControlUnit(
        .clk(clk),
        .rst(rst),
        .zero(zero),
        .less(less),
        .lessu(lessu),

        .is_rtype(is_rtype),
        .is_itype(is_itype),
        .is_lw(is_lw),
        .is_sw(is_sw),
        .is_btype(is_btype),
        .is_jal(is_jal),
        .is_jalr(is_jalr),
        .is_lui(is_lui),
        .is_auipc(is_auipc),
        .illegal_inst(illegal_inst),

        .MemRead(MemRead),
        .MemWrite(MemWrite),

        .RFWE(RFWE),
        .dec_NPCOp(dec_NPCOp),
        .Funct3(Funct3),

        .PCWrite(PCWrite),
        .InsMemRW(InsMemRW),
        .IRWrite(IRWrite),
        .RFWrite(RFWrite),
        .AWrite(AWrite),
        .BWrite(BWrite),
        .ALUOutWrite(ALUOutWrite),
        .DMCtrl(DMCtrl),

        .NPCOp(NPCOp),
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
        .ImmI(ImmI),
        .ImmB(ImmB),
        .ImmJ(ImmJ),
        .rs(RD1),
        .PCA4(PCA4),
        .NPC(NPC)
    );
    IM U_IM(
        .addr(PC[14:2]),
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
        .W(UTypeWD),
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
    MUX_2to1_A U_MUX_2to1_A(
        .X(RD1_r),
        .Y(32'h0),
        .control(ALUSrcA),
        .out(A)
    );
    MUX_3to1_B U_MUX_3to1_B(
        .X(RD2_r),
        .Y(Imm32),
        .Z(ImmAddr),
        .control(ALUSrcB),
        .out(B)
    );
    ALU U_ALU(
        .A(A),
        .B(B),
        .ALUOp(ALUOp),
        .ALU_result(ALU_result),
        .zero(zero),
        .less(less),
        .lessu(lessu)
    );
    Flopr U_ALU_result(
        .clk(clk),
        .rst(rst),
        .en(ALUOutWrite),
        .in_data(ALU_result),
        .out_data(ALU_result_r)
    );
    DM U_DM(
        .Addr(ALU_result_r),
        .WD(RD2_r),
        .Funct3(Funct3),
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
            debug_wb_pc        <= PC;
            debug_wb_ena       <= commit_now ? RFWrite : 1'b0;
            debug_wb_reg       <= commit_now ? WR : 5'b0;
            debug_wb_value     <= commit_now ? WD : 32'b0;
        end
    end
endmodule
