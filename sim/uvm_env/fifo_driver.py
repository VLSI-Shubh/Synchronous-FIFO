from pyuvm import uvm_driver
from cocotb.triggers import RisingEdge

from .fifo_item import FifoItem, FifoOp
from . import dut_ref


class FifoDriver(uvm_driver):
    """
    FIFO Driver:
      - For WRITE items: wait for !full, drive data_in + wr pulse
      - For READ items:  wait for !empty, drive rd pulse
    """

    def __init__(self, name, parent):
        super().__init__(name, parent)
        self.dut = None

    def build_phase(self):
        super().build_phase()
        # Get DUT handle from shared module set by cocotb
        self.dut = dut_ref.dut
        if self.dut is None:
            raise RuntimeError("FifoDriver: dut_ref.dut is None. Did cocotb set it?")

    async def run_phase(self):
        self.logger.info("FifoDriver starting run_phase")

        while True:
            item: FifoItem = await self.seq_item_port.get_next_item()
            self.logger.info(f"Driving item: {item}")

            if item.op == FifoOp.WRITE:
                # Wait until FIFO not full
                while int(self.dut.full.value) == 1:
                    await RisingEdge(self.dut.clk)

                # Drive write
                self.dut.data_in.value = item.data
                self.dut.wr.value = 1
                await RisingEdge(self.dut.clk)
                self.dut.wr.value = 0

            elif item.op == FifoOp.READ:
                # Wait until FIFO not empty
                while int(self.dut.empty.value) == 1:
                    await RisingEdge(self.dut.clk)

                # Drive read
                self.dut.rd.value = 1
                await RisingEdge(self.dut.clk)
                self.dut.rd.value = 0

            else:
                self.logger.error(f"Unknown operation in FifoItem: {item.op}")

            # Indicate we are done
            self.seq_item_port.item_done()
