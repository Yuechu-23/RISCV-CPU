// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VminiRV_SoC__Syms.h"


void VminiRV_SoC___024root__trace_chg_0_sub_0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VminiRV_SoC___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_chg_0\n"); );
    // Init
    VminiRV_SoC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VminiRV_SoC___024root*>(voidSelf);
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VminiRV_SoC___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VminiRV_SoC___024root__trace_chg_0_sub_0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i),32);
        bufp->chgIData(oldp+1,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__mem_file),32);
        bufp->chgIData(oldp+2,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i),32);
        bufp->chgIData(oldp+3,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__mem_file),32);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+4,(vlSelf->miniRV_SoC__DOT__cpu__DOT__RFWrite));
        bufp->chgBit(oldp+5,(vlSelf->miniRV_SoC__DOT__cpu__DOT__DMCtrl));
        bufp->chgBit(oldp+6,(vlSelf->miniRV_SoC__DOT__cpu__DOT__AWrite));
        bufp->chgBit(oldp+7,(vlSelf->miniRV_SoC__DOT__cpu__DOT__BWrite));
        bufp->chgBit(oldp+8,(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOutWrite));
        bufp->chgCData(oldp+9,(vlSelf->miniRV_SoC__DOT__cpu__DOT__WDSel),2);
        bufp->chgCData(oldp+10,(vlSelf->miniRV_SoC__DOT__cpu__DOT__RegSel),2);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[4U]))) {
        bufp->chgBit(oldp+11,(vlSelf->miniRV_SoC__DOT__cpu__DOT__PCWrite));
        bufp->chgBit(oldp+12,(vlSelf->miniRV_SoC__DOT__cpu__DOT__ExtSel));
        bufp->chgBit(oldp+13,((0U == vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result)));
        bufp->chgBit(oldp+14,(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcA));
        bufp->chgCData(oldp+15,(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcB),2);
        bufp->chgCData(oldp+16,(vlSelf->miniRV_SoC__DOT__cpu__DOT__NPCOp),2);
        bufp->chgCData(oldp+17,(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp),4);
        bufp->chgIData(oldp+18,(vlSelf->miniRV_SoC__DOT__cpu__DOT__NPC),32);
        bufp->chgIData(oldp+19,(vlSelf->miniRV_SoC__DOT__cpu__DOT__Imm32),32);
        bufp->chgCData(oldp+20,(vlSelf->miniRV_SoC__DOT__cpu__DOT__WR),5);
        bufp->chgIData(oldp+21,(vlSelf->miniRV_SoC__DOT__cpu__DOT__WD),32);
        bufp->chgIData(oldp+22,(vlSelf->miniRV_SoC__DOT__cpu__DOT__A),32);
        bufp->chgIData(oldp+23,(vlSelf->miniRV_SoC__DOT__cpu__DOT__B),32);
        bufp->chgIData(oldp+24,(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+25,(vlSelf->miniRV_SoC__DOT__cpu__DOT__RD1_r),32);
        bufp->chgIData(oldp+26,(vlSelf->miniRV_SoC__DOT__cpu__DOT__RD2_r),32);
        bufp->chgIData(oldp+27,(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result_r),32);
        bufp->chgCData(oldp+28,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state),4);
        bufp->chgSData(oldp+29,((0x3ffU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result_r 
                                           >> 2U))),10);
        bufp->chgCData(oldp+30,((3U & vlSelf->miniRV_SoC__DOT__cpu__DOT__RD2_r)),2);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgCData(oldp+31,((0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)),7);
        bufp->chgCData(oldp+32,((7U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+33,((vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                 >> 0x19U)),7);
        bufp->chgIData(oldp+34,(vlSelf->miniRV_SoC__DOT__cpu__DOT__in_ins),32);
        bufp->chgIData(oldp+35,(vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins),32);
        bufp->chgCData(oldp+36,((0x1fU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+37,((0x1fU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+38,((0x1fU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                          >> 7U))),5);
        bufp->chgSData(oldp+39,((vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                 >> 0x14U)),12);
        bufp->chgIData(oldp+40,(((0x80000U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                              >> 0xcU)) 
                                 | ((0x7f800U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                 >> 1U)) 
                                    | ((0x400U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                  >> 0xaU)) 
                                       | (0x3ffU & 
                                          (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                           >> 0x15U)))))),20);
        bufp->chgSData(oldp+41,(vlSelf->miniRV_SoC__DOT__cpu__DOT____Vcellinp__U_MUX_3to1_B__Z),12);
        bufp->chgIData(oldp+42,(vlSelf->miniRV_SoC__DOT__cpu__DOT__RD1),32);
        bufp->chgIData(oldp+43,(((0U == (0x1fU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                  >> 0x14U)))
                                  ? 0U : vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register
                                 [(0x1fU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                            >> 0x14U))])),32);
        bufp->chgBit(oldp+44,(((0x33U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)) 
                               | ((0x13U == (0x7fU 
                                             & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)) 
                                  | ((3U == (0x7fU 
                                             & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)) 
                                     | ((0x23U == (0x7fU 
                                                   & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)) 
                                        | ((0x63U == 
                                            (0x7fU 
                                             & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)) 
                                           | ((0x6fU 
                                               == (0x7fU 
                                                   & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)) 
                                              | (0x67U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))))))))));
        bufp->chgSData(oldp+45,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all),10);
        bufp->chgSData(oldp+46,(((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT____Vcellinp__U_MUX_3to1_B__Z) 
                                 << 1U)),13);
        bufp->chgIData(oldp+47,(((0x100000U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                               >> 0xbU)) 
                                 | ((0xff000U & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins) 
                                    | ((0x800U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                  >> 9U)) 
                                       | (0x7feU & 
                                          (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                           >> 0x14U)))))),21);
        bufp->chgIData(oldp+48,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[0]),32);
        bufp->chgIData(oldp+49,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[1]),32);
        bufp->chgIData(oldp+50,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[2]),32);
        bufp->chgIData(oldp+51,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[3]),32);
        bufp->chgIData(oldp+52,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[4]),32);
        bufp->chgIData(oldp+53,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[5]),32);
        bufp->chgIData(oldp+54,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[6]),32);
        bufp->chgIData(oldp+55,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[7]),32);
        bufp->chgIData(oldp+56,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[8]),32);
        bufp->chgIData(oldp+57,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[9]),32);
        bufp->chgIData(oldp+58,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[10]),32);
        bufp->chgIData(oldp+59,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[11]),32);
        bufp->chgIData(oldp+60,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[12]),32);
        bufp->chgIData(oldp+61,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[13]),32);
        bufp->chgIData(oldp+62,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[14]),32);
        bufp->chgIData(oldp+63,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[15]),32);
        bufp->chgIData(oldp+64,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[16]),32);
        bufp->chgIData(oldp+65,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[17]),32);
        bufp->chgIData(oldp+66,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[18]),32);
        bufp->chgIData(oldp+67,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[19]),32);
        bufp->chgIData(oldp+68,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[20]),32);
        bufp->chgIData(oldp+69,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[21]),32);
        bufp->chgIData(oldp+70,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[22]),32);
        bufp->chgIData(oldp+71,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[23]),32);
        bufp->chgIData(oldp+72,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[24]),32);
        bufp->chgIData(oldp+73,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[25]),32);
        bufp->chgIData(oldp+74,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[26]),32);
        bufp->chgIData(oldp+75,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[27]),32);
        bufp->chgIData(oldp+76,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[28]),32);
        bufp->chgIData(oldp+77,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[29]),32);
        bufp->chgIData(oldp+78,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[30]),32);
        bufp->chgIData(oldp+79,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[31]),32);
    }
    bufp->chgBit(oldp+80,(vlSelf->fpga_rst));
    bufp->chgBit(oldp+81,(vlSelf->fpga_clk));
    bufp->chgBit(oldp+82,(vlSelf->debug_wb_have_inst));
    bufp->chgIData(oldp+83,(vlSelf->debug_wb_pc),32);
    bufp->chgBit(oldp+84,(vlSelf->debug_wb_ena));
    bufp->chgCData(oldp+85,(vlSelf->debug_wb_reg),5);
    bufp->chgIData(oldp+86,(vlSelf->debug_wb_value),32);
    bufp->chgBit(oldp+87,(vlSelf->miniRV_SoC__DOT__cpu__DOT__IRWrite));
    bufp->chgBit(oldp+88,(vlSelf->miniRV_SoC__DOT__cpu__DOT__InsMemRW));
    bufp->chgIData(oldp+89,(vlSelf->miniRV_SoC__DOT__cpu__DOT__PC),32);
    bufp->chgIData(oldp+90,(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__rd_reg),32);
    bufp->chgBit(oldp+91,(vlSelf->miniRV_SoC__DOT__cpu__DOT__commit_now));
    bufp->chgSData(oldp+92,((0x3ffU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__PC 
                                       >> 2U))),10);
}

void VminiRV_SoC___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_cleanup\n"); );
    // Init
    VminiRV_SoC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VminiRV_SoC___024root*>(voidSelf);
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}
