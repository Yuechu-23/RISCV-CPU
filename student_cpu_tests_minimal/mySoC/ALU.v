`include "ctrl_signal_def.v"
`include "instruction_def.v"

module ALU(A, B, ALUOp, zero, less, lessu, ALU_result);
    input signed [31:0] A;
    input signed [31:0] B;
    input [3:0] ALUOp;
    output zero;
    output less;
    output lessu;
    output reg signed [31:0] ALU_result;

    always @(*) begin
        case (ALUOp)
            `ALUOp_ADD: ALU_result = A + B;
            `ALUOp_SUB: ALU_result = A - B;
            `ALUOp_AND: ALU_result = A & B;
            `ALUOp_OR:  ALU_result = A | B;
            `ALUOp_XOR: ALU_result = A ^ B;
            `ALUOp_SRA: ALU_result = A >>> B[4:0];
            `ALUOp_SLL: ALU_result = A << B[4:0];
            `ALUOp_SRL: ALU_result = $signed($unsigned(A) >> B[4:0]);
            `ALUOp_BR:  ALU_result = A - B;
            `ALUOp_SLT:  ALU_result = ($signed(A) < $signed(B)) ? 32'b1 : 32'b0;
            `ALUOp_SLTU: ALU_result = ($unsigned(A) < $unsigned(B)) ? 32'b1 : 32'b0;
            default:    ALU_result = 32'hFFFF_FFFF;
        endcase
    end

    assign zero = (ALU_result == 32'b0);
    assign less  = ($signed(A) < $signed(B));
    assign lessu = ($unsigned(A) < $unsigned(B));

endmodule

