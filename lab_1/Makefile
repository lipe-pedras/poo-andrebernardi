# Simple Makefile for Lab 1
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

# Directories
SRC = src
BUILD = build

# Target executable
TARGET = $(BUILD)/lab1

# Source files
SOURCES = $(SRC)/main.cpp $(SRC)/rectangle.cpp

# Default: build the program
all: $(TARGET)

# Create build directory and compile
$(TARGET): $(SOURCES)
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build files
clean:
	rm -rf $(BUILD)

.PHONY: all run clean