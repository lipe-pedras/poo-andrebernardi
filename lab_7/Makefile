# Simple Makefile for Lab 7

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
INCLUDE = -Iinclude
SRC = src
BUILD = build

POLITICS_SRC = $(SRC)/politicians.cpp
GEOMETRY_SRC = $(SRC)/geometry.cpp

POLITICS_BIN = $(BUILD)/politicians
GEOMETRY_BIN = $(BUILD)/geometry

all: $(POLITICS_BIN) $(GEOMETRY_BIN)

$(POLITICS_BIN): $(POLITICS_SRC) include/classes.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) $< -o $@

$(GEOMETRY_BIN): $(GEOMETRY_SRC) include/classes.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) $< -o $@

clean:
	rm -rf $(BUILD)/*

.PHONY: all clean
