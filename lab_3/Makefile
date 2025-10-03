# Makefile for Laboratory 3 - Object-Oriented Programming

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I.
SRCDIR = src
INCDIR = include
BUILDDIR = build

# Source files
COMPLEX_SOURCES = $(SRCDIR)/complex.cpp $(SRCDIR)/main_complex.cpp
LONG_INTEGER_SOURCES = $(SRCDIR)/long_integer.cpp $(SRCDIR)/main_long_integer.cpp
RIGHT_TRIANGLE_SOURCES = $(SRCDIR)/right_triangle.cpp $(SRCDIR)/main_right_triangle.cpp

# Executable names
COMPLEX_TARGET = $(BUILDDIR)/complex
LONG_INTEGER_TARGET = $(BUILDDIR)/long_integer
RIGHT_TRIANGLE_TARGET = $(BUILDDIR)/right_triangle

# Default target
all: $(COMPLEX_TARGET) $(LONG_INTEGER_TARGET) $(RIGHT_TRIANGLE_TARGET)

# Complex numbers program
$(COMPLEX_TARGET): $(COMPLEX_SOURCES)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Long integer program
$(LONG_INTEGER_TARGET): $(LONG_INTEGER_SOURCES)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Right triangle program
$(RIGHT_TRIANGLE_TARGET): $(RIGHT_TRIANGLE_SOURCES)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Individual targets
complex: $(COMPLEX_TARGET)

long_integer: $(LONG_INTEGER_TARGET)

right_triangle: $(RIGHT_TRIANGLE_TARGET)

# Run targets
run-complex: $(COMPLEX_TARGET)
	./$(COMPLEX_TARGET)

run-long-integer: $(LONG_INTEGER_TARGET)
	./$(LONG_INTEGER_TARGET)

run-right-triangle: $(RIGHT_TRIANGLE_TARGET)
	./$(RIGHT_TRIANGLE_TARGET)

# Clean build directory
clean:
	rm -rf $(BUILDDIR)/*

# Create build directory
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Help target
help:
	@echo "Available targets:"
	@echo "  all              - Build all programs"
	@echo "  complex          - Build complex numbers program"
	@echo "  long_integer     - Build long integer program"
	@echo "  right_triangle   - Build right triangle program"
	@echo "  run-complex      - Build and run complex numbers program"
	@echo "  run-long-integer - Build and run long integer program"
	@echo "  run-right-triangle - Build and run right triangle program"
	@echo "  clean            - Remove all built files"
	@echo "  help             - Show this help message"

# Phony targets
.PHONY: all complex long_integer right_triangle run-complex run-long-integer run-right-triangle clean help