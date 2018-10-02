CC = g++ # use g++ compiler

FLAGS = -std=c++11 	# compile with C++ 11 standard
FLAGS += -Wall 			# Compile with all warnings

LINK = $(CC) $(FLAGS) -o
COMPILE = $(CC) $(FLAGS) -c

INCLUDE = include
SOURCE = src
BINARY = bin
BUILD = build
TEST = test
BUILD64 = build_w64
BUILD32 = build_w32

CCW64 = x86_64-w64-mingw32-g++
CCW84 = i686-w64-mingw32-g++

LINKW64 = $(CCW64) $(FLAGS) --static -o
LINKW84 = $(CCW84) $(FLAGS) --static -o

COMPILEW64 = $(CCW64) $(FLAGS) --static -c
COMPILEW84 = $(CCW84) $(FLAGS) --static -c


generator :	$(BUILD)/generator.o
	$(LINK) $(BINARY)/$@ $^

$(BUILD)/generator.o : $(SOURCE)/generator.cc $(INCLUDE)/generator.h
	$(COMPILE) $< -o $@

generator64.exe : $(BUILD64)/generator.o
	$(LINKW64) $(BINARY)/$@ $^

$(BUILD64)/generator.o : $(SOURCE)/generator.cc $(INCLUDE)/generator.h
	$(COMPILEW64) $< -o $@

generator32.exe : $(BUILD32)/generator.o
	$(LINKW84) $(BINARY)/$@ $^

$(BUILD32)/generator.o : $(SOURCE)/generator.cc $(INCLUDE)/generator.h
	$(COMPILEW84) $< -o $@

clean:
	@rm $(BUILD)/*.o $(BUILD64)/*.o $(BUILD32)/*.o $(BINARY)/*
