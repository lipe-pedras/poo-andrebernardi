# Makefile for Laboratory 4 - Comprehensive Operator Overloading

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude
SRCDIR = src
INCDIR = include
BUILDDIR = build

# Source files
COMPLEX_SOURCES = $(SRCDIR)/Complex.cpp $(SRCDIR)/main_Complex.cpp
FRACTION_SOURCES = $(SRCDIR)/Fraction.cpp $(SRCDIR)/main_Fraction.cpp
LONGINTEGER_SOURCES = $(SRCDIR)/LongInteger.cpp $(SRCDIR)/main_LongInteger.cpp

# Object files
COMPLEX_OBJECTS = $(BUILDDIR)/Complex.o $(BUILDDIR)/main_Complex.o
FRACTION_OBJECTS = $(BUILDDIR)/Fraction.o $(BUILDDIR)/main_Fraction.o
LONGINTEGER_OBJECTS = $(BUILDDIR)/LongInteger.o $(BUILDDIR)/main_LongInteger.o

# Executables
COMPLEX_TARGET = $(BUILDDIR)/complex
FRACTION_TARGET = $(BUILDDIR)/fraction
LONGINTEGER_TARGET = $(BUILDDIR)/longinteger

# Default target
all: $(COMPLEX_TARGET) $(FRACTION_TARGET) $(LONGINTEGER_TARGET)

# Complex number program
$(COMPLEX_TARGET): $(COMPLEX_OBJECTS)
	$(CXX) $(COMPLEX_OBJECTS) -o $@

$(BUILDDIR)/Complex.o: $(SRCDIR)/Complex.cpp $(INCDIR)/Complex.h | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR)/main_Complex.o: $(SRCDIR)/main_Complex.cpp $(INCDIR)/Complex.h | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Fraction program
$(FRACTION_TARGET): $(FRACTION_OBJECTS)
	$(CXX) $(FRACTION_OBJECTS) -o $@

$(BUILDDIR)/Fraction.o: $(SRCDIR)/Fraction.cpp $(INCDIR)/Fraction.h | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR)/main_Fraction.o: $(SRCDIR)/main_Fraction.cpp $(INCDIR)/Fraction.h | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# LongInteger program
$(LONGINTEGER_TARGET): $(LONGINTEGER_OBJECTS)
	$(CXX) $(LONGINTEGER_OBJECTS) -o $@

$(BUILDDIR)/LongInteger.o: $(SRCDIR)/LongInteger.cpp $(INCDIR)/LongInteger.h | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR)/main_LongInteger.o: $(SRCDIR)/main_LongInteger.cpp $(INCDIR)/LongInteger.h | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Individual targets for convenience
complex: $(COMPLEX_TARGET)
fraction: $(FRACTION_TARGET)
longinteger: $(LONGINTEGER_TARGET)

# Run targets
run-complex: $(COMPLEX_TARGET)
	./$(COMPLEX_TARGET)

run-fraction: $(FRACTION_TARGET)
	./$(FRACTION_TARGET)

run-longinteger: $(LONGINTEGER_TARGET)
	./$(LONGINTEGER_TARGET)

# Clean target
clean:
	rm -rf $(BUILDDIR)

# Help target
help:
	@echo "Available targets:"
	@echo "  all         - Build all programs"
	@echo "  complex     - Build complex number program"
	@echo "  fraction    - Build fraction program"
	@echo "  longinteger - Build long integer program"
	@echo "  run-complex     - Build and run complex number program"
	@echo "  run-fraction    - Build and run fraction program"
	@echo "  run-longinteger - Build and run long integer program"
	@echo "  clean       - Remove all build files"
	@echo "  help        - Show this help message"

.PHONY: all complex fraction longinteger run-complex run-fraction run-longinteger clean help