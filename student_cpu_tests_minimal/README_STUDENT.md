# Student CPU Test Package

This package is a minimal Verilator-based difftest environment for a RISC-V
RV32I CPU. It contains binary tests, a C golden model, a Verilator C++ harness,
test memories, and a `miniRV_SoC` top module used as the student CPU wrapper.

## Requirements

Use Linux or WSL. Required tools:

```bash
make
verilator
g++
python3
```

On Windows, if the tools are installed in WSL, run commands through `wsl`.

## Quick Start

Build and run one test:

```bash
make run TEST=addi
```

Build once, then run all tests:

```bash
make build
python3 run_all_tests.py
```

Clean generated files:

```bash
make clean
```

## After Changing CPU Code

If you modify any Verilog/SystemVerilog CPU source under `mySoC/`, rebuild the
Verilator simulator before rerunning tests:

```bash
make clean
make build
python3 run_all_tests.py
```

For a quick single-test check after editing CPU code, use:

```bash
make run TEST=addi
```

`make run` rebuilds when source files are newer than the simulator binary, then
runs the selected test. If results look stale or unexpected, run `make clean`
first to remove old `obj_dir/`, `waveform/`, and `meminit.bin` files.

Do not use only `python3 run_all_tests.py` after changing CPU code unless you
have already rebuilt with `make build`. The Python script calls
`make run_for_python`, which expects `obj_dir/VminiRV_SoC` to already exist and
does not perform a full rebuild.

Example from Windows PowerShell:

```powershell
wsl bash -lc "cd /mnt/c/path/to/student_cpu_tests_selfcpu && make build && python3 run_all_tests.py"
```

## How The Test Works

The Verilator top module is fixed to:

```verilog
module miniRV_SoC (...);
```

The C++ harness resets the RTL CPU, ticks the clock, and reads the commit
debug interface each cycle. When `debug_wb_have_inst` is `1`, the golden model
executes one instruction and compares:

```text
debug_wb_pc
debug_wb_ena
debug_wb_reg
debug_wb_value
```

If any field differs, the test prints a `[difftest] Test Failed!` report.
Passing tests stop at `ecall` and print `Test Point Pass!`.

## Connecting A Student CPU

Put the student's Verilog/SystemVerilog files under:

```text
mySoC/
```

Keep `mySoC/miniRV_SoC.sv` as the top-level wrapper, or replace its internals
while preserving the module name and ports. Instantiate the student's CPU in
that wrapper and connect it to:

```text
fpga_clk
fpga_rst, active high
IROM instruction address/data
DRAM data address/read/write
debug_wb_* commit signals
```

The required top-level debug signals are:

```verilog
debug_wb_have_inst  // 1 when one valid instruction commits this cycle
debug_wb_pc         // committed instruction PC
debug_wb_ena        // register-file write enable of the committed instruction
debug_wb_reg        // destination register number
debug_wb_value      // value written to the register file
```

For a single-cycle CPU, `debug_wb_have_inst` can usually be `1` after reset.
For a pipelined CPU, stall, bubble, and flushed cycles must report
`debug_wb_have_inst = 0`; otherwise the golden model will advance too many
instructions.

Note: this package's `vsrc/ram.v` has a 1-bit DRAM write enable. If the CPU has
byte-enable stores, either adapt them in `miniRV_SoC.sv` with read-modify-write
logic, or replace the RAM/wrapper consistently.

## Files

```text
Makefile
  Verilator build and run rules.

run_all_tests.py
  Runs every .bin test in bin/.

bin/
  Prebuilt RISC-V binary test programs.

csrc/dut.h
csrc/test.cpp
  Verilator testbench wrapper and difftest driver.

golden_model/
  C reference model used for instruction-level comparison.

vsrc/ram.v
  IROM and DRAM models. Both load the selected bin file through meminit.bin.

mySoC/miniRV_SoC.sv
  Student integration top module. This package includes a simple verified
  single-cycle RV32I CPU example inside this file.
```

## Generated Files

These are created by running tests and are not needed in a clean handout:

```text
obj_dir/
waveform/
meminit.bin
```

## Verified Example

The included example CPU in `mySoC/miniRV_SoC.sv` was checked with:

```bash
make build
python3 run_all_tests.py
```

All tests in `bin/` passed:

```text
add, addi, and, andi, auipc, beq, bge, bgeu, blt, bltu, bne, jal, jalr,
lb, lbu, lh, lhu, lui, lw, or, ori, sb, sh, simple, sll, slli, slt,
slti, sltiu, sltu, sra, srai, srl, srli, start, sub, sw, xor, xori
```
