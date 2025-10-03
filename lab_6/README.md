# Laboratory 6 - Object-Oriented Programming with C++

This laboratory demonstrates advanced object-oriented programming concepts in C++ including operator overloading, inheritance hierarchies, mathematical computations, and input validation. The project showcases three main areas: polynomial mathematics, Brazilian phone number validation, and geometric inheritance patterns.

## 📋 Project Structure

```
lab_6/
├── include/                    # Header files
│   ├── Polynomial.h           # Polynomial class declaration
│   ├── PhoneNumber.h          # Phone number class declaration
│   └── Geometry.h             # Geometric hierarchy classes
├── src/                       # Source files
│   ├── Polynomial.cpp         # Polynomial implementation
│   ├── PhoneNumber.cpp        # Phone number implementation
│   ├── Geometry.cpp           # Geometric classes implementation
│   ├── main_polynomial.cpp    # Polynomial demo program
│   ├── main_phone_number.cpp  # Phone validation demo program
│   └── main_geometry.cpp      # Inheritance demo program
├── build/                     # Compiled executables (generated)
├── Makefile                   # Build system
└── README.md                  # This documentation
```

## 🎯 Core Components

### 1. **Polynomial Mathematics System** (`Polynomial.h/cpp`)
- Dynamic coefficient management with proper memory handling
- Mathematical operations: derivative calculation, evaluation, root finding
- Newton's method implementation for numerical root finding
- Comprehensive operator overloading (+, -, =, ==, <, >, [], <<, >>)

### 2. **Brazilian Phone Number Validator** (`PhoneNumber.h/cpp`)
- Validation for Brazilian phone number formats
- Support for 8-digit (landline) and 9-digit (mobile) numbers
- Automatic formatting with area codes
- Input validation and error handling

### 3. **Inheritance Hierarchies** (`Geometry.h/cpp`)
- **Political hierarchy**: Politician → President → Governor → Mayor
- **Geometric hierarchy**: Point → Circle → Cylinder
- Demonstrates constructor/destructor chains and virtual functions
- Stream operator overloading for interactive input/output

## 🚀 Quick Start

### Compilation
```bash
# Compile all programs
make all

# Or compile individual programs
make polynomial  # Polynomial mathematics demo
make phone      # Phone number validation demo  
make geometry   # Inheritance hierarchy demo
```

### Running the Programs
```bash
# Run all demonstrations
make run-all

# Or run individual programs
make run-polynomial
make run-phone
make run-geometry

# Or run directly from build directory
./build/polynomial_demo
./build/phone_demo
./build/geometry_demo
```

### Cleaning Up
```bash
make clean  # Remove build directory and compiled files
```


## 🔧 Key Programming Concepts Demonstrated

### 1. Dynamic Memory Management
```cpp
Polynomial::Polynomial(const Polynomial &other) {
    degree = other.degree;
    coefficients = new double[degree + 1];
    memcpy(coefficients, other.coefficients, (degree + 1) * sizeof(double));
}

Polynomial::~Polynomial() {
    delete[] coefficients;  // Proper cleanup
}

Polynomial Polynomial::operator=(const Polynomial &other) {
    if (this != &other) {   // Avoid self-assignment
        delete[] coefficients;
        degree = other.degree;
        coefficients = new double[degree + 1];
        memcpy(coefficients, other.coefficients, (degree + 1) * sizeof(double));
    }
    return *this;
}
```

### 2. Input Validation and Error Handling
```cpp
bool PhoneNumber::isValidAreaCode(const string &area) const {
    return area.length() == 2 && 
           area.find_first_not_of("0123456789") == string::npos;
}

bool PhoneNumber::isValidNumber(const string &num) const {
    return (num.length() == 8 || num.length() == 9) && 
           num.find_first_not_of("0123456789") == string::npos;
}

PhoneNumber::PhoneNumber(const string &area, const string &num) 
    : areaCode(area), number(num) {
    if (!isValidAreaCode(area) || !isValidNumber(num)) {
        throw invalid_argument("Invalid phone number format");
    }
}
```

### 3. Mathematical Algorithm Implementation
```cpp
Polynomial Polynomial::derivative() const {
    if (degree == 0) {
        Polynomial deriv(0);
        deriv.coefficients[0] = 0;  // Derivative of constant is zero
        return deriv;
    }
    
    Polynomial deriv(degree - 1);
    for (int i = 1; i <= degree; i++) {
        deriv.coefficients[i - 1] = i * coefficients[i];  // Power rule
    }
    return deriv;
}

double Polynomial::newtonMethod(double x0, int maxIter, double epsilon) const {
    Polynomial derivativePolynomial = derivative();
    double x = x0;
    
    for (int i = 0; i < maxIter; i++) {
        double p_x = evaluate(x);
        double p_prime_x = derivativePolynomial.evaluate(x);
        
        if (fabs(p_prime_x) < epsilon) {
            cout << "Derivative too close to zero. Newton's method may fail.\n";
            break;
        }
        
        double x_next = x - p_x / p_prime_x;  // Newton's formula
        
        if (fabs(x_next - x) < epsilon) {
            return x_next;  // Converged
        }
        
        x = x_next;
    }
    
    return x;  // Return best approximation
}
```

### 4. Inheritance and Polymorphism
```cpp
class Circle : public Point {  // Inheritance from Point
public:
    double radius;
    
    Circle(double x = 0, double y = 0, double radius = 0) 
        : Point(x, y), radius(radius) {}  // Constructor delegation
    
    double area() const {
        return M_PI * radius * radius;
    }
    
    // Operator overloading for input/output
    friend ostream &operator<<(ostream &os, const Circle &c) {
        os << "Center: " << static_cast<Point>(c) << ", Radius: " << c.radius;
        return os;
    }
};

class Cylinder : public Circle {  // Multi-level inheritance
public:
    double height;
    
    double volume() const {
        return area() * height;  // Uses inherited area() method
    }
    
    double surfaceArea() const {
        return 2 * area() + 2 * M_PI * radius * height;
    }
};
```

## 📚 Educational Value & Professional Skills

This laboratory demonstrates essential programming concepts for professional software development:

### Core OOP Principles
- **Encapsulation** - Private data members with controlled access through public methods
- **Inheritance** - Multi-level inheritance hierarchies with proper constructor/destructor chains
- **Polymorphism** - Virtual function behavior and method overriding
- **Abstraction** - Clean interfaces hiding implementation complexity

### Advanced C++ Features
- **Operator Overloading** - Custom behavior for +, -, =, ==, <, >, [], <<, >> operators
- **Dynamic Memory Management** - Proper allocation, deallocation, and copy semantics
- **Constructor Delegation** - Base class constructor calling in derived classes
- **Exception Handling** - Input validation with exception throwing and catching
- **Friend Functions** - Stream operators with access to private members

### Software Engineering Best Practices
- **Project Organization** - Professional directory structure (include/, src/, build/)
- **Build Systems** - Comprehensive Makefile with multiple targets and help system
- **Code Documentation** - Detailed comments and function documentation  
- **Input Validation** - Comprehensive format checking and error reporting
- **Memory Safety** - RAII principles, proper copy constructors, and assignment operators
- **Error Recovery** - Graceful handling of invalid input with meaningful error messages
