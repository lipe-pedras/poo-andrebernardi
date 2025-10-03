# Laboratory 2 - Class Separation and File Organization

This laboratory focuses on proper code organization by separating class declarations from implementations, and introduces more complex class relationships.

## 📁 Project Structure

```
lab_2/
├── include/           # Header files (.h)
│   ├── Fraction.h     # Fraction class declaration
│   ├── Polygon.h      # Polygon class declaration  
│   └── Rectangle.h    # Rectangle class declaration
├── src/               # Source files (.cpp)
│   ├── Fraction.cpp   # Fraction class implementation
│   ├── Polygon.cpp    # Polygon class implementation
│   ├── Rectangle.cpp  # Rectangle class implementation
│   ├── main.cpp       # Main demonstration program
│   ├── fraction_demo.cpp  # Fraction-specific demo
│   └── rectangle_demo.cpp # Rectangle-specific demo
├── build/             # Build output directory
├── Makefile           # Build automation
└── README.md          # This file
```

## � Quick Start

### Building the Project
```bash
# Build all programs
make all

# Build specific programs
make main           # Main demonstration
make fraction_demo  # Fraction operations demo
make rectangle_demo # Rectangle array demo

# Clean build files
make clean
```

### Running the Programs
```bash
# Run main program
make run-main

# Run fraction demo
make run-fraction

# Run rectangle demo  
make run-rectangle
```

## �📋 Contents

### Core Classes
- **`Fraction`** - Fraction class with arithmetic operations (translated from CFracao)
- **`Polygon`** - Polygon class with geometric calculations (translated from Poligono) 
- **`Rectangle`** - Enhanced Rectangle class (translated from Retangulo)

### Programs
- **`main.cpp`** - Main demonstration program
- **`fraction_demo.cpp`** - Fraction operations demonstration
- **`rectangle_demo.cpp`** - Rectangle array demonstration

## � Build System

The project uses a Makefile for automated building:

```bash
# Build all programs
make all

# Build individual programs
make main           # Main demonstration program
make fraction_demo  # Fraction operations demo
make rectangle_demo # Rectangle array demo

# Clean build artifacts
make clean

# Get help on available targets
make help
```

## 📚 Educational Value

This laboratory demonstrates:

### Professional Code Organization
- **Modular design** - Separate interface from implementation
- **Reusability** - Classes can be used in multiple programs
- **Maintainability** - Changes to implementation don't affect interface

### Advanced Class Features
- **Constructor overloading** - Multiple ways to create objects
- **Copy semantics** - Proper object copying
- **Method design** - Logical grouping of related operations

### Mathematical Programming
- **Fraction arithmetic** - Handling rational numbers with precision
- **Geometric calculations** - Real-world mathematical applications
- **Algorithm implementation** - GCD, area formulas, trigonometry

### Best Practices
- **Input validation** - Robust error handling
- **Const correctness** - Proper use of const methods
- **Memory management** - Constructor/destructor pairs
- **Documentation** - Clear comments and method descriptions

This laboratory establishes the foundation for professional C++ development by emphasizing clean code architecture and proper class design patterns.
