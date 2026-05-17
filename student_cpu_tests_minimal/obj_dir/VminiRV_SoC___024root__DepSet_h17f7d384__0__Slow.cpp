// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC___024root.h"

VL_ATTR_COLD void VminiRV_SoC___024root___eval_static(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_static\n"); );
}

VL_ATTR_COLD void VminiRV_SoC___024root___eval_initial__TOP(VminiRV_SoC___024root* vlSelf);

VL_ATTR_COLD void VminiRV_SoC___024root___eval_initial(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_initial\n"); );
    // Body
    VminiRV_SoC___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigprevexpr___TOP__fpga_clk__0 = vlSelf->fpga_clk;
    vlSelf->__Vtrigprevexpr___TOP__fpga_rst__0 = vlSelf->fpga_rst;
}

VL_ATTR_COLD void VminiRV_SoC___024root___eval_final(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__stl(VminiRV_SoC___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VminiRV_SoC___024root___eval_phase__stl(VminiRV_SoC___024root* vlSelf);

VL_ATTR_COLD void VminiRV_SoC___024root___eval_settle(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VminiRV_SoC___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("mySoC/miniRV_SoC.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VminiRV_SoC___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__stl(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VminiRV_SoC___024root___stl_sequent__TOP__0(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->miniRV_SoC__DOT__cpu__DOT__InsMemRW = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__IRWrite = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__RFWrite = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__AWrite = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__BWrite = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOutWrite = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__DMCtrl = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__commit_now = 
        ((0xbU == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state)) 
         | ((9U == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state)) 
            | ((0xaU == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state)) 
               | ((5U == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state)) 
                  | ((6U == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state)) 
                     | ((7U == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state)) 
                        | ((~ ((0x33U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)) 
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
                                                  & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))))))))) 
                           & (2U == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state)))))))));
    vlSelf->miniRV_SoC__DOT__cpu__DOT__RegSel = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__WDSel = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__RD1 = ((0U == 
                                               (0x1fU 
                                                & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                   >> 0xfU)))
                                               ? 0U
                                               : vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register
                                              [(0x1fU 
                                                & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                   >> 0xfU))]);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcA = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all 
        = ((0x3f8U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                      >> 0x16U)) | (7U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                          >> 0xcU)));
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcB = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ExtSel = 1U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT____Vcellinp__U_MUX_3to1_B__Z 
        = (0xfffU & ((0x63U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))
                      ? ((0x800U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                    >> 0x14U)) | ((0x400U 
                                                   & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                      << 3U)) 
                                                  | ((0x3f0U 
                                                      & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                         >> 0x15U)) 
                                                     | (0xfU 
                                                        & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                           >> 8U)))))
                      : ((0x23U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))
                          ? ((0xfe0U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                        >> 0x14U)) 
                             | (0x1fU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                         >> 7U))) : 
                         (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                          >> 0x14U))));
    if ((1U & (~ (IData)(vlSelf->fpga_rst)))) {
        if ((8U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
            if ((4U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                vlSelf->miniRV_SoC__DOT__cpu__DOT__InsMemRW = 1U;
            }
            if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                    if ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__RFWrite = 1U;
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__RegSel = 0U;
                    }
                    if ((1U & (~ (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state)))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__DMCtrl = 1U;
                    }
                } else {
                    if ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__RFWrite = 1U;
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__RegSel = 0U;
                    }
                    if ((1U & (~ (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state)))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__DMCtrl = 0U;
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state)))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__InsMemRW = 1U;
                    }
                }
            }
            if ((4U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                if ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                    vlSelf->miniRV_SoC__DOT__cpu__DOT__RFWrite = 1U;
                    vlSelf->miniRV_SoC__DOT__cpu__DOT__RegSel = 0U;
                }
            } else if ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                if ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                    vlSelf->miniRV_SoC__DOT__cpu__DOT__RegSel = 0U;
                }
            }
        }
        if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__IRWrite = 1U;
                    }
                }
                if ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                    if ((1U & (~ (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state)))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__AWrite = 1U;
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__BWrite = 1U;
                    }
                }
            }
            if ((4U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state)))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOutWrite = 1U;
                    }
                }
            } else if ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                if ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOutWrite = 1U;
                }
            }
        }
    }
    vlSelf->miniRV_SoC__DOT__cpu__DOT__WR = (0x1fU 
                                             & ((2U 
                                                 & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__RegSel))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__RegSel))
                                                  ? 0U
                                                  : 0x1fU)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__RegSel))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                  >> 7U))));
    if ((1U & (~ (IData)(vlSelf->fpga_rst)))) {
        if ((8U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
            if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                    if ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__WDSel = 0U;
                    }
                } else if ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                    vlSelf->miniRV_SoC__DOT__cpu__DOT__WDSel = 1U;
                }
            }
        } else if ((4U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
            if ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                vlSelf->miniRV_SoC__DOT__cpu__DOT__WDSel = 2U;
            }
        } else if ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
            if ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                vlSelf->miniRV_SoC__DOT__cpu__DOT__WDSel = 0U;
            }
        }
    }
    vlSelf->miniRV_SoC__DOT__cpu__DOT__WD = ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__WDSel))
                                              ? ((1U 
                                                  & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__WDSel))
                                                  ? 0U
                                                  : vlSelf->miniRV_SoC__DOT__cpu__DOT__PC)
                                              : ((1U 
                                                  & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__WDSel))
                                                  ? vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__rd_reg
                                                  : vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result_r));
    if ((1U & (~ (IData)(vlSelf->fpga_rst)))) {
        if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                      >> 3U)))) {
            if ((4U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                              >> 1U)))) {
                    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcA = 0U;
                }
            } else if ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                if ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                    if ((0x33U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcA = 0U;
                    } else if ((0x13U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcA = 0U;
                    } else if ((0x37U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcA = 1U;
                    } else if ((0x17U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcA = 1U;
                    }
                }
            }
        }
    }
    vlSelf->miniRV_SoC__DOT__cpu__DOT__A = ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcA)
                                             ? 0U : vlSelf->miniRV_SoC__DOT__cpu__DOT__RD1_r);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp = 0U;
    if ((1U & (~ (IData)(vlSelf->fpga_rst)))) {
        if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                      >> 3U)))) {
            if ((4U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                              >> 1U)))) {
                    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcB 
                        = ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))
                            ? 0U : 2U);
                }
                if ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                    if ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ExtSel = 1U;
                    }
                } else if ((1U & (~ (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state)))) {
                    vlSelf->miniRV_SoC__DOT__cpu__DOT__ExtSel = 1U;
                }
            } else if ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                if ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                    if ((0x33U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcB = 0U;
                    } else if ((0x13U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcB = 1U;
                    } else if ((0x37U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcB = 1U;
                    } else if ((0x17U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcB = 1U;
                    }
                    if ((0x33U != (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))) {
                        if ((0x13U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))) {
                            vlSelf->miniRV_SoC__DOT__cpu__DOT__ExtSel 
                                = ((0x4000U & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)
                                    ? ((1U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                              >> 0xdU)) 
                                       || (1U & (~ 
                                                 (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                  >> 0xcU))))
                                    : ((1U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                              >> 0xdU)) 
                                       || (1U & (~ 
                                                 (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                  >> 0xcU)))));
                        } else if ((0x37U == (0x7fU 
                                              & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))) {
                            vlSelf->miniRV_SoC__DOT__cpu__DOT__ExtSel = 1U;
                        } else if ((0x17U == (0x7fU 
                                              & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))) {
                            vlSelf->miniRV_SoC__DOT__cpu__DOT__ExtSel = 1U;
                        }
                    }
                }
            }
        }
    }
    vlSelf->miniRV_SoC__DOT__cpu__DOT__Imm32 = ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ExtSel)
                                                 ? 
                                                ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ExtSel)
                                                  ? 
                                                 (((- (IData)(
                                                              (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                               >> 0x1fU))) 
                                                   << 0xcU) 
                                                  | (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                     >> 0x14U))
                                                  : 0U)
                                                 : 
                                                (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                 >> 0x14U));
    vlSelf->miniRV_SoC__DOT__cpu__DOT__B = ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcB))
                                             ? ((1U 
                                                 & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcB))
                                                 ? vlSelf->miniRV_SoC__DOT__cpu__DOT__RD2_r
                                                 : 
                                                VL_EXTENDS_II(32,12, (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT____Vcellinp__U_MUX_3to1_B__Z)))
                                             : ((1U 
                                                 & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcB))
                                                 ? vlSelf->miniRV_SoC__DOT__cpu__DOT__Imm32
                                                 : vlSelf->miniRV_SoC__DOT__cpu__DOT__RD2_r));
    if ((1U & (~ (IData)(vlSelf->fpga_rst)))) {
        if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                      >> 3U)))) {
            if ((4U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                              >> 1U)))) {
                    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp 
                        = ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))
                            ? 0xaU : 0U);
                }
            } else if ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                if ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                    if ((0x33U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp 
                            = (((((((((0U == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all)) 
                                      | (0x100U == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all))) 
                                     | (7U == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all))) 
                                    | (6U == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all))) 
                                   | (4U == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all))) 
                                  | (1U == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all))) 
                                 | (5U == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all))) 
                                | (0x105U == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all)))
                                ? ((0U == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all))
                                    ? 0U : ((0x100U 
                                             == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all))
                                             ? 1U : 
                                            ((7U == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all))
                                              ? 2U : 
                                             ((6U == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all))
                                               ? 3U
                                               : ((4U 
                                                   == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all))
                                                   ? 4U
                                                   : 
                                                  ((1U 
                                                    == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all))
                                                    ? 8U
                                                    : 
                                                   ((5U 
                                                     == (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all))
                                                     ? 9U
                                                     : 7U)))))))
                                : 0U);
                    } else if ((0x13U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp 
                            = ((0x4000U & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)
                                ? ((0x2000U & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)
                                    ? ((0x1000U & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)
                                        ? 2U : 3U) : 
                                   ((0x1000U & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)
                                     ? ((0x20U == (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                   >> 0x19U))
                                         ? 7U : 9U)
                                     : 4U)) : ((0x2000U 
                                                & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)
                                                ? 0xaU
                                                : (
                                                   (0x1000U 
                                                    & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)
                                                    ? 8U
                                                    : 0U)));
                    } else if ((0x37U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp = 0U;
                    } else if ((0x17U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp = 0U;
                    }
                }
            }
        }
    }
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result = 
        ((8U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp))
          ? ((4U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp))
              ? 0U : ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp))
                       ? ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp))
                           ? 0U : (vlSelf->miniRV_SoC__DOT__cpu__DOT__A 
                                   - vlSelf->miniRV_SoC__DOT__cpu__DOT__B))
                       : ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp))
                           ? (vlSelf->miniRV_SoC__DOT__cpu__DOT__A 
                              >> (0x1fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__B))
                           : (vlSelf->miniRV_SoC__DOT__cpu__DOT__A 
                              << (0x1fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__B)))))
          : ((4U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp))
              ? ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp))
                  ? ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp))
                      ? VL_SHIFTRS_III(32,32,5, vlSelf->miniRV_SoC__DOT__cpu__DOT__A, 
                                       (0x1fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__B))
                      : ((vlSelf->miniRV_SoC__DOT__cpu__DOT__A 
                          < vlSelf->miniRV_SoC__DOT__cpu__DOT__B)
                          ? 1U : 0U)) : ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp))
                                          ? (VL_LTS_III(32, vlSelf->miniRV_SoC__DOT__cpu__DOT__A, vlSelf->miniRV_SoC__DOT__cpu__DOT__B)
                                              ? 1U : 0U)
                                          : (vlSelf->miniRV_SoC__DOT__cpu__DOT__A 
                                             ^ vlSelf->miniRV_SoC__DOT__cpu__DOT__B)))
              : ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp))
                  ? ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp))
                      ? (vlSelf->miniRV_SoC__DOT__cpu__DOT__A 
                         | vlSelf->miniRV_SoC__DOT__cpu__DOT__B)
                      : (vlSelf->miniRV_SoC__DOT__cpu__DOT__A 
                         & vlSelf->miniRV_SoC__DOT__cpu__DOT__B))
                  : ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp))
                      ? (vlSelf->miniRV_SoC__DOT__cpu__DOT__A 
                         - vlSelf->miniRV_SoC__DOT__cpu__DOT__B)
                      : (vlSelf->miniRV_SoC__DOT__cpu__DOT__A 
                         + vlSelf->miniRV_SoC__DOT__cpu__DOT__B)))));
    vlSelf->miniRV_SoC__DOT__cpu__DOT__PCWrite = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__NPCOp = 0U;
    if ((1U & (~ (IData)(vlSelf->fpga_rst)))) {
        if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                      >> 3U)))) {
            if ((4U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                if ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                    vlSelf->miniRV_SoC__DOT__cpu__DOT__PCWrite = 1U;
                    vlSelf->miniRV_SoC__DOT__cpu__DOT__NPCOp 
                        = ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))
                            ? 2U : 3U);
                } else if ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                    vlSelf->miniRV_SoC__DOT__cpu__DOT__PCWrite = 0U;
                    if ((0x4000U & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)) {
                        if ((0U != vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result)) {
                            vlSelf->miniRV_SoC__DOT__cpu__DOT__PCWrite = 1U;
                            vlSelf->miniRV_SoC__DOT__cpu__DOT__NPCOp = 1U;
                        }
                    } else {
                        if ((0x2000U & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)) {
                            vlSelf->miniRV_SoC__DOT__cpu__DOT__PCWrite = 0U;
                        } else if ((0x1000U & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)) {
                            if ((0U != vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result)) {
                                vlSelf->miniRV_SoC__DOT__cpu__DOT__PCWrite = 1U;
                            }
                        } else if ((0U == vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result)) {
                            vlSelf->miniRV_SoC__DOT__cpu__DOT__PCWrite = 1U;
                        }
                        if ((1U & (~ (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                      >> 0xdU)))) {
                            if ((0x1000U & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins)) {
                                if ((0U != vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result)) {
                                    vlSelf->miniRV_SoC__DOT__cpu__DOT__NPCOp = 1U;
                                }
                            } else if ((0U == vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result)) {
                                vlSelf->miniRV_SoC__DOT__cpu__DOT__NPCOp = 1U;
                            }
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                                 >> 1U)))) {
                if ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                    vlSelf->miniRV_SoC__DOT__cpu__DOT__PCWrite = 1U;
                    vlSelf->miniRV_SoC__DOT__cpu__DOT__NPCOp = 0U;
                }
            }
        }
    }
    vlSelf->miniRV_SoC__DOT__cpu__DOT__NPC = ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__NPCOp))
                                               ? ((1U 
                                                   & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__NPCOp))
                                                   ? 
                                                  (vlSelf->miniRV_SoC__DOT__cpu__DOT__PC 
                                                   + (IData)(
                                                             (0x1ffffffffULL 
                                                              & VL_EXTENDS_QI(33,21, 
                                                                              ((0x100000U 
                                                                                & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                                                >> 0xbU)) 
                                                                               | ((0xff000U 
                                                                                & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins) 
                                                                                | ((0x800U 
                                                                                & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                                                >> 9U)) 
                                                                                | (0x7feU 
                                                                                & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                                                >> 0x14U)))))))))
                                                   : 
                                                  (0xfffffffeU 
                                                   & (vlSelf->miniRV_SoC__DOT__cpu__DOT__RD1 
                                                      + 
                                                      (((- (IData)(
                                                                   (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                                    >> 0x1fU))) 
                                                        << 0xcU) 
                                                       | (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                          >> 0x14U)))))
                                               : ((1U 
                                                   & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__NPCOp))
                                                   ? 
                                                  (vlSelf->miniRV_SoC__DOT__cpu__DOT__PC 
                                                   + (IData)(
                                                             (0x1ffffffffULL 
                                                              & VL_EXTENDS_QI(33,13, 
                                                                              ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT____Vcellinp__U_MUX_3to1_B__Z) 
                                                                               << 1U)))))
                                                   : 
                                                  ((IData)(4U) 
                                                   + vlSelf->miniRV_SoC__DOT__cpu__DOT__PC)));
}

VL_ATTR_COLD void VminiRV_SoC___024root___eval_stl(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VminiRV_SoC___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void VminiRV_SoC___024root___eval_triggers__stl(VminiRV_SoC___024root* vlSelf);

VL_ATTR_COLD bool VminiRV_SoC___024root___eval_phase__stl(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VminiRV_SoC___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        VminiRV_SoC___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__ico(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__act(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge fpga_clk or posedge fpga_rst)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge fpga_clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__nba(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge fpga_clk or posedge fpga_rst)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge fpga_clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VminiRV_SoC___024root___ctor_var_reset(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->fpga_rst = VL_RAND_RESET_I(1);
    vlSelf->fpga_clk = VL_RAND_RESET_I(1);
    vlSelf->debug_wb_have_inst = VL_RAND_RESET_I(1);
    vlSelf->debug_wb_pc = VL_RAND_RESET_I(32);
    vlSelf->debug_wb_ena = VL_RAND_RESET_I(1);
    vlSelf->debug_wb_reg = VL_RAND_RESET_I(5);
    vlSelf->debug_wb_value = VL_RAND_RESET_I(32);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__RFWrite = VL_RAND_RESET_I(1);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__DMCtrl = VL_RAND_RESET_I(1);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__PCWrite = VL_RAND_RESET_I(1);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__IRWrite = VL_RAND_RESET_I(1);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__InsMemRW = VL_RAND_RESET_I(1);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ExtSel = VL_RAND_RESET_I(1);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcA = VL_RAND_RESET_I(1);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__AWrite = VL_RAND_RESET_I(1);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__BWrite = VL_RAND_RESET_I(1);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOutWrite = VL_RAND_RESET_I(1);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcB = VL_RAND_RESET_I(2);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__NPCOp = VL_RAND_RESET_I(2);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__WDSel = VL_RAND_RESET_I(2);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__RegSel = VL_RAND_RESET_I(2);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp = VL_RAND_RESET_I(4);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__PC = VL_RAND_RESET_I(32);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__NPC = VL_RAND_RESET_I(32);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__in_ins = VL_RAND_RESET_I(32);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins = VL_RAND_RESET_I(32);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__Imm32 = VL_RAND_RESET_I(32);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__WR = VL_RAND_RESET_I(5);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__WD = VL_RAND_RESET_I(32);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__RD1 = VL_RAND_RESET_I(32);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__RD1_r = VL_RAND_RESET_I(32);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__RD2_r = VL_RAND_RESET_I(32);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__A = VL_RAND_RESET_I(32);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__B = VL_RAND_RESET_I(32);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result = VL_RAND_RESET_I(32);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result_r = VL_RAND_RESET_I(32);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__commit_now = VL_RAND_RESET_I(1);
    vlSelf->miniRV_SoC__DOT__cpu__DOT____Vcellinp__U_MUX_3to1_B__Z = VL_RAND_RESET_I(12);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all = VL_RAND_RESET_I(10);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state = VL_RAND_RESET_I(4);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__memory[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__mem_rd[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__mem_file = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__mem_rd[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__rd_reg = VL_RAND_RESET_I(32);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__mem_file = 0;
    vlSelf->__Vdlyvset__miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register__v0 = 0;
    vlSelf->__Vdlyvdim0__miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register__v1 = 0;
    vlSelf->__Vdlyvval__miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register__v1 = VL_RAND_RESET_I(32);
    vlSelf->__Vdlyvset__miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register__v1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__fpga_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__fpga_rst__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
