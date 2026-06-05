// A control signal
`define ALUSrcA_A 1'b0

// B control signal
`define ALUSrcB_B 2'b00
`define ALUSrcB_Imm 2'b01
`define ALUSrcB_Offset 2'b10

// EXT control signal
`define ExtSel_ZERO 1'b0
`define ExtSel_SIGNED 1'b1

// ALU control signal
`define ALUOp_ADD 4'b0000
`define ALUOp_SUB 4'b0001
`define ALUOp_AND 4'b0010
`define ALUOp_OR 4'b0011
`define ALUOp_XOR 4'b0100
`define ALUOp_SRA 4'b0111
`define ALUOp_SLL 4'b1000
`define ALUOp_SRL 4'b1001
`define ALUOp_BR 4'b1010
`define ALUOp_SLT  4'b1011
`define ALUOp_SLTU 4'b1100

`define WDSel_FromALU 2'b00
`define WDSel_FromMEM 2'b01
`define WDSel_FromPC 2'b10
`define WDSel_Else 2'b11

// DM control signal
`define DMCtrl_RD 1'b0
`define DMCtrl_WR 1'b1
