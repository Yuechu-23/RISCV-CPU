// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMINIRV_SOC__SYMS_H_
#define VERILATED_VMINIRV_SOC__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VminiRV_SoC.h"

// INCLUDE MODULE CLASSES
#include "VminiRV_SoC___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VminiRV_SoC__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VminiRV_SoC* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VminiRV_SoC___024root          TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_miniRV_SoC__cpu__U_DM;
    VerilatedScope __Vscope_miniRV_SoC__cpu__U_IM;

    // CONSTRUCTORS
    VminiRV_SoC__Syms(VerilatedContext* contextp, const char* namep, VminiRV_SoC* modelp);
    ~VminiRV_SoC__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
