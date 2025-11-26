// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    bufp->chgCData(oldp+0,(vlSelfRef.data_in),8);
    bufp->chgBit(oldp+1,(vlSelfRef.clk));
    bufp->chgBit(oldp+2,(vlSelfRef.rst));
    bufp->chgBit(oldp+3,(vlSelfRef.rd));
    bufp->chgBit(oldp+4,(vlSelfRef.wr));
    bufp->chgCData(oldp+5,(vlSelfRef.data_out),8);
    bufp->chgBit(oldp+6,(vlSelfRef.full));
    bufp->chgBit(oldp+7,(vlSelfRef.empty));
    bufp->chgCData(oldp+8,(vlSelfRef.fifo__DOT__data_in),8);
    bufp->chgBit(oldp+9,(vlSelfRef.fifo__DOT__clk));
    bufp->chgBit(oldp+10,(vlSelfRef.fifo__DOT__rst));
    bufp->chgBit(oldp+11,(vlSelfRef.fifo__DOT__rd));
    bufp->chgBit(oldp+12,(vlSelfRef.fifo__DOT__wr));
    bufp->chgCData(oldp+13,(vlSelfRef.fifo__DOT__data_out),8);
    bufp->chgBit(oldp+14,(vlSelfRef.fifo__DOT__full));
    bufp->chgBit(oldp+15,(vlSelfRef.fifo__DOT__empty));
    bufp->chgCData(oldp+16,(vlSelfRef.fifo__DOT__fifo[0]),8);
    bufp->chgCData(oldp+17,(vlSelfRef.fifo__DOT__fifo[1]),8);
    bufp->chgCData(oldp+18,(vlSelfRef.fifo__DOT__fifo[2]),8);
    bufp->chgCData(oldp+19,(vlSelfRef.fifo__DOT__fifo[3]),8);
    bufp->chgCData(oldp+20,(vlSelfRef.fifo__DOT__fifo[4]),8);
    bufp->chgCData(oldp+21,(vlSelfRef.fifo__DOT__fifo[5]),8);
    bufp->chgCData(oldp+22,(vlSelfRef.fifo__DOT__fifo[6]),8);
    bufp->chgCData(oldp+23,(vlSelfRef.fifo__DOT__fifo[7]),8);
    bufp->chgCData(oldp+24,(vlSelfRef.fifo__DOT__wr_ptr),4);
    bufp->chgCData(oldp+25,(vlSelfRef.fifo__DOT__rd_ptr),4);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Locals
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
