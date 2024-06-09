# Compiler settings
CXX := g++
CC := gcc
CXXFLAGS := -std=c++11  # C++11 standard for g++

# Target executable
TARGET := sorting-algorithms-merge-sort-gc-dt

# Source directories
SRC_DIR := ../../src-dt
INC_DIR := ../../headers-dt
CUR_DIR := .

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
SRCS += $(wildcard $(CUR_DIR)/*.c)

# Object files
OBJS := $(patsubst $(SRC_DIR)/%.cpp,%.o,$(filter %.cpp,$(SRCS)))
OBJS += $(patsubst $(CUR_DIR)/%.c,%.o,$(filter %.c,$(SRCS)))

# Include directories
INC := -I$(INC_DIR)

# Default target
all: $(TARGET)

# Compile C++ source files
%.o: $(SRC_DIR)/%.cpp
	$(CXX) -O3 $(CXXFLAGS) $(INC) -I/usr/gc/include -c $< -o $@

# Compile C source files
%.o: $(CUR_DIR)/%.c
	$(CC) -O3 $(INC) -I/usr/gc/include -c $< -o $@ -lm

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) -O3 $^ /usr/gc/lib/libgc.so -o $@

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
