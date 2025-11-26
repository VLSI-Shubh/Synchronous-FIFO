import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

from pyuvm import uvm_root

# Import UVM environment and shared DUT reference
from uvm_env import fifo_tests  # registers FifoBasicTest
from uvm_env import dut_ref     # global holder for DUT handle


async def reset_dut(dut, cycles=5):
    """Apply synchronous reset to the DUT."""
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

    dut._log.info("Starting FIFO UVM basic test")

    # Start clock (10 ns period)
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    # Reset DUT
    await reset_dut(dut)

    # Share DUT handle with UVM components via dut_ref
    dut_ref.dut = dut

    # Run the named UVM test (class FifoBasicTest in uvm_env/fifo_tests.py)
    await uvm_root().run_test("FifoBasicTest")

    dut._log.info("Completed FIFO UVM basic test")

