`include "ctrl_signal_def.v"
`include "instruction_def.v"
module NPC(NPCOp, ImmI, ImmB, ImmJ, PC, rs, PCA4, NPC);
    input [1:0] NPCOp;
    input [31:0] ImmI;
    input [31:0] ImmB;
    input [31:0] ImmJ;
    input [31:0] PC;
    input [31:0] rs;
    output reg [31:0] PCA4;
    output reg [31:0] NPC;

    always @(*) begin
        case (NPCOp)
            `NPC_PC:       NPC = PC + 4;
            `NPC_Offset12: NPC = $signed({1'b0, PC}) + $signed(ImmB);
            `NPC_rs:       NPC = (rs + ImmI) & 32'hFFFF_FFFE;
            `NPC_Offset20: NPC = $signed({1'b0, PC}) + $signed(ImmJ);
            default:       NPC = PC + 4;
        endcase
        PCA4 = PC + 4;
    end
endmodule
