# Compilaton level: -O0, -O1, -O2, ...
# -O0 : No optimizations
# -O1 : Optimized debug binaries, don't change the execution order but remove
#       dead code and stuff
# -Os : Optimize, but don't run passes that could blow up code. Try to be a bit
#       more drastic when removing code.
# -O2 : Optimized build, but should not explode in code size nor consume all
#       resources while compiling
# -O3 : Do every optimization
# -Oz : Only perform optimizations that reduce code size. Don't even try to run
#       things that could potentially increase code size
#OPTIMIZE:= -O0 -g
OPTIMIZE:= -O3

# Macro definitions
# Example) -D HOST_MODE
MACRO_DEFINES:=
#WERROR_FLAG=-Werror

# Compilation options
# -mllvm -enable-aa-sched-mi        : Enable use of AA during MI GAD construction
# -mllvm -enable-bundle-compression : Enable bundle compression
# -mllvm -allow-cga                 : Allow CGA mapping
# -DCONFIG_ARCH_BERN                : This is necessary for the use of DMA
# -Werror								: Turn all warnings into errors
COMPILE_OPTIONS= \
					-mllvm -enable-aa-sched-mi \
					-mllvm -enable-bundle-compression \
					-mllvm -enable-bundle-nop-compression \
					-mllvm -enable-multi-cycle-nop \
					$(WERROR_FLAG) 

# User defined symbols
# Here define the application specific address
# If you want to set an address of a symbol, define it below.
# Example) -defsym=input_image=0x4000
USER_SYM_DEF=

# User defined include
# Add the pathes of the header files if you want
SCC_INC:=

# Exclude directory for compilation
# Write the directory name that you want to exclude in compilation
# Delimiter is '|'.
# For example, if you want to exclude a and b, SCC_EXCLUDES=a|b.
SCC_EXCLUDES:=params

# User defined library path
# Add the libraries and their paths if you want.
USER_LIBS:=

# Output directory definition
OUTPUT_DIR=.

## The following line uses the default linker script
# Inside linker script, you can manipulate not only the location of sections but
# also the memory layout of variables. In order to make some changes for specific
# application, please copy the defaule linker script, change the linker script,
# and change a line below (LINKER_SCRIPT).
# YOU SHOULD NOT MODIFY THE SYSTEM SYMBOLS IN LINKER SCRIPT WITHOUT DISCUSING SYSTEM DEVELOPERS
LINKER_SCRIPT= $(SRPSDK_INSTALL)/share/arch/$(TARGET)/system/$(TARGET_SYS)/$(LDSCRIPT_NAME)

# Option for system linker (scc.ld)
# As it is impossible to make a comment inside linker script, here we have
# the example of linker script description.
# The content of linker script is like this:
#
# SECTIONS {
#   /// Syntax of variable layout
#   /// EXAMPLE) the layout of 'int test_var[100] = {0};' at 0x20001010
#   /// .symbol.test_var 0x20001010 { *(.dta.test_var) }
#   /// The line below is another example.
#   .symbol.input_image 0x20150000 :		/// User defined variable layout.
#     {
#       *(.data.input_image)
#     }
#
#   /// YOU SHOULD BE VERY CAREFUL WHEN YOU CHANGE THE LINE BELOW.
#   .SRP.FLIH 0x0 :    /// Boot code at 0x0
#     AT(0x0)          /// Boot code load address 0x0
#     {
#       *(.SRP.FLIH)
#     }
#   .text 0x10000 :    /// Program code at 0x10000
#     AT( ADDR(.SRP.FLIH) + SIZEOF(.SRP.FLIH) )
#     {
#       *(.text)
#     }
#   .data 0x0 :        /// Program data at 0x0
#     AT( ADDR(.text) + SIZEOF(.text) ) ALIGN(16)   /// 16 bytes alignment
#     {
#       *(.data) *(.data.*)
#     }
#   .bss :             /// Uninitialized data right after .data
#     AT( ADDR(.data) + SIZEOF(.data) ) ALIGN(16)
#     {
#       *(.bss) *(.tbss) *(.common)
#     }
#   .cga 0x0 :         /// CGRA configuration memory at 0x0
#     AT( ADDR(.bss) + SIZEOF(.bss) ) ALIGN(1)
#     {
#       *(.cga)
#     }
# }

# Include the appropriate makefile.conf
# DO NOT REMOVE THE BELOW.
################################################################################
################################################################################
# YOU HAVE TO BE CAREFUL TO MAKE A MODIFICATION BELOW
################################################################################
################################################################################

# Target name
# srp3c : SRP3C
# srp3s : Slim SRP
# srp4m : SRP4 (vector architecture)
TARGET=srp4m

# Target system
# default : Default system
TARGET_SYS=sim

# Compile macro definitions
# -D__srp__          		: This is necessary for newlib
# -D__ELF__          		: This is necessary for newlib
COMPILE_MACRO_DEFINES= \
					-D__srp__ \
					-D__ELF__

# System dependent macro definitions
# -DCONFIG_ARCH_BERN 		: This is necessary for DMA as we reuse BERN DMA code.
# FIXME: CONFIG_ARCH_BERN is temporarily used for Slim SRP even
# though there is no DMA module in Slim SRP. It is necessary to
# clean up the related codes.
SYSTEM_MACRO_DEFINES= \
					-DCONFIG_ARCH_BERN

# Tools to be used
SCC=$(SRPSDK_INSTALL)/bin/scc
SCC_LD=$(SRPSDK_INSTALL)/bin/scc.ld
SCC_AR=ar
MRPSIM=$(MRPSIM_PATH)/bin/mRPsim
CC=gcc
LD=gcc
STD=gnu89
EXE=a.out

# All compilation options
# -fdata-sections				: Place each data in its own section
# -fno-vectorize				: Disable the loop vectorization passes
# -fno-slp-vectorize		: Disable the superword level parallelism vectorization passes
# -fno-zero-initialized-in-bss : 
# -mllvm -isolated-vmem	: Generate code by considering separate vector SPM (SRP4 only)
# -mllvm -enable-aa-sched-mi : Enable use of AA during MI GAD construction
# -mllvm -enable-bundle-nop-compression : Enable bundle nop compression
# -mllvm -enable-bundle-compression : Enable bundle compression
# -mllvm -enable-multi-cycle-nop : Enable multiple cycle nop instruction (compression)
# -std=gnu89						: Use gnu89 style language extension
# -Werror								: Turn all warnings into errors

# Default compiler options
OPTIONS= \
					-fdata-sections \
					-fno-vectorize \
					-fno-slp-vectorize \
					-fno-zero-initialized-in-bss \
					-std=$(STD) \
					$(COMPILE_MACRO_DEFINES) \
					$(SYSTEM_MACRO_DEFINES) \
					$(COMPILE_OPTIONS)

# Options for newlib compilation
# The compilation option for newlib is grouped separately. This is also used
# by SCC_CFLAGS. In 'buildNewlib.sh' the order of compilation option should not be
# changed. If so, there might be compilation problem.
NEWLIB_COMPILE_OPTIONS= -srp-subtarget $(TARGET) $(MACRO_DEFINES)

# Options for compiler (scc)
SCC_CFLAGS= $(NEWLIB_COMPILE_OPTIONS) $(OPTIMIZE) $(OPTIONS) -g

# Options for compiling assembly files (scc)
SCC_ASFLAGS= -c $(OPTIMIZE) -srp-subtarget $(TARGET)

# Options for creating archive (ar)
SCC_ARFLAGS= r

# Essential symbols for compilation
# YOU SHOULD NOT MODIFY THIS WITHOUT DISCUSING COMPILER DEVELOPERS
COMPILER_SYM_DEF=

# Essential symbols for system
# YOU SHOULD NOT MODIFY THIS WITHOUT DISCUSING SYSTEM DEVELOPERS
# -defsym : Symbol address
# -defsym=DMAC_CONF=0xf200 				: DMA configuration
# -defsym=DMAC_EN_CH=0xf2004			: DMA channel enable
# -defsym=DMAC_INT_STAT=0xf2010		: DMA conf
# -defsym=DMAC_INT_RSTAT=0xf2014	: DMA conf
# -defsym=DMAC_INT_CL=0xf2018			: DMA conf
# -defsym=DMAC_CH_REGS=0xf2100		: DMA channel registers
SYSTEM_SYM_DEF= \
					-defsym=_SRP_USER_STACK_ADDR_=0x07000000 \
					-defsym=_SRP_INTERRUPT_STACK_ADDR_=0x08000000 \
					-defsym=__HAL_L1_BEGIN=0x0 \
					-defsym=__HAL_L1_END=0x08000000 \
					-defsym=__HAL_L1_VECTOR_BEGIN=0x0 \
					-defsym=__HAL_L1_VECTOR_END=0x08000000 \
					-defsym=SER_UART=0xA000FFD4 \
					-defsym=SER_UART_HALF_FULL=0xA000FFD4 \
					-defsym=SER_UART_DBG=0xA000FFD8 \
					-defsym=DMAC_CONF=0x32000 \
					-defsym=DMAC_EN_CH=0x32004 \
					-defsym=DMAC_INT_STAT=0x32010 \
					-defsym=DMAC_INT_RSTAT=0x32014 \
					-defsym=DMAC_INT_CL=0x32018 \
					-defsym=DMAC_CH_REGS=0x32100

# Essential symbols
SYM_DEF= \
					$(COMPILER_SYM_DEF) \
					$(SYSTEM_SYM_DEF) \
					$(USER_SYM_DEF)

# Options for system linker (scc.ld)
SCC_LDFLAGS= -T $(LINKER_SCRIPT) $(SYM_DEF) -gc-sections

# Header file path for compile
# Add the pathes of the header files if you want
# Why is it recommended to cut off all the dependencies between hal and the other files?
# Why is the smk include in hal not good?
#  There is one problem. If someone wants to use hal directly, it is inevitable to
#  use smk as well because hal uses smk's header files. This increases the code size
# YOU SHOULD NOT MODIFY THIS WITHOUT DISCUSSING COMPILER DEVELOPERS AND SYSTEM DEVELOPERS
LIBRARY_INC:= \
					-I $(SRPSDK_SRC)/library/compiler-rt \
					-I $(SRPSDK_SRC)/library/smk \
					-I $(SRPSDK_SRC)/arch/common \
					-I $(SRPSDK_SRC)/arch/$(TARGET)/etc \
					-I $(SRPSDK_SRC)/arch/$(TARGET)/hal \
					-I $(SRPSDK_SRC)/arch/$(TARGET)/system/$(TARGET_SYS)/src \
					-I $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/musl/include \
					-include $(SRPSDK_SRC)/arch/$(TARGET)/etc/srp_vector.h

# Essential header include path
# YOU SHOULD NOT MODIFY THIS WITHOUT DISCUSSING COMPILER DEVELOPERS
SYSTEM_INC:= \
					-I $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/common \
					-I $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/compiler-rt \
					-I $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/etc \
					-I $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/hal \
					-I $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/newlib/srp-elf/include \
					-I $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/smk \
					-I $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/startup \
					-I $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/system \
					-include $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/etc/srp_vector.h \
					-include $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/common/legacy.h

# Essential libraries such as HAL
# YOU SHOULD NOT MODIFY THIS WITHOUT DISCUSSING COMPILER DEVELOPERS AND SYSTEM DEVELOPERS
SYSTEM_LIBS:= \
					-L $(SRPSDK_INSTALL)/lib/arch/$(TARGET)/system/$(TARGET_SYS)/common \
					-L $(SRPSDK_INSTALL)/lib/arch/$(TARGET)/system/$(TARGET_SYS)/compiler-rt \
					-L $(SRPSDK_INSTALL)/lib/arch/$(TARGET)/system/$(TARGET_SYS)/etc \
					-L $(SRPSDK_INSTALL)/lib/arch/$(TARGET)/system/$(TARGET_SYS)/hal \
					-L $(SRPSDK_INSTALL)/lib/arch/$(TARGET)/system/$(TARGET_SYS)/newlib \
					-L $(SRPSDK_INSTALL)/include/arch/srp4m/system/sim/musl/lib \
					-L $(SRPSDK_INSTALL)/include/arch/srp4m/system/sim/musl \
					-L $(SRPSDK_INSTALL)/lib/arch/$(TARGET)/system/$(TARGET_SYS)/smk \
					-L $(SRPSDK_INSTALL)/lib/arch/$(TARGET)/system/$(TARGET_SYS)/system \
					-lc -lcrypt  -ldl  -lm  -lresolv  -lrt  -lutil  -lsrp\
					-start-group -lcommon -lcompiler-rt -letc -lhal -lc -lm -lsrp -lsmk -lsystem -end-group

STARTUP_OBJS:= \
					$(SRPSDK_INSTALL)/lib/arch/$(TARGET)/system/$(TARGET_SYS)/startup/crt0.o \
					$(SRPSDK_INSTALL)/lib/arch/$(TARGET)/system/$(TARGET_SYS)/startup/isr.o

SCC_INC+=$(shell find . -type d | grep -v "\.svn" | grep -v -E "' '|$(SCC_EXCLUDES)" | sed -e "s/^./-I ./")
SRCS:=$(shell find . -name "*.c" | grep -v -E "' '|$(SCC_EXCLUDES)")
SRC_ASMS:=$(patsubst %c,%s,$(SRCS))
ASMS:=$(shell find . -name "*.s" | grep -v -E "' '|$(SCC_EXCLUDES)")
OBJS:=$(patsubst %c,%o,$(SRCS))
ASM_OBJS:=$(patsubst %s,%o,$(ASMS))
SCC_LIBS:=$(USER_LIBS) $(SYSTEM_LIBS)

MODE:=CROSS_COMPILE
TARGET_BIN=$(OUTPUT_DIR)/$(EXE)
LDSCRIPT_NAME=ldscript
ifeq ($(findstring -g, $(OPTIMIZE)), -g)
  LDSCRIPT_NAME:=$(LDSCRIPT_NAME).dbg
endif

%.o: %.c
ifeq ($(MODE), HOST_COMPILE)
	$(CC) -c -g -O0 -o $@ $< $(SCC_INC) $(LIBRARY_INC)
else
ifeq ($(LIBGEN), TRUE)
	$(SCC) -c $(SCC_CFLAGS) -o $@ $< $(SCC_INC) $(LIBRARY_INC)
else
	$(SCC) -c $(SCC_CFLAGS) -o $@ $< $(SCC_INC) $(SYSTEM_INC)
endif
endif

%.s : %.c
	$(SCC) -S $(SCC_CFLAGS) -o $@ $< $(SCC_INC) $(SYSTEM_INC)

%.o : %.s
	$(SCC) $(SCC_ASFLAGS) -o $@ $<

.PHONY: lib clean dis sym run help asm

print-%:
	@echo $($*)

out: $(TARGET_BIN)

$(TARGET_BIN): $(OBJS) $(ASM_OBJS)
	$(SCC_LD) -o $(OUTPUT_DIR)/$(EXE) $(SCC_LDFLAGS) $(STARTUP_OBJS) $(OBJS) $(ASM_OBJS) $(SCC_LIBS)

asm: $(SRC_ASMS)

lib: $(OBJS) $(ASM_OBJS)
	$(SCC_AR) $(SCC_ARFLAGS) lib $(OBJS) $(ASM_OBJS)

run: $(OUTPUT_DIR)/$(EXE)
	$(MRPSIM) --command cmd

dis:
	scc-objdump -disassemble -g -triple=srp-$(TARGET)-xx $(OUTPUT_DIR)/$(EXE)

sym:
	readelf -s $(OUTPUT_DIR)/$(EXE)

host: $(OBJS)
	$(LD) -o host $(OBJS)

clean::
	rm -f $(OUTPUT_DIR)/$(EXE) lib $(OBJS) $(SRC_ASMS) uart_out.mRPsim fifo_out mRPsim.vcd *.dump host *.profile

help:
	@echo
	@echo "SRP Compiler Collection"
	@echo
	@echo "make [-jn] : make binary, n: number of threads, more means faster"
	@echo "make run   : make binary and run on mRPsim"
	@echo "make dis   : disassemble"
	@echo "make sym   : show symbols"
	@echo "make clean : clean objects and binary"
	@echo "make asm   : make assembly files"
	@echo

