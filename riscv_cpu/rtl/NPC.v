`include "ctrl_signal_def.v"
`include "instruction_def.v"
module NPC(NPCOp, Offset12, Offset20, PC, rs, PCA4, NPC);
    input [1:0] NPCOp;
    input [12:1] Offset12;
    input [20:1] Offset20;
    input [31:0] PC;
    input [31:0] rs;
    output reg [31:0] PCA4;
    output reg [31:0] NPC;

    wire signed [12:0] Offset13;
    wire signed [20:0] Offset21;
    wire [11:0] JALRImm12;
    wire signed [31:0] JALRImm32;

    assign Offset13 = $signed({Offset12, 1'b0});
    assign Offset21 = $signed({Offset20, 1'b0});
    // 顶层rs端口固定连接RD1时，在NPC内部从Offset20重建JALR的I-type立即数
    // I-type imm[11:0] = inst[31:20]
    // Offset20       = {inst[31], inst[19:12], inst[20], inst[30:21]}
    assign JALRImm12 = {Offset20[20], Offset20[10:5], Offset20[4:1], Offset20[11]};
    assign JALRImm32 = {{20{JALRImm12[11]}}, JALRImm12};

    always @(*) begin
        case (NPCOp)
            `NPC_PC: NPC = PC + 4;
            `NPC_Offset12: NPC = $signed({1'b0, PC}) + $signed(Offset13);
            `NPC_rs: NPC = (rs + JALRImm32) & 32'hFFFF_FFFE;
            `NPC_Offset20: NPC = $signed({1'b0, PC}) + $signed(Offset21);
        endcase
        PCA4 = PC + 4;
    end
endmodule