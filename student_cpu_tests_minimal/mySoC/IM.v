`timescale 1ns/1ps

`include "ctrl_signal_def.v"

`ifndef STRINGIFY
`define STRINGIFY(x) `"x`"
`endif

module IM(InsMemRW, addr, Ins);
    input InsMemRW;
    input [11:2] addr;
    output [31:0] Ins;
    reg [31:0] memory [0:1023];
    integer i;
    integer mem_file;

    initial begin
        for (i = 0; i < 1024; i = i + 1) memory[i] = 32'b0;

`ifdef PATH
        mem_file = $fopen(`STRINGIFY(`PATH), "r");
        if (mem_file == 0) begin
            $display("[ERROR] IM open file %s failed", `STRINGIFY(`PATH));
            $fatal;
        end
        $display("[INFO] IM initialized with %s", `STRINGIFY(`PATH));
        $fread(memory, mem_file);
        $fclose(mem_file);
        for (i = 0; i < 1024; i = i + 1)
            memory[i] = {memory[i][7:0], memory[i][15:8], memory[i][23:16], memory[i][31:24]};
`endif
    end

    assign Ins = InsMemRW ? memory[addr] : 32'b0;
endmodule
