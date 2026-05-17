`timescale 1ns/1ps

`include "ctrl_signal_def.v"

`ifndef STRINGIFY
`define STRINGIFY(x) `"x`"
`endif

module IM(clk, InsMemRW, addr, Ins);
    input clk;
    input InsMemRW;
    input [11:2] addr;
    output reg [31:0] Ins;
    reg [31:0] memory [0:1023];
    reg [31:0] mem_rd [0:1023];
    integer i;
    integer mem_file;

    initial begin
        for (i = 0; i < 1024; i = i + 1) begin
            memory[i] = 32'b0;
            mem_rd[i] = 32'b0;
        end

`ifdef PATH
        mem_file = $fopen(`STRINGIFY(`PATH), "r");
        if (mem_file == 0) begin
            $display("[ERROR] IM open file %s failed", `STRINGIFY(`PATH));
            $fatal;
        end
        $display("[INFO] IM initialized with %s", `STRINGIFY(`PATH));
        $fread(mem_rd, mem_file);
        $fclose(mem_file);
        for (i = 0; i < 1024; i = i + 1) begin
            memory[i] = {mem_rd[i][7:0], mem_rd[i][15:8], mem_rd[i][23:16], mem_rd[i][31:24]};
        end
`endif
    end

    always @(posedge clk) begin
        if (InsMemRW) begin
            Ins <= memory[addr];
        end else begin
            Ins <= 32'b0;
        end
    end
endmodule
