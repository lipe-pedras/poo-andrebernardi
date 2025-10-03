# Laboratory 4 - Comprehensive Operator Overloading

A complete C++ implementation demonstrating advanced operator overloading concepts through three mathematical classes: Complex numbers, Fractions, and Long integers.

## 📂 Project Structure

```
lab_4/
├── include/                    # Header files
│   ├── Complex.h              # Complex number class declaration
│   ├── Fraction.h             # Fraction class declaration
│   └── LongInteger.h          # Long integer class declaration
├── src/                       # Source files
│   ├── Complex.cpp            # Complex number implementation
│   ├── Fraction.cpp           # Fraction implementation
│   ├── LongInteger.cpp        # Long integer implementation
│   ├── main_Complex.cpp       # Complex number demonstration
│   ├── main_Fraction.cpp      # Fraction demonstration
│   └── main_LongInteger.cpp   # Long integer demonstration
├── build/                     # Build artifacts (auto-generated)
├── Makefile                   # Build automation
└── README.md                  # Project documentation
```

## 🎯 Learning Objectives

This laboratory demonstrates mastery of:

- **Complete Operator Overloading** - Arithmetic, comparison, and stream operators
- **Modern C++ Practices** - Clean code, const correctness, friend functions
- **Mathematical Programming** - Complex arithmetic, rational numbers, arbitrary precision
- **Professional Development** - Proper project structure, build automation, documentation

## 🔧 Quick Start

### Build All Programs

```bash
# Clone and navigate to the project
cd lab_4

# Build all programs
make all

# Run individual programs
make run-complex
make run-fraction  
make run-longinteger
```

### Build Individual Programs

```bash
# Build specific programs
make complex      # Complex number calculator
make fraction     # Fraction arithmetic
make longinteger  # Large integer operations

# Clean build artifacts
make clean

# Show available targets
make help
```

## 💡 Implementation Highlights

### Operator Overloading Best Practices

```cpp
// Arithmetic operators return new objects
Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imaginary + other.imaginary);
}

// Comparison operators for intuitive usage
bool Fraction::operator<(const Fraction& other) const {
    return (m_numerator * other.m_denominator) < 
           (other.m_numerator * m_denominator);
}

// Stream operators as friend functions
friend std::ostream& operator<<(std::ostream& out, const Complex& c);
friend std::istream& operator>>(std::istream& in, Complex& c);
```

### Memory Management

- **RAII Principles**: Proper constructor/destructor patterns
- **Static Tracking**: Automatic instance counting for Complex numbers
- **No Memory Leaks**: Stack-based allocation, automatic cleanup

### Error Handling

- **Division by Zero**: Proper error checking and messages
- **Input Validation**: Robust stream input handling
- **Boundary Conditions**: Safe array access in LongInteger

## 📊 Sample Output

### Complex Numbers
```
c1: 1 1i
c2: 2 4i
Sum: 3 5i
Subtraction: -1 -3i
Multiplication: -0.31611 6.31665i
Division: 0.289435 0.127386i
Modulus c1: 1.41421
Number of complex numbers stored: 3
```

### Fractions
```
Enter the numerator.
3
Enter the denominator.
4
Numerator F1 = 3
Denominator F1 = 4
Enter the numerator.
1
Enter the denominator.
2
Sum of F1 and F2: 5 / 4
F1 as Float: 0.75
F2 as Float: 0.5
```

### Long Integers
```
Enter the first number.
123456789012345678901234567890
Enter the second number.
987654321098765432109876543210

num1 = 123456789012345678901234567890
num2 = 987654321098765432109876543210
Sum: 1111111110111111111011111111100
Greater: 987654321098765432109876543210
num1 >= num2 0
are different
```

## 🛠️ Development Environment

### Compilation Flags
- `-std=c++11`: Enable C++11 features
- `-Wall -Wextra`: Enable comprehensive warnings
- `-Iinclude`: Include header directory

## 📚 Educational Value

This laboratory demonstrates:

### Advanced C++ Concepts
- **Operator overloading patterns**
- **Friend function usage**
- **Static member management**
- **Const correctness**
- **RAII principles**

### Mathematical Programming
- **Complex number arithmetic**
- **Rational number operations**
- **Arbitrary precision arithmetic**
- **Numerical stability considerations**

### Software Engineering
- **Clean project structure**
- **Build automation**
- **Code documentation**
- **Professional development practices**


