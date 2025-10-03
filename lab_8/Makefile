CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
INCLUDE = -Iinclude
SRC = src
BUILD = build

all: $(BUILD)/poly $(BUILD)/stack $(BUILD)/advanced

$(BUILD)/poly: $(SRC)/main_ex1.cpp $(SRC)/polynomial.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ $^

$(BUILD)/stack: $(SRC)/main_ex2.cpp $(SRC)/stack.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ $^

$(BUILD)/advanced: $(SRC)/main_ex4.cpp $(SRC)/stack.cpp $(SRC)/polynomial.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ $^

clean:
	rm -f $(BUILD)/*

.PHONY: all clean
