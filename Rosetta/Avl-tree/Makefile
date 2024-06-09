# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -O3
# Source files
SRCS = use-avl-tree.c avl-tree.c
# Object files
OBJS = $(SRCS:.c=.o)
# Executable name
TARGET = use-avl-tree

# Default target
all: $(TARGET)

# Linking object files to create executable
$(TARGET): $(OBJS)
	$(CC) -O3 $(CFLAGS) -o $@.gcc_run $^ -lm

# Compilation rule for .c files
%.o: %.c avl-tree.h
	$(CC) -O3 $(CFLAGS) -c -o $@ $<

# Clean rule to remove generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
