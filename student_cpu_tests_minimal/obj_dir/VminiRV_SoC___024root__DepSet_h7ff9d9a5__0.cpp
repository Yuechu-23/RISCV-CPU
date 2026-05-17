// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC__Syms.h"
#include "VminiRV_SoC___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__ico(VminiRV_SoC___024root* vlSelf);
#endif  // VL_DEBUG

void VminiRV_SoC___024root___eval_triggers__ico(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VminiRV_SoC___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__act(VminiRV_SoC___024root* vlSelf);
#endif  // VL_DEBUG

void VminiRV_SoC___024root___eval_triggers__act(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->fpga_clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__fpga_clk__0))) 
                                     | ((IData)(vlSelf->fpga_rst) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__fpga_rst__0)))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->fpga_clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__fpga_clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__fpga_clk__0 = vlSelf->fpga_clk;
    vlSelf->__Vtrigprevexpr___TOP__fpga_rst__0 = vlSelf->fpga_rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VminiRV_SoC___024root___dump_triggers__act(vlSelf);
    }
#endif
}
