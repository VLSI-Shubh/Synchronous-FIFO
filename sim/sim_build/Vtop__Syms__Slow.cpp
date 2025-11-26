// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(260);
    // Setup sub module instances
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_fifo = new VerilatedScope{this, "fifo", "fifo", "fifo", -9, VerilatedScope::SCOPE_MODULE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_fifo);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("clk", &(TOP.clk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("data_in", &(TOP.data_in), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("data_out", &(TOP.data_out), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("empty", &(TOP.empty), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("full", &(TOP.full), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rd", &(TOP.rd), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rst", &(TOP.rst), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("wr", &(TOP.wr), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_fifo->varInsert("clk", &(TOP.fifo__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fifo->varInsert("data_in", &(TOP.fifo__DOT__data_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_fifo->varInsert("data_out", &(TOP.fifo__DOT__data_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_fifo->varInsert("depth", const_cast<void*>(static_cast<const void*>(&(TOP.fifo__DOT__depth))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_fifo->varInsert("empty", &(TOP.fifo__DOT__empty), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fifo->varInsert("fifo", &(TOP.fifo__DOT__fifo), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,7 ,7,0);
    __Vscopep_fifo->varInsert("full", &(TOP.fifo__DOT__full), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fifo->varInsert("ptr_depth", const_cast<void*>(static_cast<const void*>(&(TOP.fifo__DOT__ptr_depth))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_fifo->varInsert("rd", &(TOP.fifo__DOT__rd), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fifo->varInsert("rd_ptr", &(TOP.fifo__DOT__rd_ptr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_fifo->varInsert("rst", &(TOP.fifo__DOT__rst), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fifo->varInsert("width", const_cast<void*>(static_cast<const void*>(&(TOP.fifo__DOT__width))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_fifo->varInsert("wr", &(TOP.fifo__DOT__wr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fifo->varInsert("wr_ptr", &(TOP.fifo__DOT__wr_ptr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_fifo);
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_fifo, __Vscopep_fifo = nullptr);
    // Tear down sub module instances
}
