// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VminiRV_SoC__Syms.h"


VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+81,0,"fpga_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"fpga_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"debug_wb_have_inst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+84,0,"debug_wb_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+85,0,"debug_wb_ena",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+86,0,"debug_wb_reg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+87,0,"debug_wb_value",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("miniRV_SoC", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+81,0,"fpga_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"fpga_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"debug_wb_have_inst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+84,0,"debug_wb_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+85,0,"debug_wb_ena",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+86,0,"debug_wb_reg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+87,0,"debug_wb_value",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("cpu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+82,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"debug_wb_have_inst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+84,0,"debug_wb_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+85,0,"debug_wb_ena",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+86,0,"debug_wb_reg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+87,0,"debug_wb_value",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+5,0,"RFWrite",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"DMCtrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"PCWrite",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"IRWrite",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"InsMemRW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"ExtSel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"zero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"ALUSrcA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"AWrite",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"BWrite",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"ALUOutWrite",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+16,0,"ALUSrcB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+17,0,"NPCOp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+10,0,"WDSel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+11,0,"RegSel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+18,0,"ALUOp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+32,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+33,0,"Funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+34,0,"Funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+90,0,"PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"NPC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,0,"PCA4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"in_ins",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"out_ins",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"RD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"DR_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+38,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+39,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+40,0,"Imm12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+20,0,"Imm32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"Offset20",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,1);
    tracep->declBus(c+42,0,"Offset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+21,0,"WR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+22,0,"WD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+43,0,"RD1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"RD1_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"RD2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"RD2_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+23,0,"A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,0,"ALU_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"ALU_result_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,0,"state_dbg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+94,0,"ST_ID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+95,0,"ST_EX_BR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+96,0,"ST_EX_JAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+97,0,"ST_EX_JALR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+98,0,"ST_MEM_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+99,0,"ST_MEM_WR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+100,0,"ST_WB_ALU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+45,0,"supported_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"commit_now",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("U_A", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+82,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+43,0,"in_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"out_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_ALU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+23,0,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"B",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"ALUOp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+14,0,"zero",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"ALU_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_ALU_result", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+82,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"in_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"out_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_B", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+82,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+44,0,"in_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"out_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_ControlUnit", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+81,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"zero",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+32,0,"opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+34,0,"Funct7",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+33,0,"Funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+12,0,"PCWrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"InsMemRW",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"IRWrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"RFWrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"DMCtrl",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"ExtSel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"ALUSrcA",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+16,0,"ALUSrcB",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+11,0,"RegSel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+17,0,"NPCOp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+10,0,"WDSel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+18,0,"ALUOp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+7,0,"AWrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"BWrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"ALUOutWrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+29,0,"state_dbg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+46,0,"funct_all",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+101,0,"INSTR_LUI_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+102,0,"INSTR_AUIPC_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+103,0,"ST_IF_REQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+104,0,"ST_IF_LATCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+94,0,"ST_ID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+105,0,"ST_EX_ALU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+106,0,"ST_EX_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+95,0,"ST_EX_BR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+96,0,"ST_EX_JAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+97,0,"ST_EX_JALR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+107,0,"ST_MEM_RD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+98,0,"ST_MEM_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+99,0,"ST_MEM_WR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+100,0,"ST_WB_ALU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+29,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_DM", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+30,0,"Addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,2);
    tracep->declBus(c+27,0,"WD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+82,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"DMCtrl",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"RD",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"rd_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+2,0,"mem_file",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+31,0,"byte_off",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_EXT", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+40,0,"imm_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+13,0,"ExtSel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+20,0,"imm_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_IM", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+82,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"InsMemRW",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,2);
    tracep->declBus(c+35,0,"Ins",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+4,0,"mem_file",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_IR", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+82,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"IRWrite",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+35,0,"in_ins",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"out_ins",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_MUX_2to1_A", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+26,0,"X",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,0,"Y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+15,0,"control",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_MUX_3to1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+39,0,"X",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+109,0,"Y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+110,0,"Z",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+11,0,"control",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+21,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_MUX_3to1_B", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+27,0,"X",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+20,0,"Y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"Z",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+16,0,"control",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+24,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_MUX_3to1_LMD", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+28,0,"X",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"Y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,0,"Z",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"control",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+22,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_NPC", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+17,0,"NPCOp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+42,0,"Offset12",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,1);
    tracep->declBus(c+41,0,"Offset20",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,1);
    tracep->declBus(c+40,0,"Imm12",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+90,0,"PC",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+43,0,"rs",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,0,"PCA4",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"NPC",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"Offset13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+48,0,"Offset21",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_PC", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+82,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"PCWrite",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"NPC",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,0,"PC",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_RF", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+37,0,"RR1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+38,0,"RR2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+21,0,"WR",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+22,0,"WD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+5,0,"RFWrite",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+43,0,"RD1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"RD2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("register", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+49+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_top(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_top\n"); );
    // Body
    VminiRV_SoC___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VminiRV_SoC___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VminiRV_SoC___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VminiRV_SoC___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_register(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&VminiRV_SoC___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&VminiRV_SoC___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&VminiRV_SoC___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&VminiRV_SoC___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_const_0_sub_0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_const_0\n"); );
    // Init
    VminiRV_SoC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VminiRV_SoC___024root*>(voidSelf);
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VminiRV_SoC___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_const_0_sub_0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+94,(2U),4);
    bufp->fullCData(oldp+95,(5U),4);
    bufp->fullCData(oldp+96,(6U),4);
    bufp->fullCData(oldp+97,(7U),4);
    bufp->fullCData(oldp+98,(9U),4);
    bufp->fullCData(oldp+99,(0xaU),4);
    bufp->fullCData(oldp+100,(0xbU),4);
    bufp->fullCData(oldp+101,(0x37U),7);
    bufp->fullCData(oldp+102,(0x17U),7);
    bufp->fullCData(oldp+103,(0U),4);
    bufp->fullCData(oldp+104,(1U),4);
    bufp->fullCData(oldp+105,(3U),4);
    bufp->fullCData(oldp+106,(4U),4);
    bufp->fullCData(oldp+107,(8U),4);
    bufp->fullIData(oldp+108,(0U),32);
    bufp->fullCData(oldp+109,(0U),5);
    bufp->fullCData(oldp+110,(0x1fU),5);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_full_0_sub_0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_full_0\n"); );
    // Init
    VminiRV_SoC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VminiRV_SoC___024root*>(voidSelf);
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VminiRV_SoC___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_full_0_sub_0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i),32);
    bufp->fullIData(oldp+2,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__mem_file),32);
    bufp->fullIData(oldp+3,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i),32);
    bufp->fullIData(oldp+4,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__mem_file),32);
    bufp->fullBit(oldp+5,(vlSelf->miniRV_SoC__DOT__cpu__DOT__RFWrite));
    bufp->fullBit(oldp+6,(vlSelf->miniRV_SoC__DOT__cpu__DOT__DMCtrl));
    bufp->fullBit(oldp+7,(vlSelf->miniRV_SoC__DOT__cpu__DOT__AWrite));
    bufp->fullBit(oldp+8,(vlSelf->miniRV_SoC__DOT__cpu__DOT__BWrite));
    bufp->fullBit(oldp+9,(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOutWrite));
    bufp->fullCData(oldp+10,(vlSelf->miniRV_SoC__DOT__cpu__DOT__WDSel),2);
    bufp->fullCData(oldp+11,(vlSelf->miniRV_SoC__DOT__cpu__DOT__RegSel),2);
    bufp->fullBit(oldp+12,(vlSelf->miniRV_SoC__DOT__cpu__DOT__PCWrite));
    bufp->fullBit(oldp+13,(vlSelf->miniRV_SoC__DOT__cpu__DOT__ExtSel));
    bufp->fullBit(oldp+14,((0U == vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result)));
    bufp->fullBit(oldp+15,(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcA));
    bufp->fullCData(oldp+16,(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcB),2);
    bufp->fullCData(oldp+17,(vlSelf->miniRV_SoC__DOT__cpu__DOT__NPCOp),2);
    bufp->fullCData(oldp+18,(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp),4);
    bufp->fullIData(oldp+19,(vlSelf->miniRV_SoC__DOT__cpu__DOT__NPC),32);
    bufp->fullIData(oldp+20,(vlSelf->miniRV_SoC__DOT__cpu__DOT__Imm32),32);
    bufp->fullCData(oldp+21,(vlSelf->miniRV_SoC__DOT__cpu__DOT__WR),5);
    bufp->fullIData(oldp+22,(vlSelf->miniRV_SoC__DOT__cpu__DOT__WD),32);
    bufp->fullIData(oldp+23,(vlSelf->miniRV_SoC__DOT__cpu__DOT__A),32);
    bufp->fullIData(oldp+24,(vlSelf->miniRV_SoC__DOT__cpu__DOT__B),32);
    bufp->fullIData(oldp+25,(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result),32);
    bufp->fullIData(oldp+26,(vlSelf->miniRV_SoC__DOT__cpu__DOT__RD1_r),32);
    bufp->fullIData(oldp+27,(vlSelf->miniRV_SoC__DOT__cpu__DOT__RD2_r),32);
    bufp->fullIData(oldp+28,(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result_r),32);
    bufp->fullCData(oldp+29,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state),4);
    bufp->fullSData(oldp+30,((0x3ffU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result_r 
                                        >> 2U))),10);
    bufp->fullCData(oldp+31,((3U & vlSelf->miniRV_SoC__DOT__cpu__DOT__RD2_r)),2);
    bufp->fullCData(oldp+32,((0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)),7);
    bufp->fullCData(oldp+33,((7U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+34,((vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                              >> 0x19U)),7);
    bufp->fullIData(oldp+35,(vlSelf->miniRV_SoC__DOT__cpu__DOT__in_ins),32);
    bufp->fullIData(oldp+36,(vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins),32);
    bufp->fullCData(oldp+37,((0x1fU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+38,((0x1fU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+39,((0x1fU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                       >> 7U))),5);
    bufp->fullSData(oldp+40,((vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                              >> 0x14U)),12);
    bufp->fullIData(oldp+41,(((0x80000U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                           >> 0xcU)) 
                              | ((0x7f800U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                              >> 1U)) 
                                 | ((0x400U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                               >> 0xaU)) 
                                    | (0x3ffU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                 >> 0x15U)))))),20);
    bufp->fullSData(oldp+42,(vlSelf->miniRV_SoC__DOT__cpu__DOT____Vcellinp__U_MUX_3to1_B__Z),12);
    bufp->fullIData(oldp+43,(vlSelf->miniRV_SoC__DOT__cpu__DOT__RD1),32);
    bufp->fullIData(oldp+44,(((0U == (0x1fU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                               >> 0x14U)))
                               ? 0U : vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register
                              [(0x1fU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                         >> 0x14U))])),32);
    bufp->fullBit(oldp+45,(((0x33U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)) 
                            | ((0x13U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)) 
                               | ((3U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)) 
                                  | ((0x23U == (0x7fU 
                                                & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)) 
                                     | ((0x63U == (0x7fU 
                                                   & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)) 
                                        | ((0x6fU == 
                                            (0x7fU 
                                             & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)) 
                                           | (0x67U 
                                              == (0x7fU 
                                                  & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))))))))));
    bufp->fullSData(oldp+46,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all),10);
    bufp->fullSData(oldp+47,(((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT____Vcellinp__U_MUX_3to1_B__Z) 
                              << 1U)),13);
    bufp->fullIData(oldp+48,(((0x100000U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                            >> 0xbU)) 
                              | ((0xff000U & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins) 
                                 | ((0x800U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                               >> 9U)) 
                                    | (0x7feU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                 >> 0x14U)))))),21);
    bufp->fullIData(oldp+49,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[0]),32);
    bufp->fullIData(oldp+50,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[1]),32);
    bufp->fullIData(oldp+51,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[2]),32);
    bufp->fullIData(oldp+52,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[3]),32);
    bufp->fullIData(oldp+53,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[4]),32);
    bufp->fullIData(oldp+54,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[5]),32);
    bufp->fullIData(oldp+55,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[6]),32);
    bufp->fullIData(oldp+56,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[7]),32);
    bufp->fullIData(oldp+57,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[8]),32);
    bufp->fullIData(oldp+58,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[9]),32);
    bufp->fullIData(oldp+59,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[10]),32);
    bufp->fullIData(oldp+60,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[11]),32);
    bufp->fullIData(oldp+61,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[12]),32);
    bufp->fullIData(oldp+62,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[13]),32);
    bufp->fullIData(oldp+63,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[14]),32);
    bufp->fullIData(oldp+64,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[15]),32);
    bufp->fullIData(oldp+65,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[16]),32);
    bufp->fullIData(oldp+66,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[17]),32);
    bufp->fullIData(oldp+67,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[18]),32);
    bufp->fullIData(oldp+68,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[19]),32);
    bufp->fullIData(oldp+69,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[20]),32);
    bufp->fullIData(oldp+70,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[21]),32);
    bufp->fullIData(oldp+71,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[22]),32);
    bufp->fullIData(oldp+72,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[23]),32);
    bufp->fullIData(oldp+73,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[24]),32);
    bufp->fullIData(oldp+74,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[25]),32);
    bufp->fullIData(oldp+75,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[26]),32);
    bufp->fullIData(oldp+76,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[27]),32);
    bufp->fullIData(oldp+77,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[28]),32);
    bufp->fullIData(oldp+78,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[29]),32);
    bufp->fullIData(oldp+79,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[30]),32);
    bufp->fullIData(oldp+80,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[31]),32);
    bufp->fullBit(oldp+81,(vlSelf->fpga_rst));
    bufp->fullBit(oldp+82,(vlSelf->fpga_clk));
    bufp->fullBit(oldp+83,(vlSelf->debug_wb_have_inst));
    bufp->fullIData(oldp+84,(vlSelf->debug_wb_pc),32);
    bufp->fullBit(oldp+85,(vlSelf->debug_wb_ena));
    bufp->fullCData(oldp+86,(vlSelf->debug_wb_reg),5);
    bufp->fullIData(oldp+87,(vlSelf->debug_wb_value),32);
    bufp->fullBit(oldp+88,(vlSelf->miniRV_SoC__DOT__cpu__DOT__IRWrite));
    bufp->fullBit(oldp+89,(vlSelf->miniRV_SoC__DOT__cpu__DOT__InsMemRW));
    bufp->fullIData(oldp+90,(vlSelf->miniRV_SoC__DOT__cpu__DOT__PC),32);
    bufp->fullIData(oldp+91,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__rd_reg),32);
    bufp->fullBit(oldp+92,(vlSelf->miniRV_SoC__DOT__cpu__DOT__commit_now));
    bufp->fullSData(oldp+93,((0x3ffU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__PC 
                                        >> 2U))),10);
}
