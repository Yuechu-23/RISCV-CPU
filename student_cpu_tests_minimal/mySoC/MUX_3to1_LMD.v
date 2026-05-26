`timescale 1ns/1ps

`include "ctrl_signal_def.v"

module MUX_3to1_LMD(X, Y, Z, W, control, out);
    input [31:0] X;
    input [31:0] Y;
    input [31:0] Z;
    input [31:0] W;
    input [1:0] control;
    output reg [31:0] out;

    always @(X or Y or Z or W or control) begin
        case (control)
            `WDSel_FromALU: out = X;
            `WDSel_FromMEM: out = Y;
            `WDSel_FromPC: out = Z;
            `WDSel_Else: out = W;
        endcase
    end
endmodule
