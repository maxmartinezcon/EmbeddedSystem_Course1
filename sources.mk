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

# Add your Source files to this variable
SOURCES = src/memory.c 
SOURCES += src/main.c
SOURCES += src/syscalls.c
SOURCES += src/course1.c
SOURCES += src/stats.c
SOURCES += src/data.c


TARGET = main.out

ifeq ($(PLATFORM), MSP432)
    SOURCES += src/interrupts_msp432p401r_gcc.c \
               src/startup_msp432p401r_gcc.c \
               src/system_msp432p401r.c
endif

# Add your include paths to this variable
INCLUDES = -Iinclude/common

ifeq ($(PLATFORM), MSP432)
    INCLUDES += -Iinclude/msp432 \
                -Iinclude/CMSIS
endif

