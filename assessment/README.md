# Assessment 1 - Advanced Object-Oriented Programming

This assessment demonstrates advanced Object-Oriented Programming concepts through the implementation of three comprehensive classes: LongInteger for arbitrary precision arithmetic, Polynomial for mathematical operations, and BimonthlyExam for educational management.

## 📋 Contents

### Core Classes
- **`LongInteger`** - Arbitrary precision integer arithmetic class
- **`Polynomial`** - Mathematical polynomial operations class  
- **`BimonthlyExam`** - Educational exam management class

### Demo Programs
- **`main_long_integer.cpp`** - LongInteger class demonstration
- **`main_polynomial.cpp`** - Polynomial class demonstration
- **`main_exam.cpp`** - BimonthlyExam class demonstration

## 🚀 Compilation and Usage

### Using Makefile (Recommended)
```bash
# Navigate to assessment directory
cd assessment

# Build all programs
make

# Run individual demonstrations
make run_long_integer    # LongInteger demo
make run_polynomial      # Polynomial demo  
make run_exam           # BimonthlyExam demo

# Run all demonstrations
make run_all

# Clean build files
make clean
```

## 🔧 Advanced Programming Concepts Demonstrated

### 1. Operator Overloading Mastery
```cpp
// Comprehensive operator sets for each class
LongInteger a, b;
a + b;    // Addition
++a;      // Pre-increment  
a++;      // Post-increment
a += b;   // Compound assignment
a == b;   // Equality comparison
cout << a; // Stream output
cin >> a;  // Stream input
```

### 2. Memory Management Excellence
```cpp
// RAII principles with std::vector
class LongInteger {
    std::vector<int> digits;  // Automatic memory management
    // No need for explicit new/delete
    // Automatic cleanup on destruction
};
```

### 3. Algorithm Implementation
```cpp
// Custom arithmetic for arbitrary precision
LongInteger LongInteger::operator+(const LongInteger &other) const {
    // Digit-by-digit addition with carry handling
    int carry = 0;
    for (size_t i = 0; i < max_size || carry; ++i) {
        int sum = carry;
        if (i < digits.size()) sum += digits[i];
        if (i < other.digits.size()) sum += other.digits[i];
        result.digits.push_back(sum % 10);
        carry = sum / 10;
    }
}
```

### 4. Mathematical Algorithm Integration
```cpp
// Horner's method for efficient polynomial evaluation
double Polynomial::evaluate(double x) const {
    double result = coefficients.back();
    for (int i = coefficients.size() - 2; i >= 0; --i) {
        result = result * x + coefficients[i];
    }
    return result;
}
```

## 📚 Educational Value

This assessment demonstrates:

### Object-Oriented Design Principles
- **Encapsulation** - Private data members with public interfaces
- **Data Abstraction** - Hide implementation details behind clean APIs
- **Operator Overloading** - Natural mathematical notation for custom types
- **Resource Management** - Proper constructor/destructor patterns

### Advanced C++ Features
- **STL Containers** - std::vector for dynamic storage
- **Stream Operators** - Custom input/output formatting
- **Const Correctness** - Proper const method declarations
- **Copy Semantics** - Safe object copying and assignment

### Algorithm and Data Structure Skills
- **Mathematical Algorithms** - Arbitrary precision arithmetic
- **String Processing** - Input validation and conversion
- **Sorting Algorithms** - Custom comparison operators
- **Memory Efficiency** - Dynamic resizing and management

### Software Engineering Practices
- **Code Organization** - Clean separation of interface and implementation
- **Error Handling** - Input validation and bounds checking
- **Documentation** - Clear method naming and functionality
