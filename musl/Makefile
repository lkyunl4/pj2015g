OPTIMIZE:= -O3
MACRO_DEFINES:=
COMPILE_OPTIONS= \
					-mllvm -enable-aa-sched-mi \
					-mllvm -enable-bundle-compression \
					-mllvm -enable-bundle-nop-compression \
					-mllvm -enable-multi-cycle-nop \
					$(WERROR_FLAG) 

USER_SYM_DEF=
SCC_INC:=
SCC_EXCLUDES:=params
USER_LIBS:=
OUTPUT_DIR=.
LINKER_SCRIPT= $(SRPSDK_INSTALL)/share/arch/$(TARGET)/system/$(TARGET_SYS)/$(LDSCRIPT_NAME)

#

TARGET=srp4m

TARGET_SYS=sim

COMPILE_MACRO_DEFINES= \
					-D__srp__ \
					-D__ELF__

SYSTEM_MACRO_DEFINES= \
					-DCONFIG_ARCH_BERN

SCC=$(SRPSDK_INSTALL)/bin/scc
SCC_LD=$(SRPSDK_INSTALL)/bin/scc.ld
SCC_AR=ar
MRPSIM=$(MRPSIM_PATH)/bin/mRPsim
LD=gcc
STD=gnu89
EXE=a.out

OPTIONS= \
					-fdata-sections \
					-fno-vectorize \
					-fno-slp-vectorize \
					-fno-zero-initialized-in-bss \
					-std=$(STD) \
					$(COMPILE_MACRO_DEFINES) \
					$(SYSTEM_MACRO_DEFINES) \
					$(COMPILE_OPTIONS)

MUSLLIB_COMPILE_OPTIONS= -srp-subtarget $(TARGET) $(MACRO_DEFINES)
SCC_CFLAGS= $(MUSLLIB_COMPILE_OPTIONS) $(OPTIMIZE) $(OPTIONS) -D SCC_TEST -g

SCC_ASFLAGS= -c $(OPTIMIZE) -srp-subtarget $(TARGET)

SCC_ARFLAGS= r

COMPILER_SYM_DEF=

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

SYM_DEF= \
					$(COMPILER_SYM_DEF) \
					$(SYSTEM_SYM_DEF) \
					$(USER_SYM_DEF)

SCC_LDFLAGS= -T $(LINKER_SCRIPT) $(SYM_DEF) -gc-sections

LIBRARY_INC:= \
					-I $(SRPSDK_SRC)/library/compiler-rt \
					-I $(SRPSDK_SRC)/library/smk \
					-I $(SRPSDK_SRC)/arch/common \
					-I $(SRPSDK_SRC)/arch/$(TARGET)/etc \
					-I $(SRPSDK_SRC)/arch/$(TARGET)/hal \
					-I $(SRPSDK_SRC)/arch/$(TARGET)/system/$(TARGET_SYS)/src \
					#-include $(SRPSDK_SRC)/arch/$(TARGET)/etc/srp_vector.h

SYSTEM_INC:= \
					-I $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/common \
					-I $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/compiler-rt \
					-I $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/etc \
					-I $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/hal \
					-I $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/smk \
					-I $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/startup \
					-I $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/system \
					#-include $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/etc/srp_vector.h \
					#-include $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/common/legacy.h

SYSTEM_LIBS:= \
					-L $(SRPSDK_INSTALL)/lib/arch/$(TARGET)/system/$(TARGET_SYS)/common \
					-L $(SRPSDK_INSTALL)/lib/arch/$(TARGET)/system/$(TARGET_SYS)/compiler-rt \
					-L $(SRPSDK_INSTALL)/lib/arch/$(TARGET)/system/$(TARGET_SYS)/etc \
					-L $(SRPSDK_INSTALL)/lib/arch/$(TARGET)/system/$(TARGET_SYS)/hal \
					-L $(SRPSDK_INSTALL)/lib/arch/$(TARGET)/system/$(TARGET_SYS)/smk \
					-L $(SRPSDK_INSTALL)/lib/arch/$(TARGET)/system/$(TARGET_SYS)/system \
					-start-group -lcommon -lcompiler-rt -letc -lhal -lc -lm -lsrp -lsmk -lsystem -end-group

STARTUP_OBJS:= \
					$(SRPSDK_INSTALL)/lib/arch/$(TARGET)/system/$(TARGET_SYS)/startup/crt0.o \
					$(SRPSDK_INSTALL)/lib/arch/$(TARGET)/system/$(TARGET_SYS)/startup/isr.o



exec_prefix	= $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/musl

bindir = $(exec_prefix)/bin

prefix = $(SRPSDK_INSTALL)/include/arch/$(TARGET)/system/$(TARGET_SYS)/musl
includedir = $(prefix)/include
libdir = $(prefix)/lib
syslibdir = $(SRPSDK_INSTALL)/lib-musl

SRCS = $(sort $(wildcard src/*/*.c arch/$(ARCH)/src/*.c))
OBJS = $(SRCS:.c=.o)
LOBJS = $(OBJS:.o=.lo)
GENH = include/bits/alltypes.h
#GENH_INT = src/internal/version.h
IMPH = src/internal/stdio_impl.h src/internal/libc.h

#CFLAGS = -Os -pipe
#CFLAGS_C99FSE = -std=c99 -ffreestanding -nostdinc 

#CFLAGS_ALL = $(CFLAGS_C99FSE)
CFLAGS_ALL = -D_XOPEN_SOURCE=700 -I./arch/$(ARCH) -I./src/internal -I./include
CFLAGS_ALL += $(CFLAGS)
CFLAGS_ALL_STATIC = $(CFLAGS_ALL)
#CFLAGS_ALL_SHARED = $(CFLAGS_ALL) -fPIC -DSHARED

AR      = $(CROSS_COMPILE)ar
RANLIB  = $(CROSS_COMPILE)ranlib
INSTALL = ./tools/install.sh

#ARCH_INCLUDES = $(wildcard arch/$(ARCH)/bits/*.h)
#ALL_INCLUDES = $(sort $(wildcard include/*.h include/*/*.h) $(GENH) $(ARCH_INCLUDES:arch/$(ARCH)/%=include/%))
ALL_INCLUDES = $(sort $(wildcard include/*.h include/*/*.h) $(GENH))

EMPTY_LIB_NAMES = m rt pthread crypt util xnet resolv dl
EMPTY_LIBS = $(EMPTY_LIB_NAMES:%=lib/lib%.a)
#CRT_LIBS = lib/crt1.o lib/Scrt1.o lib/crti.o lib/crtn.o
STATIC_LIBS = lib/libc.a
SHARED_LIBS = lib/libc.so
#TOOL_LIBS = lib/musl-gcc.specs
#ALL_LIBS = $(CRT_LIBS) $(STATIC_LIBS) $(SHARED_LIBS) $(EMPTY_LIBS) $(TOOL_LIBS)
#ALL_LIBS = $(CRT_LIBS) $(STATIC_LIBS) $(SHARED_LIBS) $(EMPTY_LIBS)
ALL_LIBS = $(STATIC_LIBS) $(SHARED_LIBS) $(EMPTY_LIBS)
#ALL_TOOLS = tools/musl-gcc

LDSO_PATHNAME = $(syslibdir)/ld-musl-$(ARCH)$(SUBARCH).so.1

#-include config.mak
ARCH=srp4m

all: $(ALL_LIBS)

install: install-libs install-headers

clean:
	rm -f crt/*.o
	rm -f $(OBJS)
	rm -f $(LOBJS)
	rm -f $(ALL_LIBS) lib/*.[ao] lib/*.so
	rm -f $(GENH) $(GENH_INT)
	rm -f include/bits

include/bits:
	ln -sf ../arch/i386/bits $@

include/bits/alltypes.h.in: include/bits

include/bits/alltypes.h: include/bits/alltypes.h.in include/alltypes.h.in tools/mkalltypes.sed
	sed -f tools/mkalltypes.sed include/bits/alltypes.h.in include/alltypes.h.in > $@

OPTIMIZE_SRCS = $(wildcard $(OPTIMIZE_GLOBS:%=src/%))
$(OPTIMIZE_SRCS:%.c=%.o) $(OPTIMIZE_SRCS:%.c=%.lo): CFLAGS += -O3

MEMOPS_SRCS = src/string/memcpy.c src/string/memmove.c src/string/memcmp.c src/string/memset.c
$(MEMOPS_SRCS:%.c=%.o) $(MEMOPS_SRCS:%.c=%.lo): CFLAGS += $(CFLAGS_MEMOPS)

define mkasmdep
$(dir $(patsubst %/,%,$(dir $(1))))$(notdir $(1:.s=.o)): $(1)
endef
$(foreach s,$(wildcard src/*/$(ARCH)*/*.s),$(eval $(call mkasmdep,$(s))))

%.o: %.c $(GENH) $(IMPH)
	$(SCC) $(SCC_CFLAGS) $(CFLAGS_ALL_STATIC) -c -o $@ $< $(SYSTEM_INC)

%.lo: $(ARCH)$(ASMSUBARCH)/%.sub
	$(SCC) $(SCC_CFLAGS) $(CFLAGS_ALL_STATIC) -c -o $@ $(dir $<)$(shell cat $<) $(SYSTEM_INC)

%.lo: %.c $(GENH) $(IMPH)
	$(SCC) $(SCC_CFLAGS) $(CFLAGS_ALL_STATIC) -c -o $@ $< $(SYSTEM_INC)

lib/libc.so: $(LOBJS)
	$(SCC) $(SCC_CFLAGS) $(CFLAGS_ALL_STATIC) $(LDFLAGS) -nostdlib -shared -Wl,-e,_dlstart -Wl,-Bsymbolic-functions -o $@ $(LOBJS) $(LIBCC)

lib/libc.a: $(OBJS)
	rm -f $@
	$(AR) rc $@ $(OBJS)
	$(RANLIB) $@

$(EMPTY_LIBS):
	rm -f $@
	$(AR) rc $@

lib/%.o: crt/%.o
	cp $< $@

$(DESTDIR)$(libdir)/%.so: lib/%.so
	$(INSTALL) -D -m 755 $< $@

$(DESTDIR)$(libdir)/%: lib/%
	$(INSTALL) -D -m 644 $< $@

$(DESTDIR)$(includedir)/bits/%: arch/$(ARCH)/bits/%
	$(INSTALL) -D -m 644 $< $@

$(DESTDIR)$(includedir)/%: include/%
	$(INSTALL) -D -m 644 $< $@

$(DESTDIR)$(LDSO_PATHNAME): $(DESTDIR)$(libdir)/libc.so
	$(INSTALL) -D -l $(libdir)/libc.so $@ || true

install-libs: $(ALL_LIBS:lib/%=$(DESTDIR)$(libdir)/%) $(if $(SHARED_LIBS),$(DESTDIR)$(LDSO_PATHNAME),)

install-headers: $(ALL_INCLUDES:include/%=$(DESTDIR)$(includedir)/%)

musl-git-%.tar.gz: .git
	git archive --format=tar.gz --prefix=$(patsubst %.tar.gz,%,$@)/ -o $@ $(patsubst musl-git-%.tar.gz,%,$@)

musl-%.tar.gz: .git
	git archive --format=tar.gz --prefix=$(patsubst %.tar.gz,%,$@)/ -o $@ v$(patsubst musl-%.tar.gz,%,$@)

.PRECIOUS: $(CRT_LIBS:lib/%=crt/%)

.PHONY: all clean install install-libs install-headers

