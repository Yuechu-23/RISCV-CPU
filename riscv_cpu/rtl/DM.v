`include "ctrl_signal_def.v"

module DM(
    input  [11:2] Addr,
    input  [31:0] WD,
    input  clk,
    input  DMCtrl,
    output [31:0] RD
);

    reg [31:0] memory[0:1023];

    // 同步写
    always @(posedge clk) begin
        if (DMCtrl == `DMCtrl_WR) begin
            memory[Addr] <= WD;
        end
    end

    // 异步读
    assign RD = (DMCtrl == `DMCtrl_RD) ? memory[Addr] : 32'b0;

endmodule
