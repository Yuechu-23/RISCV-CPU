`include "ctrl_signal_def.v"

`ifndef STRINGIFY
`define STRINGIFY(x) `"x`"
`endif

module DM(
    input  [31:0] Addr,
    input  [31:0] WD,
    input  [2:0]  Funct3,
    input         clk,
    input         DMCtrl,
    output reg [31:0] RD
);

    reg [31:0] memory[0:8191];
    reg [31:0] mem_rd[0:8191];

    integer i;
    integer mem_file;

    wire is_dmem_addr;
    wire [12:0] word_addr;
    wire [1:0] byte_offset;

    reg [31:0] word_data;

    assign is_dmem_addr = (Addr[31:16] == 16'h0000);
    assign word_addr    = Addr[14:2];
    assign byte_offset  = Addr[1:0];

    initial begin
        RD = 32'b0;

        for (i = 0; i < 8192; i = i + 1) begin
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

        for (i = 0; i < 8192; i = i + 1) begin
            memory[i] = {
                mem_rd[i][7:0],
                mem_rd[i][15:8],
                mem_rd[i][23:16],
                mem_rd[i][31:24]
            };
        end
`endif
    end

    always @(*) begin
        if (!is_dmem_addr) begin
            RD = 32'b0;
        end else begin
            word_data = memory[word_addr];

            case (Funct3)
                3'b000: begin
                    case (byte_offset)
                        2'b00: RD = {{24{word_data[7]}},  word_data[7:0]};
                        2'b01: RD = {{24{word_data[15]}}, word_data[15:8]};
                        2'b10: RD = {{24{word_data[23]}}, word_data[23:16]};
                        2'b11: RD = {{24{word_data[31]}}, word_data[31:24]};
                    endcase
                end

                3'b001: begin
                    if (byte_offset[1] == 1'b0)
                        RD = {{16{word_data[15]}}, word_data[15:0]};
                    else
                        RD = {{16{word_data[31]}}, word_data[31:16]};
                end

                3'b010: RD = word_data;

                3'b100: begin
                    case (byte_offset)
                        2'b00: RD = {24'b0, word_data[7:0]};
                        2'b01: RD = {24'b0, word_data[15:8]};
                        2'b10: RD = {24'b0, word_data[23:16]};
                        2'b11: RD = {24'b0, word_data[31:24]};
                    endcase
                end

                3'b101: begin
                    if (byte_offset[1] == 1'b0)
                        RD = {16'b0, word_data[15:0]};
                    else
                        RD = {16'b0, word_data[31:16]};
                end

                default: RD = word_data;
            endcase
        end
    end

    always @(posedge clk) begin
        if ((DMCtrl == `DMCtrl_WR) && is_dmem_addr) begin
            case (Funct3)
                3'b000: begin // sb
                    case (byte_offset)
                        2'b00: memory[word_addr][7:0]   <= WD[7:0];
                        2'b01: memory[word_addr][15:8]  <= WD[7:0];
                        2'b10: memory[word_addr][23:16] <= WD[7:0];
                        2'b11: memory[word_addr][31:24] <= WD[7:0];
                    endcase
                end

                3'b001: begin // sh
                    if (byte_offset[1] == 1'b0)
                        memory[word_addr][15:0] <= WD[15:0];
                    else
                        memory[word_addr][31:16] <= WD[15:0];
                end

                3'b010: begin // sw
                    memory[word_addr] <= WD;
                end
            endcase
        end
    end

endmodule
