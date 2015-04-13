# Compilation level: -O0, -O1, -O2, ...
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
include $(SRPSDK_INSTALL)/share/arch/srp4m/system/sim/makefile.conf

