# Laboratory 1 - Introduction to C++ and Classes

This laboratory introduces fundamental concepts of Object-Oriented Programming in C++ through the implementation of a Rectangle class and various mathematical operations.

## Project Structure

```
lab_1/
├── src/                    # Source files
│   ├── main.cpp           # Main program with menu system and mathematical functions
│   └── rectangle.cpp      # Rectangle class implementation
├── include/               # Header files
│   └── rectangle.h        # Rectangle class header file
├── build/                 # Build output directory (auto-generated)
│   ├── obj/              # Object files
│   └── lab1              # Final executable
├── Makefile              # Build configuration
├── .gitignore            # Git ignore rules
└── README.md             # This file
```

## Contents

### Core Files
- **`include/rectangle.h`** - Rectangle class header file
- **`src/rectangle.cpp`** - Rectangle class implementation  
- **`src/main.cpp`** - Main program with menu system and mathematical functions

## 🎯 Learning Objectives

### 1. Basic Class Implementation
- Constructor and destructor usage
- Private member variables with public interface
- Input validation and error handling
- Const member functions

### 2. Rectangle Class Features
- **Constructor**: Creates rectangle with specified length and width
- **Setters**: `setComprimento()`, `setLargura()` with validation (1-20 range)
- **Getters**: `getComprimento()`, `getLargura()`
- **Calculations**: `getArea()`, `getPerimetro()`
- **Utilities**: `printRetangulo()` (ASCII art), `Is_Square()` checker

### 3. Mathematical Operations Menu
Interactive console menu featuring:
- **Factorial calculation** - Recursive implementation
- **Prime number generator** - Finds first 20 primes
- **Rectangle drawing** - ASCII art with customizable borders
- **Sum operations** - Various sum calculations
- **GCD calculation** - Greatest Common Divisor using Euclidean algorithm
- **Binary conversion** - Binary to decimal conversion
- **Palindrome checker** - String-based palindrome detection

## 🚀 Compilation and Execution

The project uses a Makefile for easy compilation and execution:

```bash
# Build the project
make

# Build and run
make run

# Clean build files
make clean
```

## 📚 Educational Value

This laboratory demonstrates:
- **Class design principles** - Encapsulation, data validation
- **Memory management** - Constructor/destructor lifecycle
- **User interface design** - Menu-driven program structure
- **Algorithm implementation** - Mathematical functions and recursion
- **Code organization** - Separation of class interface and implementation

The combination of object-oriented programming with classical algorithms provides a comprehensive introduction to C++ programming fundamentals.