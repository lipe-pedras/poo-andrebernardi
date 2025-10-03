# Makefile for Laboratory 9 - Generic Data Structures
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g -O2
INCLUDES = -Iinclude
SRCDIR = src
INCDIR = include
BUILDDIR = build

# Source files
VECTOR_EXAMPLE_SRC = $(SRCDIR)/vector_example.cpp
STACK_EXAMPLE_SRC = $(SRCDIR)/stack_example.cpp
COMBINED_EXAMPLE_SRC = $(SRCDIR)/combined_example.cpp

# Executables
VECTOR_EXEC = $(BUILDDIR)/vector_example
STACK_EXEC = $(BUILDDIR)/stack_example
COMBINED_EXEC = $(BUILDDIR)/combined_example

# Default target
all: $(VECTOR_EXEC) $(STACK_EXEC) $(COMBINED_EXEC)

# Create build directory if it doesn't exist
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Build vector example (header-only template)
$(VECTOR_EXEC): $(VECTOR_EXAMPLE_SRC) $(INCDIR)/Vector.h | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(VECTOR_EXAMPLE_SRC) -o $(VECTOR_EXEC)

# Build stack example (header-only template)
$(STACK_EXEC): $(STACK_EXAMPLE_SRC) $(INCDIR)/Stack.h | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(STACK_EXAMPLE_SRC) -o $(STACK_EXEC)

# Build combined example (both header-only templates)
$(COMBINED_EXEC): $(COMBINED_EXAMPLE_SRC) $(INCDIR)/Vector.h $(INCDIR)/Stack.h | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(COMBINED_EXAMPLE_SRC) -o $(COMBINED_EXEC)

# Individual targets
vector: $(VECTOR_EXEC)
stack: $(STACK_EXEC)
combined: $(COMBINED_EXEC)

# Run targets
run-vector: $(VECTOR_EXEC)
	@echo "Running Vector Example:"
	@echo "======================"
	./$(VECTOR_EXEC)

run-stack: $(STACK_EXEC)
	@echo "Running Stack Example:"
	@echo "====================="
	./$(STACK_EXEC)

run-combined: $(COMBINED_EXEC)
	@echo "Running Combined Example:"
	@echo "========================"
	./$(COMBINED_EXEC)

run-all: run-vector run-stack run-combined

# Debug builds
debug: CXXFLAGS += -DDEBUG -O0
debug: all

# Release builds
release: CXXFLAGS += -DNDEBUG -O3
release: all

# Clean targets
clean:
	rm -rf $(BUILDDIR)/*.o

clean-all:
	rm -rf $(BUILDDIR)/*

distclean: clean-all
	rm -rf $(BUILDDIR)

# Install (copy executables to a bin directory)
install: all
	mkdir -p bin
	cp $(VECTOR_EXEC) bin/
	cp $(STACK_EXEC) bin/
	cp $(COMBINED_EXEC) bin/

# Test targets
test: all
	@echo "Running all examples as tests..."
	@echo "Testing Vector Example:"
	@echo "5" | $(VECTOR_EXEC) > /dev/null && echo "Vector test: PASSED" || echo "Vector test: FAILED"
	@echo "Testing Stack Example:"
	@echo "1 2 3 -1" | $(STACK_EXEC) > /dev/null && echo "Stack test: PASSED" || echo "Stack test: FAILED"

# Help target
help:
	@echo "Available targets:"
	@echo "  all          - Build all executables"
	@echo "  vector       - Build vector example only"
	@echo "  stack        - Build stack example only"
	@echo "  combined     - Build combined example only"
	@echo "  run-vector   - Build and run vector example"
	@echo "  run-stack    - Build and run stack example"
	@echo "  run-combined - Build and run combined example"
	@echo "  run-all      - Build and run all examples"
	@echo "  debug        - Build with debug symbols"
	@echo "  release      - Build optimized release version"
	@echo "  clean        - Remove object files"
	@echo "  clean-all    - Remove all build files"
	@echo "  distclean    - Remove build directory"
	@echo "  install      - Install executables to bin/"
	@echo "  test         - Run basic tests"
	@echo "  help         - Show this help message"

# Phony targets
.PHONY: all vector stack combined run-vector run-stack run-combined run-all debug release clean clean-all distclean install test help

# Dependencies
$(VECTOR_EXEC): $(INCDIR)/Vector.h
$(STACK_EXEC): $(INCDIR)/Stack.h
$(COMBINED_EXEC): $(INCDIR)/Vector.h $(INCDIR)/Stack.h