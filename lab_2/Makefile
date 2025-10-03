# Makefile for Laboratory 2 - Object-Oriented Programming
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
SRCDIR = src
INCDIR = include
BUILDDIR = build

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

# Header files
INCLUDES = -I$(INCDIR)

# Main targets
MAIN_TARGET = $(BUILDDIR)/main
FRACTION_TARGET = $(BUILDDIR)/fraction_demo
RECTANGLE_TARGET = $(BUILDDIR)/rectangle_demo

# Class object files (without main functions)
CLASS_OBJECTS = $(BUILDDIR)/Fraction.o $(BUILDDIR)/Polygon.o $(BUILDDIR)/Rectangle.o

.PHONY: all clean help

# Default target
all: $(MAIN_TARGET) $(FRACTION_TARGET) $(RECTANGLE_TARGET)

# Main program
$(MAIN_TARGET): $(BUILDDIR)/main.o $(CLASS_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Fraction demonstration program
$(FRACTION_TARGET): $(BUILDDIR)/fraction_demo.o $(BUILDDIR)/Fraction.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rectangle demonstration program
$(RECTANGLE_TARGET): $(BUILDDIR)/rectangle_demo.o $(BUILDDIR)/Rectangle.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Object files compilation
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Create build directory
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Clean build files
clean:
	rm -rf $(BUILDDIR)/*

# Help target
help:
	@echo "Available targets:"
	@echo "  all           - Build all programs"
	@echo "  main          - Build main program"
	@echo "  fraction_demo - Build fraction demonstration"
	@echo "  rectangle_demo- Build rectangle demonstration"
	@echo "  clean         - Remove all build files"
	@echo "  help          - Show this help message"

# Run targets
run-main: $(MAIN_TARGET)
	./$(MAIN_TARGET)

run-fraction: $(FRACTION_TARGET)
	./$(FRACTION_TARGET)

run-rectangle: $(RECTANGLE_TARGET)
	./$(RECTANGLE_TARGET)