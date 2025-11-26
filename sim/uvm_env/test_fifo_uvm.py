import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

# Correct import for pyuvm 4.x
from pyuvm import ConfigDB, uvm_root

# Import the test class so pyuvm can find it
from uvm_env import fifo_tests


async def reset_dut(dut, cycles=5):
    """Apply reset to DUT."""
    dut.rst.value = 1
    dut.wr.value = 0
    dut.rd.value = 0
    dut.data_in.value = 0

    for _ in range(cycles):
        await RisingEdge(dut.clk)

    dut.rst.value = 0
    await RisingEdge(dut.clk)


@cocotb.test()
async def run_fifo_basic_uvm_test(dut):
    """
    Top-level cocotb test that launches the pyuvm FifoBasicTest.
    """

    # Start clock
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    # Reset DUT
    await reset_dut(dut)

    # Put DUT handle into ConfigDB so driver and monitor can access it
    ConfigDB().set(None, "*", "DUT", dut)

    # Run the named UVM test
    await uvm_root().run_test("FifoBasicTest")

