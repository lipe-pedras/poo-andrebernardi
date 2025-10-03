# Makefile for Laboratory 6 - Object-Oriented Programming with C++
# Author: Andre Bernardi
# Course: Object-Oriented Programming

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2 -I./include

# Directories
SRCDIR = src
INCDIR = include
BUILDDIR = build

# Source files
POLYNOMIAL_SRCS = $(SRCDIR)/Polynomial.cpp $(SRCDIR)/main_polynomial.cpp
PHONE_SRCS = $(SRCDIR)/PhoneNumber.cpp $(SRCDIR)/main_phone_number.cpp
GEOMETRY_SRCS = $(SRCDIR)/Geometry.cpp $(SRCDIR)/main_geometry.cpp

# Target executables
POLYNOMIAL_TARGET = $(BUILDDIR)/polynomial_demo
PHONE_TARGET = $(BUILDDIR)/phone_demo
GEOMETRY_TARGET = $(BUILDDIR)/geometry_demo

# All targets
TARGETS = $(POLYNOMIAL_TARGET) $(PHONE_TARGET) $(GEOMETRY_TARGET)

# Default target
all: $(TARGETS)

# Create build directory if it doesn't exist
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Polynomial demo
$(POLYNOMIAL_TARGET): $(POLYNOMIAL_SRCS) | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -o $@ $(POLYNOMIAL_SRCS)

# Phone number demo
$(PHONE_TARGET): $(PHONE_SRCS) | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -o $@ $(PHONE_SRCS)

# Geometry demo
$(GEOMETRY_TARGET): $(GEOMETRY_SRCS) | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -o $@ $(GEOMETRY_SRCS)

# Individual targets
polynomial: $(POLYNOMIAL_TARGET)

phone: $(PHONE_TARGET)

geometry: $(GEOMETRY_TARGET)

# Run targets
run-polynomial: $(POLYNOMIAL_TARGET)
	./$(POLYNOMIAL_TARGET)

run-phone: $(PHONE_TARGET)
	./$(PHONE_TARGET)

run-geometry: $(GEOMETRY_TARGET)
	./$(GEOMETRY_TARGET)

run-all: $(TARGETS)
	@echo "=== Running Phone Number Demo ==="
	./$(PHONE_TARGET)
	@echo ""
	@echo "=== Running Polynomial Demo ==="
	./$(POLYNOMIAL_TARGET)
	@echo ""
	@echo "=== Running Geometry Demo ==="
	./$(GEOMETRY_TARGET)

# Clean compiled files
clean:
	rm -rf $(BUILDDIR)

# Install (optional - copies to system directory)
install: all
	@echo "Installing to /usr/local/bin (requires sudo)"
	sudo cp $(TARGETS) /usr/local/bin/

# Help target
help:
	@echo "Available targets:"
	@echo "  all              - Compile all programs"
	@echo "  polynomial       - Compile polynomial mathematics program"
	@echo "  phone            - Compile phone number validation program"
	@echo "  geometry         - Compile inheritance demonstration program"
	@echo "  run-polynomial   - Compile and run polynomial demo"
	@echo "  run-phone        - Compile and run phone demo"
	@echo "  run-geometry     - Compile and run geometry demo"
	@echo "  run-all          - Compile and run all programs"
	@echo "  clean            - Remove build directory and compiled files"
	@echo "  install          - Install executables to /usr/local/bin"
	@echo "  help             - Show this help message"

.PHONY: all polynomial phone geometry run-polynomial run-phone run-geometry run-all clean install help