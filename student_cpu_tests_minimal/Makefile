VSRC = $(wildcard vsrc/ram.v mySoC/*)
CSRC = $(wildcard golden_model/*.c) $(wildcard golden_model/stage/*.c) $(wildcard golden_model/peripheral/*.c) $(wildcard csrc/*.c csrc/*.cpp)
SIM_OPTS = --trace -Wno-lint -Wno-style -Wno-TIMESCALEMOD
# add sub xor or and sll srl sra slt sltu 
# addi xori ori andi slli srli srai slti sltiu
# lb lh lw lbu lhu
# sb sh sw
# beq bne blt bge   ## bltu bgeu 
# jal   			## jalr
# lui auipc
# ecall ebreak
TEST = addi
TESTFILE = meminit.bin
PWD = $(shell pwd)

build: $(VSRC) $(CSRC)
	@verilator -cc --exe --build $(VSRC) --top-module miniRV_SoC $(CSRC) $(SIM_OPTS) +define+PATH=$(TESTFILE) -CFLAGS "-DPATH=$(TESTFILE) -std=c++14" -ImySoC -CFLAGS -I$(PWD)/golden_model/include
	@mkdir -p waveform
run: build
	@ln -sf bin/$(TEST).bin $(TESTFILE)
	@./obj_dir/VminiRV_SoC $(TEST)
run_for_python:  # should run "make all" first, for python-based test
	@ln -sf bin/$(TEST).bin $(TESTFILE)
	@./obj_dir/VminiRV_SoC $(TEST)
	@rm -rf $(TESTFILE)
$(TESTFILE):
	ln -sf bin/$(TEST).bin $(TESTFILE)
clean:
	rm -rf obj_dir waveform $(TESTFILE)

.PHONY: run debug clean
