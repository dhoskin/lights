# Somewhat ripped off from teensycore/teensy3/Makefile

all: main.hex

TEENSYCORE = teensycore/teensy3
MCU = MKL26Z64
LDSCRIPT = teensycore/teensy3/mkl26z64.ld

TOOLCHAIN = arm-none-eabi-
CC = $(TOOLCHAIN)gcc
CXX = $(TOOLCHAIN)cxx
OBJCOPY = $(TOOLCHAIN)objcopy
SIZE = $(TOOLCHAIN)size

CPPFLAGS = -DF_CPU=48000000 -D__$(MCU)__ -Iteensycore/teensy3

CFLAGS = -Wall -g -Os -mcpu=cortex-m0plus -mthumb

LDFLAGS = -Os -Wl,--gc-sections,--defsym=__rtc_localtime=0 -mcpu=cortex-m0plus -mthumb -T$(LDSCRIPT)

SYS_OBJS = $(TEENSYCORE)/mk20dx128.o $(TEENSYCORE)/pins_teensy.o
OBJS = main.o internal_led.o

OBJS += $(SYS_OBJS)

$(SYS_OBJS): teensycore/.patched

teensycore/.patched: xxx_hack.patch
	(cd teensycore; git am ../xxx_hack.patch)
	touch $@

.SUFFIXES: .elf .hex

main.elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) -lm

.elf.hex:
	$(SIZE) $<
	$(OBJCOPY) -O ihex -R .eeprom $< $@

.c.o:
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
