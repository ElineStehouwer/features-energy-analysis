# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra
# Source files
SRCS = use-avl-tree-gc.c avl-tree.c
# Object files
OBJS = $(SRCS:.c=.o)
# Executable name
TARGET = use-avl-tree-gc

# Default target
all: $(TARGET)

# gcc -Wall -O3 -march=native -I/usr/gc/include $(FILE) /usr/gc/lib/libgc.so -o $(TASK).gcc-run -lm

# Linking object files to create executable
$(TARGET): $(OBJS)
	$(CC) -O3  -march=native $(CFLAGS) -I/usr/gc/include /usr/gc/lib/libgc.so -o $@.gcc_run $^ -lm

# Compilation rule for .c files
%.o: %.c avl-tree.h
	$(CC) -O3 -march=native $(CFLAGS) -I/usr/gc/include /usr/gc/lib/libgc.so  -c -o $@ $<

# Clean rule to remove generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
