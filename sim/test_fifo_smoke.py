import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge


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
async def fifo_smoke_test(dut):
    """Basic smoke test: write a few values, then read them back."""

    # Create and start a clock: 10 ns period
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())

    # Apply reset
    await reset_dut(dut)

    # Simple write sequence
    values_to_write = [0x11, 0x22, 0x33, 0x44]

    for val in values_to_write:
        # Wait until FIFO is not full
        while int(dut.full.value) == 1:
            await RisingEdge(dut.clk)

        dut.data_in.value = val
        dut.wr.value = 1
        await RisingEdge(dut.clk)
        dut.wr.value = 0

    # Small gap
    for _ in range(3):
        await RisingEdge(dut.clk)

    # Read back values
    read_values = []
    for _ in values_to_write:
        # Wait until FIFO is not empty
        while int(dut.empty.value) == 1:
            await RisingEdge(dut.clk)

        dut.rd.value = 1
        await RisingEdge(dut.clk)
        dut.rd.value = 0

        # Assume data_out valid on next cycle
        await RisingEdge(dut.clk)
        read_values.append(int(dut.data_out.value))

    dut._log.info(f"Wrote : {[hex(v) for v in values_to_write]}")
    dut._log.info(f"Read  : {[hex(v) for v in read_values]}")

    assert read_values == values_to_write, "FIFO did not preserve data order"
