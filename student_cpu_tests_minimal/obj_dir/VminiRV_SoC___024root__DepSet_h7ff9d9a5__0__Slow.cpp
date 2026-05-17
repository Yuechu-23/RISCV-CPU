// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC__Syms.h"
#include "VminiRV_SoC___024root.h"

VL_ATTR_COLD void VminiRV_SoC___024root___eval_initial__TOP(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_5;
    // Body
    vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i)) {
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__memory[(0x3ffU 
                                                              & vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i)] = 0U;
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__mem_rd[(0x3ffU 
                                                              & vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i)] = 0U;
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i 
            = ((IData)(1U) + vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i);
    }
    __Vtemp_2[0U] = 0x2e62696eU;
    __Vtemp_2[1U] = 0x696e6974U;
    __Vtemp_2[2U] = 0x6d656dU;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__mem_file 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(3, __Vtemp_2)
                      , std::string{"r"});
    ;
    if (VL_UNLIKELY((0U == vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__mem_file))) {
        VL_WRITEF("[ERROR] IM open file meminit.bin failed\n[%0t] %%Fatal: IM.v:29: Assertion failed in %NminiRV_SoC.cpu.U_IM\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("mySoC/IM.v", 29, "");
    }
    VL_WRITEF("[INFO] IM initialized with meminit.bin\n");
    (void)VL_FREAD_I(32,0,1024, &(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__mem_rd)
                     , vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__mem_file
                     , 0, 1024);
    VL_FCLOSE_I(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__mem_file); vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i)) {
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__memory[(0x3ffU 
                                                              & vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i)] 
            = ((vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__mem_rd
                [(0x3ffU & vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i)] 
                << 0x18U) | ((0xff0000U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__mem_rd
                                           [(0x3ffU 
                                             & vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i)] 
                                           << 8U)) 
                             | ((0xff00U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__mem_rd
                                            [(0x3ffU 
                                              & vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i)] 
                                            >> 8U)) 
                                | (vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__mem_rd
                                   [(0x3ffU & vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i)] 
                                   >> 0x18U))));
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i 
            = ((IData)(1U) + vlSelf->miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i);
    }
    vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__rd_reg = 0U;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i)) {
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory[(0x3ffU 
                                                              & vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i)] = 0U;
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__mem_rd[(0x3ffU 
                                                              & vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i)] = 0U;
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i 
            = ((IData)(1U) + vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i);
    }
    __Vtemp_5[0U] = 0x2e62696eU;
    __Vtemp_5[1U] = 0x696e6974U;
    __Vtemp_5[2U] = 0x6d656dU;
    vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__mem_file 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(3, __Vtemp_5)
                      , std::string{"r"});
    ;
    if (VL_UNLIKELY((0U == vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__mem_file))) {
        VL_WRITEF("[ERROR] DM open file meminit.bin failed\n[%0t] %%Fatal: DM.v:37: Assertion failed in %NminiRV_SoC.cpu.U_DM\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("mySoC/DM.v", 37, "");
    }
    VL_WRITEF("[INFO] DM initialized with meminit.bin\n");
    (void)VL_FREAD_I(32,0,1024, &(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__mem_rd)
                     , vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__mem_file
                     , 0, 1024);
    VL_FCLOSE_I(vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__mem_file); vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i)) {
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory[(0x3ffU 
                                                              & vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i)] 
            = ((vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__mem_rd
                [(0x3ffU & vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i)] 
                << 0x18U) | ((0xff0000U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__mem_rd
                                           [(0x3ffU 
                                             & vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i)] 
                                           << 8U)) 
                             | ((0xff00U & (vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__mem_rd
                                            [(0x3ffU 
                                              & vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i)] 
                                            >> 8U)) 
                                | (vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__mem_rd
                                   [(0x3ffU & vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i)] 
                                   >> 0x18U))));
        vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i 
            = ((IData)(1U) + vlSelf->miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__stl(VminiRV_SoC___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VminiRV_SoC___024root___eval_triggers__stl(VminiRV_SoC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VminiRV_SoC___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
