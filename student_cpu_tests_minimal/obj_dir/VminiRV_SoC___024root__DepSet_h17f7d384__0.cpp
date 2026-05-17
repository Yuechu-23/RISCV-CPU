// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC___024root.h"

VL_INLINE_OPT void VminiRV_SoC___024root___ico_sequent__TOP__0(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->miniRV_SoC__DOT__cpu__DOT__InsMemRW = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__IRWrite = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__RFWrite = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__AWrite = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__BWrite = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOutWrite = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__DMCtrl = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__RegSel = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__WDSel = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcA = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcB = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ExtSel = 1U;
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
                    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp 
                        = ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))
                            ? 0xaU : 0U);
                    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcA = 0U;
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
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcA = 0U;
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
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcA = 0U;
                    } else if ((0x37U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp = 0U;
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcA = 1U;
                    } else if ((0x17U == (0x7fU & vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp = 0U;
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcA = 1U;
                    }
                }
            }
        }
    }
    vlSelf->miniRV_SoC__DOT__cpu__DOT__A = ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcA)
                                             ? 0U : vlSelf->miniRV_SoC__DOT__cpu__DOT__RD1_r);
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

void VminiRV_SoC___024root___eval_ico(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VminiRV_SoC___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void VminiRV_SoC___024root___eval_triggers__ico(VminiRV_SoC___024root* vlSelf);

bool VminiRV_SoC___024root___eval_phase__ico(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VminiRV_SoC___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        VminiRV_SoC___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VminiRV_SoC___024root___eval_act(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_act\n"); );
}

VL_INLINE_OPT void VminiRV_SoC___024root___nba_sequent__TOP__0(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*9:0*/ __Vdlyvdim0__miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory__v0;
    __Vdlyvdim0__miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory__v0 = 0;
    IData/*31:0*/ __Vdlyvval__miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory__v0;
    __Vdlyvval__miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory__v0;
    __Vdlyvset__miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory__v0 = 0;
    // Body
    vlSelf->__Vdlyvset__miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register__v1 = 0U;
    __Vdlyvset__miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory__v0 = 0U;
    vlSelf->__Vdlyvset__miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register__v0 = 1U;
    if (((0U != (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__WR)) 
         & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__RFWrite))) {
        vlSelf->__Vdlyvval__miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register__v1 
            = vlSelf->miniRV_SoC__DOT__cpu__DOT__WD;
        vlSelf->__Vdlyvset__miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register__v1 = 1U;
        vlSelf->__Vdlyvdim0__miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register__v1 
            = vlSelf->miniRV_SoC__DOT__cpu__DOT__WR;
    }
    if (vlSelf->miniRV_SoC__DOT__cpu__DOT__DMCtrl) {
        __Vdlyvval__miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory__v0 
            = vlSelf->miniRV_SoC__DOT__cpu__DOT__RD2_r;
        __Vdlyvset__miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory__v0 = 1U;
        __Vdlyvdim0__miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory__v0 
            = (0x3ffU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result_r 
                         >> 2U));
    }
    if ((1U & (~ (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__DMCtrl)))) {
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__rd_reg 
            = vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory
            [(0x3ffU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result_r 
                        >> 2U))];
    }
    if (__Vdlyvset__miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory__v0) {
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory[__Vdlyvdim0__miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory__v0] 
            = __Vdlyvval__miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory__v0;
    }
}

extern const VlUnpacked<CData/*3:0*/, 4096> VminiRV_SoC__ConstPool__TABLE_h0d25cf4a_0;

VL_INLINE_OPT void VminiRV_SoC___024root___nba_sequent__TOP__1(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___nba_sequent__TOP__1\n"); );
    // Init
    SData/*11:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = ((0xfe0U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                               << 5U)) | (((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                                           << 1U) | (IData)(vlSelf->fpga_rst)));
    vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state 
        = VminiRV_SoC__ConstPool__TABLE_h0d25cf4a_0
        [__Vtableidx1];
    vlSelf->debug_wb_have_inst = ((1U & (~ (IData)(vlSelf->fpga_rst))) 
                                  && (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__commit_now));
    if (vlSelf->fpga_rst) {
        vlSelf->debug_wb_reg = 0U;
        vlSelf->debug_wb_value = 0U;
        vlSelf->miniRV_SoC__DOT__cpu__DOT__RD1_r = 0U;
        vlSelf->debug_wb_pc = 0U;
        vlSelf->miniRV_SoC__DOT__cpu__DOT__RD2_r = 0U;
        vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result_r = 0U;
    } else {
        if (vlSelf->miniRV_SoC__DOT__cpu__DOT__commit_now) {
            vlSelf->debug_wb_reg = vlSelf->miniRV_SoC__DOT__cpu__DOT__WR;
            vlSelf->debug_wb_value = vlSelf->miniRV_SoC__DOT__cpu__DOT__WD;
        } else {
            vlSelf->debug_wb_reg = 0U;
            vlSelf->debug_wb_value = 0U;
        }
        if (vlSelf->miniRV_SoC__DOT__cpu__DOT__AWrite) {
            vlSelf->miniRV_SoC__DOT__cpu__DOT__RD1_r 
                = vlSelf->miniRV_SoC__DOT__cpu__DOT__RD1;
        }
        vlSelf->debug_wb_pc = (vlSelf->miniRV_SoC__DOT__cpu__DOT__PC 
                               - (IData)(4U));
        if (vlSelf->miniRV_SoC__DOT__cpu__DOT__BWrite) {
            vlSelf->miniRV_SoC__DOT__cpu__DOT__RD2_r 
                = ((0U == (0x1fU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                    >> 0x14U))) ? 0U
                    : vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register
                   [(0x1fU & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                              >> 0x14U))]);
        }
        if (vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOutWrite) {
            vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result_r 
                = vlSelf->miniRV_SoC__DOT__cpu__DOT__ALU_result;
        }
    }
    vlSelf->debug_wb_ena = ((1U & (~ (IData)(vlSelf->fpga_rst))) 
                            && ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__commit_now) 
                                & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__RFWrite)));
    vlSelf->miniRV_SoC__DOT__cpu__DOT__RFWrite = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__AWrite = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__DMCtrl = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__RegSel = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__WDSel = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__BWrite = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOutWrite = 0U;
    if ((1U & (~ (IData)(vlSelf->fpga_rst)))) {
        if ((8U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
            if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                    if ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__RFWrite = 1U;
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__RegSel = 0U;
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__WDSel = 0U;
                    }
                    if ((1U & (~ (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state)))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__DMCtrl = 1U;
                    }
                } else {
                    if ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__RFWrite = 1U;
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__RegSel = 0U;
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__WDSel = 1U;
                    }
                    if ((1U & (~ (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state)))) {
                        vlSelf->miniRV_SoC__DOT__cpu__DOT__DMCtrl = 0U;
                    }
                }
            }
        } else if ((4U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
            if ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                vlSelf->miniRV_SoC__DOT__cpu__DOT__RFWrite = 1U;
                vlSelf->miniRV_SoC__DOT__cpu__DOT__RegSel = 0U;
                vlSelf->miniRV_SoC__DOT__cpu__DOT__WDSel = 2U;
            }
        } else if ((2U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
            if ((1U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                vlSelf->miniRV_SoC__DOT__cpu__DOT__RegSel = 0U;
                vlSelf->miniRV_SoC__DOT__cpu__DOT__WDSel = 0U;
            }
        }
        if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                          >> 2U)))) {
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
}

VL_INLINE_OPT void VminiRV_SoC___024root___nba_sequent__TOP__2(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___nba_sequent__TOP__2\n"); );
    // Body
    if (vlSelf->__Vdlyvset__miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register__v0) {
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[0U] = 0U;
    }
    if (vlSelf->__Vdlyvset__miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register__v1) {
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register[vlSelf->__Vdlyvdim0__miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register__v1] 
            = vlSelf->__Vdlyvval__miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register__v1;
    }
    if (vlSelf->miniRV_SoC__DOT__cpu__DOT__IRWrite) {
        vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
            = vlSelf->miniRV_SoC__DOT__cpu__DOT__in_ins;
    }
    vlSelf->miniRV_SoC__DOT__cpu__DOT__in_ins = ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__InsMemRW)
                                                  ? 
                                                 vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__memory
                                                 [(0x3ffU 
                                                   & (vlSelf->miniRV_SoC__DOT__cpu__DOT__PC 
                                                      >> 2U))]
                                                  : 0U);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__RD1 = ((0U == 
                                               (0x1fU 
                                                & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                   >> 0xfU)))
                                               ? 0U
                                               : vlSelf->miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register
                                              [(0x1fU 
                                                & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                                   >> 0xfU))]);
    vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all 
        = ((0x3f8U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                      >> 0x16U)) | (7U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__out_ins 
                                          >> 0xcU)));
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
}

VL_INLINE_OPT void VminiRV_SoC___024root___nba_sequent__TOP__3(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->miniRV_SoC__DOT__cpu__DOT__IRWrite = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__InsMemRW = 0U;
    if ((1U & (~ (IData)(vlSelf->fpga_rst)))) {
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
            }
        }
        if ((8U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
            if ((4U & (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state))) {
                vlSelf->miniRV_SoC__DOT__cpu__DOT__InsMemRW = 1U;
            }
        } else if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                             >> 2U)))) {
            if ((1U & (~ ((IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state)))) {
                    vlSelf->miniRV_SoC__DOT__cpu__DOT__InsMemRW = 1U;
                }
            }
        }
    }
    if (vlSelf->fpga_rst) {
        vlSelf->miniRV_SoC__DOT__cpu__DOT__PC = 0U;
    } else if (vlSelf->miniRV_SoC__DOT__cpu__DOT__PCWrite) {
        vlSelf->miniRV_SoC__DOT__cpu__DOT__PC = vlSelf->miniRV_SoC__DOT__cpu__DOT__NPC;
    }
}

VL_INLINE_OPT void VminiRV_SoC___024root___nba_comb__TOP__0(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___nba_comb__TOP__0\n"); );
    // Body
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
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcA = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUSrcB = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ExtSel = 1U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__ALUOp = 0U;
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

void VminiRV_SoC___024root___eval_nba(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VminiRV_SoC___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VminiRV_SoC___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VminiRV_SoC___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VminiRV_SoC___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VminiRV_SoC___024root___nba_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
}

void VminiRV_SoC___024root___eval_triggers__act(VminiRV_SoC___024root* vlSelf);

bool VminiRV_SoC___024root___eval_phase__act(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VminiRV_SoC___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VminiRV_SoC___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VminiRV_SoC___024root___eval_phase__nba(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VminiRV_SoC___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__ico(VminiRV_SoC___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__nba(VminiRV_SoC___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__act(VminiRV_SoC___024root* vlSelf);
#endif  // VL_DEBUG

void VminiRV_SoC___024root___eval(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            VminiRV_SoC___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("mySoC/miniRV_SoC.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VminiRV_SoC___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VminiRV_SoC___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("mySoC/miniRV_SoC.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VminiRV_SoC___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("mySoC/miniRV_SoC.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VminiRV_SoC___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VminiRV_SoC___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VminiRV_SoC___024root___eval_debug_assertions(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->fpga_rst & 0xfeU))) {
        Verilated::overWidthError("fpga_rst");}
    if (VL_UNLIKELY((vlSelf->fpga_clk & 0xfeU))) {
        Verilated::overWidthError("fpga_clk");}
}
#endif  // VL_DEBUG
