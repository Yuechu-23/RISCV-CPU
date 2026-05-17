`include "ctrl_signal_def.v"

`ifndef STRINGIFY
`define STRINGIFY(x) `"x`"
`endif

module DM(
    input  [11:2] Addr,
    input  [31:0] WD,
    input  clk,
    input  DMCtrl,
    output [31:0] RD
);

    reg [31:0] memory[0:1023];
    reg [31:0] mem_rd[0:1023];
    reg [31:0] rd_reg;
    integer i;
    integer mem_file;

    initial begin
        rd_reg = 32'b0;
        for (i = 0; i < 1024; i = i + 1) begin
            memory[i] = 32'b0;
            mem_rd[i] = 32'b0;
        end

`ifdef PATH
        mem_file = $fopen(`STRINGIFY(`PATH), "r");
        if (mem_file == 0) begin
            $display("[ERROR] DM open file %s failed", `STRINGIFY(`PATH));
            $fatal;
        end
        $display("[INFO] DM initialized with %s", `STRINGIFY(`PATH));
        $fread(mem_rd, mem_file);
        $fclose(mem_file);
        for (i = 0; i < 1024; i = i + 1) begin
            memory[i] = {mem_rd[i][7:0], mem_rd[i][15:8], mem_rd[i][23:16], mem_rd[i][31:24]};
        end
`endif
    end

    // 同步写 + 读数据打拍（替代顶层MDR）
    always @(posedge clk) begin
        if (DMCtrl == `DMCtrl_WR) begin
            memory[Addr] <= WD;
        end

        if (DMCtrl == `DMCtrl_RD) begin
            rd_reg <= memory[Addr];
        end
    end

    assign RD = rd_reg;

endmodule
