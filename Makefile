#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
CFLAGS = -Wall -Werror -g -O0 -std=c99 -DVERBOSE -DCOURSE1 
CPPFLAGS = $(INCLUDES)


ifeq ($(PLATFORM), HOST)
	LDFLAGS = -o $(TARGET) -lm
	CC = gcc
	LD = gcc
	CFLAGS += -DHOST

else ifeq ($(PLATFORM), MSP432)
	# Architectures Specific Flags
	LINKER_FILE = -T ../msp432p401r.lds
	CPU = -mcpu=cortex-m4
	ARCH = -mthumb
	SPECS = --specs=nosys.specs

	# Compiler Flags and Defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-gcc
	LDFLAGS = $(LINKER_FILE) -mfloat-abi=soft -Wl,-Map=c1m2.map
	CFLAGS += $(CPU) $(ARCH) -march=armv7e-m -mfloat-abi=soft --specs=nosys.specs -DMSP432 -MMD -MP
	CPPFLAGS += $(INCLUDES)

else 
$(error Unknow patform specified.)

endif

# Reglas de preprocesado, ensamblador y objeto
%.i: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -E $< -o $@

%.asm: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -S $< -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Regla para generar ensamblador del ejecutable
%.asm: %.out
	objdump -d $< > $@


.PHONY: generate-preprocessed
generate-preprocessed: $(SOURCES:.c=.i)

# Compilar todo sin enlazar
.PHONY: compile-all
compile-all: $(SOURCES:.c=.o)

# Compilar y enlazar todo
.PHONY: build
build: generate-preprocessed compile-all
	$(LD) $(LDFLAGS) -o main.out $(SOURCES:.c=.o)

# Limpiar
.PHONY: clean
clean:
	rm -f src/*.o src/*.i src/*.asm src/*.d src/main.out src/main.map

-include $(SOURCES:.c=.d)


