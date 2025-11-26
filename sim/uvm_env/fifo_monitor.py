from pyuvm import uvm_component, uvm_analysis_port
from cocotb.triggers import RisingEdge

from .fifo_item import FifoOp
from . import dut_ref


class FifoMonitor(uvm_component):
    """
    Passive monitor:
      - Observes wr, rd, data_in, data_out, full, empty
      - Sends events to analysis port for scoreboard / coverage
    """

    def __init__(self, name, parent):
        super().__init__(name, parent)
        self.ap = uvm_analysis_port("ap", self)
        self.dut = None

    def build_phase(self):
        super().build_phase()
        self.dut = dut_ref.dut
        if self.dut is None:
            raise RuntimeError("FifoMonitor: dut_ref.dut is None. Did cocotb set it?")


    async def run_phase(self):
        self.logger.info("FifoMonitor running")
        dut = self.dut

        # Track previous-cycle read signals for 1-cycle-late data_out
        prev_rd = 0
        prev_empty = 1

        while True:
            # Wait for next clock edge
            await RisingEdge(dut.clk)

            # Current signals
            curr_wr = int(dut.wr.value)
            curr_full = int(dut.full.value)
            curr_rd = int(dut.rd.value)
            curr_empty = int(dut.empty.value)
            curr_data_in = int(dut.data_in.value)
            curr_data_out = int(dut.data_out.value)

            # WRITE event (current cycle)
            if curr_wr == 1 and curr_full == 0:
                ev = {"op": FifoOp.WRITE, "data": curr_data_in}
                self.ap.write(ev)

            # READ event: rd was asserted last cycle and FIFO was not empty then.
            # Data for that read is visible at data_out in *this* cycle.
            if prev_rd == 1 and prev_empty == 0:
                ev = {"op": FifoOp.READ, "data": curr_data_out}
                self.ap.write(ev)

            # Update previous-cycle state
            prev_rd = curr_rd
            prev_empty = curr_empty
