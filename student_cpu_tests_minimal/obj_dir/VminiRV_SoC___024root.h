// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VminiRV_SoC.h for the primary calling header

#ifndef VERILATED_VMINIRV_SOC___024ROOT_H_
#define VERILATED_VMINIRV_SOC___024ROOT_H_  // guard

#include "verilated.h"


class VminiRV_SoC__Syms;

class alignas(VL_CACHE_LINE_BYTES) VminiRV_SoC___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(fpga_rst,0,0);
    VL_IN8(fpga_clk,0,0);
    CData/*0:0*/ miniRV_SoC__DOT__cpu__DOT__ExtSel;
    VL_OUT8(debug_wb_have_inst,0,0);
    VL_OUT8(debug_wb_ena,0,0);
    VL_OUT8(debug_wb_reg,4,0);
    CData/*0:0*/ miniRV_SoC__DOT__cpu__DOT__RFWrite;
    CData/*0:0*/ miniRV_SoC__DOT__cpu__DOT__DMCtrl;
    CData/*0:0*/ miniRV_SoC__DOT__cpu__DOT__PCWrite;
    CData/*0:0*/ miniRV_SoC__DOT__cpu__DOT__IRWrite;
    CData/*0:0*/ miniRV_SoC__DOT__cpu__DOT__InsMemRW;
    CData/*0:0*/ miniRV_SoC__DOT__cpu__DOT__ALUSrcA;
    CData/*0:0*/ miniRV_SoC__DOT__cpu__DOT__AWrite;
    CData/*0:0*/ miniRV_SoC__DOT__cpu__DOT__BWrite;
    CData/*0:0*/ miniRV_SoC__DOT__cpu__DOT__ALUOutWrite;
    CData/*1:0*/ miniRV_SoC__DOT__cpu__DOT__ALUSrcB;
    CData/*1:0*/ miniRV_SoC__DOT__cpu__DOT__NPCOp;
    CData/*1:0*/ miniRV_SoC__DOT__cpu__DOT__WDSel;
    CData/*1:0*/ miniRV_SoC__DOT__cpu__DOT__RegSel;
    CData/*3:0*/ miniRV_SoC__DOT__cpu__DOT__ALUOp;
    CData/*4:0*/ miniRV_SoC__DOT__cpu__DOT__WR;
    CData/*0:0*/ miniRV_SoC__DOT__cpu__DOT__commit_now;
    CData/*3:0*/ miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__state;
    CData/*0:0*/ __Vdlyvset__miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register__v0;
    CData/*4:0*/ __Vdlyvdim0__miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register__v1;
    CData/*0:0*/ __Vdlyvset__miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register__v1;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__fpga_clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__fpga_rst__0;
    CData/*0:0*/ __VactContinue;
    SData/*11:0*/ miniRV_SoC__DOT__cpu__DOT____Vcellinp__U_MUX_3to1_B__Z;
    SData/*9:0*/ miniRV_SoC__DOT__cpu__DOT__U_ControlUnit__DOT__funct_all;
    VL_OUT(debug_wb_pc,31,0);
    VL_OUT(debug_wb_value,31,0);
    IData/*31:0*/ miniRV_SoC__DOT__cpu__DOT__PC;
    IData/*31:0*/ miniRV_SoC__DOT__cpu__DOT__NPC;
    IData/*31:0*/ miniRV_SoC__DOT__cpu__DOT__in_ins;
    IData/*31:0*/ miniRV_SoC__DOT__cpu__DOT__out_ins;
    IData/*31:0*/ miniRV_SoC__DOT__cpu__DOT__Imm32;
    IData/*31:0*/ miniRV_SoC__DOT__cpu__DOT__WD;
    IData/*31:0*/ miniRV_SoC__DOT__cpu__DOT__RD1;
    IData/*31:0*/ miniRV_SoC__DOT__cpu__DOT__RD1_r;
    IData/*31:0*/ miniRV_SoC__DOT__cpu__DOT__RD2_r;
    IData/*31:0*/ miniRV_SoC__DOT__cpu__DOT__A;
    IData/*31:0*/ miniRV_SoC__DOT__cpu__DOT__B;
    IData/*31:0*/ miniRV_SoC__DOT__cpu__DOT__ALU_result;
    IData/*31:0*/ miniRV_SoC__DOT__cpu__DOT__ALU_result_r;
    IData/*31:0*/ miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__i;
    IData/*31:0*/ miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__mem_file;
    IData/*31:0*/ miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__rd_reg;
    IData/*31:0*/ miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__i;
    IData/*31:0*/ miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__mem_file;
    IData/*31:0*/ __Vdlyvval__miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register__v1;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 1024> miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__memory;
    VlUnpacked<IData/*31:0*/, 1024> miniRV_SoC__DOT__cpu__DOT__U_IM__DOT__mem_rd;
    VlUnpacked<IData/*31:0*/, 32> miniRV_SoC__DOT__cpu__DOT__U_RF__DOT__register;
    VlUnpacked<IData/*31:0*/, 1024> miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__memory;
    VlUnpacked<IData/*31:0*/, 1024> miniRV_SoC__DOT__cpu__DOT__U_DM__DOT__mem_rd;
    VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    VminiRV_SoC__Syms* const vlSymsp;

    // CONSTRUCTORS
    VminiRV_SoC___024root(VminiRV_SoC__Syms* symsp, const char* v__name);
    ~VminiRV_SoC___024root();
    VL_UNCOPYABLE(VminiRV_SoC___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
