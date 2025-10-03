# Makefile for Assessment 1 - Object-Oriented Programming
# Simple build system for educational purposes

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude
BUILDDIR = build
SRCDIR = src
INCDIR = include

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

# Main executables
TARGETS = $(BUILDDIR)/long_integer_demo $(BUILDDIR)/polynomial_demo $(BUILDDIR)/exam_demo

.PHONY: all clean

all: $(BUILDDIR) $(TARGETS)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Build LongInteger demo
$(BUILDDIR)/long_integer_demo: $(BUILDDIR)/main_long_integer.o $(BUILDDIR)/LongInteger.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build Polynomial demo
$(BUILDDIR)/polynomial_demo: $(BUILDDIR)/main_polynomial.o $(BUILDDIR)/Polynomial.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build Exam demo
$(BUILDDIR)/exam_demo: $(BUILDDIR)/main_exam.o $(BUILDDIR)/BimonthlyExam.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Object file rules
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILDDIR)

# Run demonstrations
run_long_integer: $(BUILDDIR)/long_integer_demo
	./$(BUILDDIR)/long_integer_demo

run_polynomial: $(BUILDDIR)/polynomial_demo
	./$(BUILDDIR)/polynomial_demo

run_exam: $(BUILDDIR)/exam_demo
	./$(BUILDDIR)/exam_demo

run_all: $(TARGETS)
	@echo "Running LongInteger demo..."
	./$(BUILDDIR)/long_integer_demo
	@echo -e "\n\nRunning Polynomial demo..."
	./$(BUILDDIR)/polynomial_demo
	@echo -e "\n\nRunning Exam demo..."
	./$(BUILDDIR)/exam_demo