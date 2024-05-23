TOOLCHAIN=1
USE_GCC=1

CC=gcc
CXX=g++
COMPILER=$(CC)

APP:=mix_c_cpp
TARGET = $(APP)
PROJECT = $(shell pwd)

ifeq ($(TOOLCHAIN), 1)
CROSS_TARGET = ../../../fwipcam/homeipcam_fw2.1/toolchain/mips-gcc472-glibc216-64bit
CC = $(CROSS_TARGET)/bin/mips-linux-uclibc-gnu-gcc
CXX = $(CROSS_TARGET)/bin/mips-linux-uclibc-gnu-g++
endif


CFLAGS += -I./
DFLAGS += -L./

ifeq ($(USE_GCC), 1)
TARGET = $(APP)_gcc
DFLAGS += -lstdc++
COMPILER=$(CC)
else
TARGET = $(APP)_g++
COMPILER=$(CXX)
endif

SRCS:= $(wildcard *.c)
SRCS_CPP:= $(wildcard *.cpp)

OBJS:= $(SRCS:.c=.o)
OBJS+= $(SRCS_CPP:.cpp=.o)


all: $(TARGET) 

%.o: %.c
	$(COMPILER) -c -o $@ $(CFLAGS) $(DFLAGS) $<

%.o: %.cpp
	$(COMPILER) -c -o $@ $(CFLAGS) $(DFLAGS) $<

$(TARGET): $(OBJS)
	$(COMPILER) -o $@ $(OBJS) $(DFLAGS)

clean:
	rm -rf *.o 
	rm -rf $(TARGET) 