`timescale 1ns/1ps

module ImmGen(
    input [31:0] inst,
    output [31:0] ImmI,       // I-type sign-extended: {{20{inst[31]}}, inst[31:20]}
    output [31:0] ImmIZero,   // I-type zero-extended:  {20'b0, inst[31:20]}
    output [31:0] ImmS,       // S-type sign-extended: {{20{inst[31]}}, inst[31:25], inst[11:7]}
    output [31:0] ImmB,       // B-type sign-extended: {{19{inst[31]}}, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0}
    output [31:0] ImmU,       // U-type:              {inst[31:12], 12'b0}
    output [31:0] ImmJ        // J-type sign-extended: {{11{inst[31]}}, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0}
);

    assign ImmI     = {{20{inst[31]}}, inst[31:20]};
    assign ImmIZero = {20'b0, inst[31:20]};
    assign ImmS     = {{20{inst[31]}}, inst[31:25], inst[11:7]};
    assign ImmB     = {{19{inst[31]}}, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0};
    assign ImmU     = {inst[31:12], 12'b0};
    assign ImmJ     = {{11{inst[31]}}, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0};

endmodule
