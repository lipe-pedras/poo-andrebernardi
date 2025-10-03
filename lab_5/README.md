# Laboratory 5 - Advanced OOP Features

This laboratory explores advanced Object-Oriented Programming concepts including operator overloading, static members, and complex class interactions.

## 🏗️ Project Structure

```
lab_5/
├── include/           # Header files
│   ├── Complex.h      # Complex number class with full operator support
│   ├── Point.h        # Point class with increment/decrement operators
│   ├── Book.h         # Book management system
│   ├── Date.h         # Date class with validation
│   ├── Polynomial.h   # Polynomial arithmetic implementation
│   └── Fraction.h     # Enhanced fraction class
├── src/               # Source files
│   ├── Complex.cpp    # Complex number implementation
│   ├── Point.cpp      # Point class implementation
│   ├── Book.cpp       # Book management implementation
│   ├── Date.cpp       # Date class implementation
│   ├── Polynomial.cpp # Polynomial arithmetic implementation
│   ├── Fraction.cpp   # Fraction class implementation
│   ├── main_point.cpp          # Point demonstration program
│   ├── main_book.cpp           # Book demonstration program
│   ├── main_polynomial.cpp     # Polynomial demonstration program
│   ├── main_date.cpp           # Date demonstration program
│   └── main_fraction_complex.cpp # Fraction and Complex demonstration
├── build/             # Build directory (generated)
├── CMakeLists.txt     # CMake build configuration
└── README.md          # This file
```

## 🔧 Advanced Programming Concepts

### 1. Pre vs Post Increment/Decrement

```cpp
// Pre-increment: modify and return reference
Point& Point::operator++() {
    ++x;
    ++y;
    return *this;
}

// Post-increment: return copy, then modify
Point Point::operator++(int) {
    Point temp = *this;
    ++(*this);
    return temp;
}
```

## 🚀 Building and Running

### Using CMake

```bash
# Create build directory and navigate to it
mkdir build && cd build

# Generate build files
cmake ..

# Build all programs
make

# Or build individual programs
make point_demo
make book_demo
make polynomial_demo
make date_demo
make fraction_complex_demo

# Run demonstrations (from build directory)
./bin/point_demo           # Point manipulation and operators
./bin/book_demo            # Book management system
./bin/polynomial_demo      # Polynomial arithmetic
./bin/date_demo            # Date operations
./bin/fraction_complex_demo # Fraction and Complex operations
```

## 📚 Educational Value

This laboratory demonstrates:

### Advanced OOP Concepts
- **Operator overloading** - Making objects behave like built-in types
- **Static members** - Class-level data and functions
- **Type conversion** - Implicit and explicit conversions
- **Friend functions** - Controlled access to private members

### Professional Development Practices
- **Const correctness** - Proper use of const methods and parameters
- **RAII principles** - Resource Acquisition Is Initialization
- **Object lifecycle** - Constructor/destructor coordination
- **Stream integration** - Seamless I/O operations

### Mathematical Applications
- **Complex number arithmetic** - Real-world mathematical operations
- **Coordinate geometry** - Point manipulation and calculations
- **Polar coordinates** - Coordinate system conversions

### Software Design Patterns
- **Factory methods** - Different ways to create objects
- **Fluent interfaces** - Method chaining capabilities
- **State management** - Object counting and tracking

This laboratory represents a significant step toward mastery of C++ and object-oriented programming, combining theoretical concepts with practical applications in mathematics and data management.
