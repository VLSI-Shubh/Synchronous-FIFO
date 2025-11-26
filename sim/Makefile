# Language of the top-level HDL
TOPLEVEL_LANG = verilog

# Top-level DUT module name (must match "module fifo" in fifo.v)
TOPLEVEL = fifo

# Name of the Python test module (without .py)
MODULE = test_fifo_smoke

# Path(s) to your Verilog sources
VERILOG_SOURCES = $(PWD)/../rtl/fifo.v

# Use Verilator as the simulator
SIM = verilator

# Optional: enable waveform dump from Verilator
EXTRA_ARGS += --trace-fst

# Include cocotb's Makefile fragment
include $(shell cocotb-config --makefiles)/Makefile.sim
