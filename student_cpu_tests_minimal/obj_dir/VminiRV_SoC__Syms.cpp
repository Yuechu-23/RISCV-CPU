// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC.h"
#include "VminiRV_SoC___024root.h"

// FUNCTIONS
VminiRV_SoC__Syms::~VminiRV_SoC__Syms()
{
}

VminiRV_SoC__Syms::VminiRV_SoC__Syms(VerilatedContext* contextp, const char* namep, VminiRV_SoC* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_miniRV_SoC__cpu__U_DM.configure(this, name(), "miniRV_SoC.cpu.U_DM", "U_DM", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_miniRV_SoC__cpu__U_IM.configure(this, name(), "miniRV_SoC.cpu.U_IM", "U_IM", -9, VerilatedScope::SCOPE_OTHER);
}
