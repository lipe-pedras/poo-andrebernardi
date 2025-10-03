# Laboratory 3 - Advanced Class Operations

This laboratory focuses on implementing advanced class operations with complex mathematical types, emphasizing operator overloading and class interaction patterns.


## � Project Structure

```
lab_3/
├── include/                    # Header files
│   ├── complex.h              # Complex number class declarations
│   ├── long_integer.h         # Long integer class declarations
│   └── right_triangle.h       # Right triangle class declarations
├── src/                       # Source files
│   ├── complex.cpp            # Complex number implementation
│   ├── long_integer.cpp       # Long integer implementation
│   ├── right_triangle.cpp     # Right triangle implementation
│   ├── main_complex.cpp       # Complex number demonstration
│   ├── main_long_integer.cpp  # Long integer arithmetic testing
│   └── main_right_triangle.cpp # Right triangle calculations
├── build/                     # Build output directory
├── Makefile                   # Build configuration
└── README.md                  # This file
```

## 📋 Contents

### Core Classes
- **`Complex`** - Complex number class with comprehensive mathematical operations
- **`LongInteger`** - Long integer implementation for arbitrary precision arithmetic
- **`RightTriangle`** - Right triangle class with geometric validations and calculations

## 🔧 Key Programming Concepts

### Static Member Usage
```cpp
// Static member for object counting
unsigned int Complex::count = 0;

// Constructor increments count
Complex::Complex() {
    count++;
    real = 1;
    imaginary = 1;
}

// Destructor decrements count
Complex::~Complex() {
    count--;
}
```

## 🚀 Compilation and Usage

This project uses a Makefile for easy compilation and execution.

### Building All Programs
```bash
# Navigate to lab_3 directory
cd lab_3

# Build all programs
make all
```

### Building Individual Programs
```bash
# Build complex number program
make complex

# Build long integer program
make long_integer

# Build right triangle program
make right_triangle
```

### Running Programs
```bash
# Run complex number demonstration
make run-complex

# Run long integer testing
make run-long-integer

# Run right triangle calculations
make run-right-triangle
```

### Clean Build Files
```bash
make clean
```

### Available Makefile Targets
```bash
make help  # Show all available targets
```

Available targets:
- `all` - Build all programs
- `complex` - Build complex numbers program
- `long_integer` - Build long integer program  
- `right_triangle` - Build right triangle program
- `run-complex` - Build and run complex numbers program
- `run-long-integer` - Build and run long integer program
- `run-right-triangle` - Build and run right triangle program
- `clean` - Remove all built files
- `help` - Show help message

## 📚 Educational Value

This laboratory demonstrates:

### Advanced Mathematical Programming
- **Complex number theory** - Real-world mathematical modeling
- **Arbitrary precision arithmetic** - Handling computational limitations
- **Geometric algorithms** - Spatial mathematics implementation

### Object-Oriented Design Patterns
- **Static members** - Class-level data management
- **Operator overloading** - Natural mathematical notation
- **Error handling** - Division by zero, invalid operations
- **Type conversion** - Coordinate system transformations

### Algorithm Implementation
- **Polar conversion** - Trigonometric calculations
- **String parsing** - Converting text to numerical data
- **Geometric validation** - Triangle inequality theorem
- **Precision arithmetic** - Digit-by-digit operations

### Software Engineering Skills
- **Mathematical accuracy** - Proper handling of floating-point operations
- **Input validation** - Robust error checking
- **Code reusability** - Generic mathematical operations
- **Performance considerations** - Efficient algorithms for large numbers

This laboratory bridges theoretical mathematics with practical programming, demonstrating how object-oriented programming can elegantly model complex mathematical concepts while maintaining code clarity and reusability.