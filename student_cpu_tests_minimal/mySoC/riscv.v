`timescale 1ns/1ps

`include "ctrl_signal_def.v"
`include "instruction_def.v"

module riscv(
    clk,
    rst,
    debug_wb_have_inst,
    debug_wb_pc,
    debug_wb_ena,
    debug_wb_reg,
    debug_wb_value
);
    input clk, rst;
    output reg debug_wb_have_inst;
    output reg [31:0] debug_wb_pc;
    output reg debug_wb_ena;
    output reg [4:0] debug_wb_reg;
    output reg [31:0] debug_wb_value;

    wire [31:0] PC, pc_next, pc_plus4, in_ins;
    wire pc_write;

    reg if_id_valid;
    reg [31:0] if_id_pc;
    reg [31:0] if_id_inst;

    wire [6:0] id_opcode;
    wire [2:0] id_funct3;
    wire [6:0] id_funct7;
    wire [4:0] id_rs1;
    wire [4:0] id_rs2;
    wire [4:0] id_rd;
    wire [31:0] id_imm_i;
    wire [31:0] id_imm_i_zero;
    wire [31:0] id_imm_s;
    wire [31:0] id_imm_b;
    wire [31:0] id_imm_u;
    wire [31:0] id_imm_j;
    wire [31:0] id_imm32;
    wire [31:0] id_imm_addr;
    wire [31:0] id_rd1_raw;
    wire [31:0] id_rd2_raw;
    wire [31:0] id_rd1;
    wire [31:0] id_rd2;

    wire id_is_rtype;
    wire id_is_itype;
    wire id_is_lw;
    wire id_is_sw;
    wire id_is_btype;
    wire id_is_jal;
    wire id_is_jalr;
    wire id_is_lui;
    wire id_is_auipc;
    wire id_illegal_inst;
    wire id_ext_sel;
    wire id_alu_src_a;
    wire [1:0] id_alu_src_b;
    wire [3:0] id_alu_op;
    wire id_mem_read;
    wire id_mem_write;
    wire id_rf_we;
    wire [1:0] id_wd_sel;
    wire [1:0] id_reg_sel;
    wire id_is_branch;
    wire id_is_jump;
    wire [1:0] id_npc_op;
    wire id_uses_rs1;
    wire id_uses_rs2;

    reg id_ex_valid;
    reg [31:0] id_ex_pc;
    reg [31:0] id_ex_pc4;
    reg [31:0] id_ex_rs1_data;
    reg [31:0] id_ex_rs2_data;
    reg [31:0] id_ex_imm_i;
    reg [31:0] id_ex_imm32;
    reg [31:0] id_ex_imm_addr;
    reg [31:0] id_ex_imm_b;
    reg [31:0] id_ex_imm_u;
    reg [31:0] id_ex_imm_j;
    reg [4:0] id_ex_rs1;
    reg [4:0] id_ex_rs2;
    reg [4:0] id_ex_rd;
    reg [2:0] id_ex_funct3;
    reg id_ex_alu_src_a;
    reg [1:0] id_ex_alu_src_b;
    reg [3:0] id_ex_alu_op;
    reg id_ex_mem_read;
    reg id_ex_mem_write;
    reg id_ex_rf_we;
    reg [1:0] id_ex_wd_sel;
    reg id_ex_is_btype;
    reg id_ex_is_jal;
    reg id_ex_is_jalr;
    reg id_ex_is_lui;
    reg id_ex_is_auipc;

    wire load_use_stall;
    wire redirect_taken;
    wire [31:0] redirect_pc;

    wire [31:0] ex_rs1_data;
    wire [31:0] ex_rs2_data;
    wire [31:0] ex_alu_a;
    wire [31:0] ex_alu_b;
    wire [31:0] ex_alu_result;
    wire ex_zero;
    wire ex_less;
    wire ex_lessu;
    wire ex_branch_taken;
    wire [31:0] ex_branch_target;
    wire [31:0] ex_jal_target;
    wire [31:0] ex_jalr_target;
    wire [31:0] ex_u_wdata;

    reg ex_mem_valid;
    reg [31:0] ex_mem_pc;
    reg [31:0] ex_mem_pc4;
    reg [31:0] ex_mem_alu_result;
    reg [31:0] ex_mem_store_data;
    reg [31:0] ex_mem_u_wdata;
    reg [4:0] ex_mem_rd;
    reg [2:0] ex_mem_funct3;
    reg ex_mem_mem_read;
    reg ex_mem_mem_write;
    reg ex_mem_rf_we;
    reg [1:0] ex_mem_wd_sel;

    wire [31:0] ex_mem_forward_data;
    wire [31:0] dm_rd;
    wire dm_ctrl;

    reg mem_wb_valid;
    reg [31:0] mem_wb_pc;
    reg [31:0] mem_wb_pc4;
    reg [31:0] mem_wb_alu_result;
    reg [31:0] mem_wb_mem_data;
    reg [31:0] mem_wb_u_wdata;
    reg [4:0] mem_wb_rd;
    reg mem_wb_rf_we;
    reg [1:0] mem_wb_wd_sel;

    wire [31:0] wb_wdata;
    wire wb_rf_write;

    assign pc_plus4 = PC + 32'd4;
    assign pc_next = redirect_taken ? redirect_pc : pc_plus4;
    assign pc_write = redirect_taken || !load_use_stall;

    PC U_PC(
        .clk(clk),
        .rst(rst),
        .PCWrite(pc_write),
        .NPC(pc_next),
        .PC(PC)
    );

    IM U_IM(
        .addr(PC[14:2]),
        .Ins(in_ins),
        .InsMemRW(1'b1)
    );

    assign id_opcode = if_id_inst[6:0];
    assign id_funct3 = if_id_inst[14:12];
    assign id_funct7 = if_id_inst[31:25];
    assign id_rs1 = if_id_inst[19:15];
    assign id_rs2 = if_id_inst[24:20];
    assign id_rd = if_id_inst[11:7];

    Decode U_Decode(
        .opcode(id_opcode),
        .Funct3(id_funct3),
        .Funct7(id_funct7),
        .is_rtype(id_is_rtype),
        .is_itype(id_is_itype),
        .is_lw(id_is_lw),
        .is_sw(id_is_sw),
        .is_btype(id_is_btype),
        .is_jal(id_is_jal),
        .is_jalr(id_is_jalr),
        .is_lui(id_is_lui),
        .is_auipc(id_is_auipc),
        .illegal_inst(id_illegal_inst),
        .ALUOp(id_alu_op),
        .ALUSrcA(id_alu_src_a),
        .ALUSrcB(id_alu_src_b),
        .ExtSel(id_ext_sel),
        .MemRead(id_mem_read),
        .MemWrite(id_mem_write),
        .RFWE(id_rf_we),
        .WDSel(id_wd_sel),
        .RegSel(id_reg_sel),
        .is_branch(id_is_branch),
        .is_jump(id_is_jump),
        .NPCOp(id_npc_op)
    );

    ImmGen U_ImmGen(
        .inst(if_id_inst),
        .ImmI(id_imm_i),
        .ImmIZero(id_imm_i_zero),
        .ImmS(id_imm_s),
        .ImmB(id_imm_b),
        .ImmU(id_imm_u),
        .ImmJ(id_imm_j)
    );

    assign id_imm32 = id_ext_sel ? id_imm_i : id_imm_i_zero;
    assign id_imm_addr = id_is_sw ? id_imm_s : id_imm_i;

    assign wb_wdata =
        (mem_wb_wd_sel == `WDSel_FromMEM) ? mem_wb_mem_data :
        (mem_wb_wd_sel == `WDSel_FromPC)  ? mem_wb_pc4 :
        (mem_wb_wd_sel == `WDSel_Else)    ? mem_wb_u_wdata :
                                            mem_wb_alu_result;
    assign wb_rf_write = mem_wb_valid && mem_wb_rf_we;

    RF U_RF(
        .RR1(id_rs1),
        .RR2(id_rs2),
        .WR(mem_wb_rd),
        .WD(wb_wdata),
        .clk(clk),
        .RFWrite(wb_rf_write),
        .RD1(id_rd1_raw),
        .RD2(id_rd2_raw)
    );

    assign id_rd1 =
        (wb_rf_write && (mem_wb_rd != 5'b0) && (mem_wb_rd == id_rs1)) ? wb_wdata :
                                                                        id_rd1_raw;
    assign id_rd2 =
        (wb_rf_write && (mem_wb_rd != 5'b0) && (mem_wb_rd == id_rs2)) ? wb_wdata :
                                                                        id_rd2_raw;

    assign id_uses_rs1 = id_is_rtype || id_is_itype || id_is_lw || id_is_sw ||
                         id_is_btype || id_is_jalr;
    assign id_uses_rs2 = id_is_rtype || id_is_sw || id_is_btype;

    assign load_use_stall =
        if_id_valid && id_ex_valid && id_ex_mem_read && (id_ex_rd != 5'b0) &&
        ((id_uses_rs1 && (id_rs1 == id_ex_rd)) ||
         (id_uses_rs2 && (id_rs2 == id_ex_rd)));

    assign ex_mem_forward_data =
        (ex_mem_wd_sel == `WDSel_FromPC) ? ex_mem_pc4 :
        (ex_mem_wd_sel == `WDSel_Else)   ? ex_mem_u_wdata :
                                           ex_mem_alu_result;

    assign ex_rs1_data =
        (ex_mem_valid && ex_mem_rf_we && !ex_mem_mem_read &&
         (ex_mem_rd != 5'b0) && (ex_mem_rd == id_ex_rs1)) ? ex_mem_forward_data :
        (wb_rf_write && (mem_wb_rd != 5'b0) && (mem_wb_rd == id_ex_rs1)) ? wb_wdata :
                                                                           id_ex_rs1_data;

    assign ex_rs2_data =
        (ex_mem_valid && ex_mem_rf_we && !ex_mem_mem_read &&
         (ex_mem_rd != 5'b0) && (ex_mem_rd == id_ex_rs2)) ? ex_mem_forward_data :
        (wb_rf_write && (mem_wb_rd != 5'b0) && (mem_wb_rd == id_ex_rs2)) ? wb_wdata :
                                                                           id_ex_rs2_data;

    assign ex_alu_a = id_ex_alu_src_a ? 32'b0 : ex_rs1_data;
    assign ex_alu_b =
        (id_ex_alu_src_b == `ALUSrcB_Imm)    ? id_ex_imm32 :
        (id_ex_alu_src_b == `ALUSrcB_Offset) ? id_ex_imm_addr :
                                               ex_rs2_data;

    ALU U_ALU(
        .A(ex_alu_a),
        .B(ex_alu_b),
        .ALUOp(id_ex_alu_op),
        .ALU_result(ex_alu_result),
        .zero(ex_zero),
        .less(ex_less),
        .lessu(ex_lessu)
    );

    assign ex_branch_taken =
        id_ex_valid && id_ex_is_btype &&
        ((id_ex_funct3 == `INSTR_BEQ_FUNCT)  ? (ex_rs1_data == ex_rs2_data) :
         (id_ex_funct3 == `INSTR_BNE_FUNCT)  ? (ex_rs1_data != ex_rs2_data) :
         (id_ex_funct3 == `INSTR_BLT_FUNCT)  ? ($signed(ex_rs1_data) < $signed(ex_rs2_data)) :
         (id_ex_funct3 == `INSTR_BGE_FUNCT)  ? ($signed(ex_rs1_data) >= $signed(ex_rs2_data)) :
         (id_ex_funct3 == `INSTR_BLTU_FUNCT) ? (ex_rs1_data < ex_rs2_data) :
         (id_ex_funct3 == `INSTR_BGEU_FUNCT) ? (ex_rs1_data >= ex_rs2_data) :
                                               1'b0);

    assign ex_branch_target = id_ex_pc + id_ex_imm_b;
    assign ex_jal_target = id_ex_pc + id_ex_imm_j;
    assign ex_jalr_target = (ex_rs1_data + id_ex_imm_i) & 32'hFFFF_FFFE;
    assign redirect_taken = id_ex_valid &&
                            (ex_branch_taken || id_ex_is_jal || id_ex_is_jalr);
    assign redirect_pc = id_ex_is_jalr ? ex_jalr_target :
                         id_ex_is_jal  ? ex_jal_target  :
                                         ex_branch_target;
    assign ex_u_wdata = id_ex_is_auipc ? (id_ex_pc + id_ex_imm_u) : id_ex_imm_u;

    assign dm_ctrl = ex_mem_mem_write ? `DMCtrl_WR : `DMCtrl_RD;

    DM U_DM(
        .Addr(ex_mem_alu_result),
        .WD(ex_mem_store_data),
        .Funct3(ex_mem_funct3),
        .DMCtrl(dm_ctrl),
        .clk(clk),
        .RD(dm_rd)
    );

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            if_id_valid <= 1'b0;
            if_id_pc <= 32'b0;
            if_id_inst <= 32'b0;
        end else if (redirect_taken) begin
            if_id_valid <= 1'b0;
            if_id_pc <= 32'b0;
            if_id_inst <= 32'b0;
        end else if (!load_use_stall) begin
            if_id_valid <= 1'b1;
            if_id_pc <= PC;
            if_id_inst <= in_ins;
        end
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            id_ex_valid <= 1'b0;
            id_ex_pc <= 32'b0;
            id_ex_pc4 <= 32'b0;
            id_ex_rs1_data <= 32'b0;
            id_ex_rs2_data <= 32'b0;
            id_ex_imm_i <= 32'b0;
            id_ex_imm32 <= 32'b0;
            id_ex_imm_addr <= 32'b0;
            id_ex_imm_b <= 32'b0;
            id_ex_imm_u <= 32'b0;
            id_ex_imm_j <= 32'b0;
            id_ex_rs1 <= 5'b0;
            id_ex_rs2 <= 5'b0;
            id_ex_rd <= 5'b0;
            id_ex_funct3 <= 3'b0;
            id_ex_alu_src_a <= 1'b0;
            id_ex_alu_src_b <= `ALUSrcB_B;
            id_ex_alu_op <= `ALUOp_ADD;
            id_ex_mem_read <= 1'b0;
            id_ex_mem_write <= 1'b0;
            id_ex_rf_we <= 1'b0;
            id_ex_wd_sel <= `WDSel_FromALU;
            id_ex_is_btype <= 1'b0;
            id_ex_is_jal <= 1'b0;
            id_ex_is_jalr <= 1'b0;
            id_ex_is_lui <= 1'b0;
            id_ex_is_auipc <= 1'b0;
        end else if (redirect_taken || load_use_stall) begin
            id_ex_valid <= 1'b0;
            id_ex_mem_read <= 1'b0;
            id_ex_mem_write <= 1'b0;
            id_ex_rf_we <= 1'b0;
            id_ex_is_btype <= 1'b0;
            id_ex_is_jal <= 1'b0;
            id_ex_is_jalr <= 1'b0;
            id_ex_is_lui <= 1'b0;
            id_ex_is_auipc <= 1'b0;
            id_ex_wd_sel <= `WDSel_FromALU;
            id_ex_alu_op <= `ALUOp_ADD;
        end else begin
            id_ex_valid <= if_id_valid;
            id_ex_pc <= if_id_pc;
            id_ex_pc4 <= if_id_pc + 32'd4;
            id_ex_rs1_data <= id_rd1;
            id_ex_rs2_data <= id_rd2;
            id_ex_imm_i <= id_imm_i;
            id_ex_imm32 <= id_imm32;
            id_ex_imm_addr <= id_imm_addr;
            id_ex_imm_b <= id_imm_b;
            id_ex_imm_u <= id_imm_u;
            id_ex_imm_j <= id_imm_j;
            id_ex_rs1 <= id_rs1;
            id_ex_rs2 <= id_rs2;
            id_ex_rd <= id_rd;
            id_ex_funct3 <= id_funct3;
            id_ex_alu_src_a <= id_alu_src_a;
            id_ex_alu_src_b <= id_alu_src_b;
            id_ex_alu_op <= id_alu_op;
            id_ex_mem_read <= if_id_valid && id_mem_read;
            id_ex_mem_write <= if_id_valid && id_mem_write;
            id_ex_rf_we <= if_id_valid && id_rf_we;
            id_ex_wd_sel <= id_wd_sel;
            id_ex_is_btype <= if_id_valid && id_is_btype;
            id_ex_is_jal <= if_id_valid && id_is_jal;
            id_ex_is_jalr <= if_id_valid && id_is_jalr;
            id_ex_is_lui <= if_id_valid && id_is_lui;
            id_ex_is_auipc <= if_id_valid && id_is_auipc;
        end
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            ex_mem_valid <= 1'b0;
            ex_mem_pc <= 32'b0;
            ex_mem_pc4 <= 32'b0;
            ex_mem_alu_result <= 32'b0;
            ex_mem_store_data <= 32'b0;
            ex_mem_u_wdata <= 32'b0;
            ex_mem_rd <= 5'b0;
            ex_mem_funct3 <= 3'b0;
            ex_mem_mem_read <= 1'b0;
            ex_mem_mem_write <= 1'b0;
            ex_mem_rf_we <= 1'b0;
            ex_mem_wd_sel <= `WDSel_FromALU;
        end else begin
            ex_mem_valid <= id_ex_valid;
            ex_mem_pc <= id_ex_pc;
            ex_mem_pc4 <= id_ex_pc4;
            ex_mem_alu_result <= ex_alu_result;
            ex_mem_store_data <= ex_rs2_data;
            ex_mem_u_wdata <= ex_u_wdata;
            ex_mem_rd <= id_ex_rd;
            ex_mem_funct3 <= id_ex_funct3;
            ex_mem_mem_read <= id_ex_valid && id_ex_mem_read;
            ex_mem_mem_write <= id_ex_valid && id_ex_mem_write;
            ex_mem_rf_we <= id_ex_valid && id_ex_rf_we;
            ex_mem_wd_sel <= id_ex_wd_sel;
        end
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            mem_wb_valid <= 1'b0;
            mem_wb_pc <= 32'b0;
            mem_wb_pc4 <= 32'b0;
            mem_wb_alu_result <= 32'b0;
            mem_wb_mem_data <= 32'b0;
            mem_wb_u_wdata <= 32'b0;
            mem_wb_rd <= 5'b0;
            mem_wb_rf_we <= 1'b0;
            mem_wb_wd_sel <= `WDSel_FromALU;
        end else begin
            mem_wb_valid <= ex_mem_valid;
            mem_wb_pc <= ex_mem_pc;
            mem_wb_pc4 <= ex_mem_pc4;
            mem_wb_alu_result <= ex_mem_alu_result;
            mem_wb_mem_data <= dm_rd;
            mem_wb_u_wdata <= ex_mem_u_wdata;
            mem_wb_rd <= ex_mem_rd;
            mem_wb_rf_we <= ex_mem_valid && ex_mem_rf_we;
            mem_wb_wd_sel <= ex_mem_wd_sel;
        end
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            debug_wb_have_inst <= 1'b0;
            debug_wb_pc <= 32'b0;
            debug_wb_ena <= 1'b0;
            debug_wb_reg <= 5'b0;
            debug_wb_value <= 32'b0;
        end else begin
            debug_wb_have_inst <= mem_wb_valid;
            debug_wb_pc <= mem_wb_pc;
            debug_wb_ena <= mem_wb_valid ? mem_wb_rf_we : 1'b0;
            debug_wb_reg <= mem_wb_valid ? mem_wb_rd : 5'b0;
            debug_wb_value <= mem_wb_valid ? wb_wdata : 32'b0;
        end
    end
endmodule
