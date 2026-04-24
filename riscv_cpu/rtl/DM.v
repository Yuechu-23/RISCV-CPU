`include "ctrl_signal_def.v"

module DM(
    input  [11:2] Addr,
    input  [31:0] WD,
    input  clk,
    input  DMCtrl,
    output [31:0] RD
);

    reg [31:0] memory[0:1023];
    reg [31:0] rd_reg;

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
