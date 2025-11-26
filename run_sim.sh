#!/bin/bash

# Unified simulation script for RTL + UVM (Cocotb + Verilator)

MODE=$1

if [ "$MODE" = "rtl" ]; then
    echo "----------------------------------------"
    echo " Running RTL Functional Simulation"
    echo "----------------------------------------"

    mkdir -p build

    iverilog -o build/fifo_sim \
        src/fifo.v \
        tb/fifo_tb.v

    vvp build/fifo_sim
    echo "Simulation complete."

    if [ -f fifo_tb.vcd ]; then
        echo "Opening waveform..."
        gtkwave fifo_tb.vcd &
    fi

elif [ "$MODE" = "uvm" ]; then
    echo "----------------------------------------"
    echo " Running Cocotb + pyuvm Verification"
    echo "----------------------------------------"

    cd sim
    make MODULE=test_fifo_uvm

else
    echo "Usage:"
    echo "  ./run_sim.sh rtl     # Run simple RTL testbench simulation"
    echo "  ./run_sim.sh uvm     # Run Cocotb/pyuvm UVM-style verification"
fi
