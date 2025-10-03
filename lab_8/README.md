# Laboratory 8 - Data Structures and Exception Handling

This laboratory demonstrates advanced C++ programming concepts including custom data structure implementation, exception handling, operator overloading, and robust error management strategies.

## 📁 Project Structure

```
lab_8/
├── build/                  # Compiled executables
├── include/               # Header files
│   ├── stack.h           # Stack class declaration
│   └── polynomial.h      # Polynomial class declaration
├── src/                  # Source files
│   ├── main_ex1.cpp     # Polynomial exception handling demo
│   ├── main_ex2.cpp     # Memory allocation exception demo
│   ├── main_ex4.cpp     # Stack operations demo
│   ├── stack.cpp        # Stack class implementation
│   └── polynomial.cpp   # Polynomial class implementation
├── Makefile             # Build configuration
├── test.sh             # Automated test script
└── README.md           # This file
```

## 🎯 Learning Objectives

This laboratory focuses on:

- **Exception Handling**: Implementing robust error handling using try-catch blocks and custom exceptions
- **Data Structure Design**: Creating custom stack and polynomial classes with proper encapsulation
- **Operator Overloading**: Implementing arithmetic operators, stream operators, and subscript operators
- **Memory Management**: Safe dynamic memory allocation and deallocation with RAII principles
- **Defensive Programming**: Input validation and bounds checking

## 🔧 Classes Overview

### Stack Class
- **Purpose**: Integer stack implementation with exception-safe operations
- **Key Features**:
  - Dynamic memory allocation
  - Push/pop operations with overflow/underflow protection
  - Copy constructor and assignment operator
  - Stream input/output operators
  - Exception handling for empty/full stack conditions

### Polynomial Class
- **Purpose**: Mathematical polynomial representation and operations
- **Key Features**:
  - Dynamic coefficient storage
  - Arithmetic operations (addition, subtraction)
  - Bounds-checked coefficient access
  - Stream input/output for interactive polynomial creation
  - Exception handling for invalid indices

## 🚀 Building the Project

### Build Commands

```bash
# Build all targets
make

# Clean compiled files
make clean

# Build specific targets
make build/poly      # Polynomial demo
make build/stack     # Memory allocation demo  
make build/advanced  # Stack operations demo
```

## 🛡️ Exception Handling Features

### Stack Exceptions
- **Stack Overflow**: Thrown when trying to push to a full stack
- **Stack Underflow**: Thrown when trying to pop from an empty stack
- **Runtime Errors**: General stack operation failures

### Polynomial Exceptions
- **Index Out of Range**: Thrown when accessing invalid coefficient positions
- **Memory Allocation**: Handled during dynamic memory operations

### Memory Management
- **RAII Principle**: Automatic cleanup through destructors
- **Copy Safety**: Deep copying for dynamic data structures
- **Exception Safety**: Strong exception safety guarantees

## 🎓 Educational Value

This laboratory teaches essential C++ programming concepts:

1. **Exception Handling Patterns**: Learning when and how to use exceptions effectively
2. **Custom Data Structures**: Understanding the principles behind container design
3. **Operator Overloading**: Implementing intuitive interfaces for custom classes
4. **Memory Safety**: Preventing memory leaks and managing dynamic allocation
5. **Defensive Programming**: Writing robust code that handles edge cases gracefully


### Expected Behavior
- **Polynomial**: Should handle valid access and throw exception for invalid index
- **Memory**: Should catch and display `std::bad_alloc` exception
- **Stack**: Should successfully push/pop elements and display stack contents