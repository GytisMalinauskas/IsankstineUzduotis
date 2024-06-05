# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -m64 -Wall -IHeaders

# Source files
SRC = $(wildcard Source/*.cpp)

# Executable file
TARGET = run

# Optimization levels and their corresponding flags
OPT_LEVELS = O1 O2 O3
OPT_FLAGS_O1 = -O1
OPT_FLAGS_O2 = -O2
OPT_FLAGS_O3 = -O3

# Targets for each optimization level
.PHONY: all clean O1 O2 O3

all: O1 O2 O3

O1: $(TARGET)_O1.exe

O2: $(TARGET)_O2.exe

O3: $(TARGET)_O3.exe

# Rule for building executable with -O1
$(TARGET)_O1.exe: $(SRC)
	@echo "Building target with -O1: $@"
	$(CXX) $(CXXFLAGS) $(OPT_FLAGS_O1) -o $@ $(SRC)

# Rule for building executable with -O2
$(TARGET)_O2.exe: $(SRC)
	@echo "Building target with -O2: $@"
	$(CXX) $(CXXFLAGS) $(OPT_FLAGS_O2) -o $@ $(SRC)

# Rule for building executable with -O3
$(TARGET)_O3.exe: $(SRC)
	@echo "Building target with -O3: $@"
	$(CXX) $(CXXFLAGS) $(OPT_FLAGS_O3) -o $@ $(SRC)

# Clean rule
clean:
	@echo "Cleaning up..."
	@del $(TARGET)_O1.exe $(TARGET)_O2.exe $(TARGET)_O3.exe
