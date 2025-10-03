# Object-Oriented Programming with C++
**Educational Portfolio - Mastering OOP Concepts and C++ Programming**

[![C++](https://img.shields.io/badge/C%2B%2B-11%2F14%2F17-blue.svg)](https://isocpp.org/)
[![Build](https://img.shields.io/badge/build-passing-brightgreen.svg)](https://github.com/lipe-pedras/poo-andrebernardi)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)

---

## 🎯 About This Repository

This repository documents my comprehensive learning journey through Object-Oriented Programming using C++. It contains 9 progressive laboratory exercises and 1 final assessment project, each building upon previous concepts to demonstrate mastery of OOP principles and advanced C++ programming techniques.

The projects showcase the evolution from basic class concepts to sophisticated template programming, demonstrating both theoretical understanding and practical implementation skills essential for professional C++ development.

---

## 📚 Learning Journey Structure

This repository contains 10 projects that demonstrate progressive mastery of Object-Oriented Programming:

| Project | Focus Area | Key Learning |
|---------|------------|--------------|
| **lab_1** | Class Fundamentals | Basic class design, constructors, encapsulation |
| **lab_2** | Operator Overloading | Arithmetic, comparison, and stream operators |
| **lab_3** | Mathematical Computing | Complex numbers, arbitrary precision arithmetic |
| **lab_4** | Advanced Operators | Complete operator suites, increment/decrement |
| **lab_5** | Multi-Class Systems | Class interaction, CMake build systems |
| **lab_6** | Data Validation | String processing, input validation |
| **lab_7** | Inheritance & Polymorphism | Class hierarchies, virtual functions |
| **lab_8** | Data Structures | Custom containers, template introduction |
| **lab_9** | Template Programming | Generic programming, STL-style design |
| **assessment** | Integration Project | Professional-level implementation |

*Each project contains its own detailed README with specific implementation details and usage examples.*

---

## 🛠️ Building and Running

### Prerequisites
- **C++ Compiler**: GCC 7.0+ or Clang 6.0+ with C++11/14/17 support
- **Build Tools**: Make (for most projects), CMake 3.16+ (for lab_5)
- **Operating System**: Linux, macOS, or Windows with appropriate toolchain

### Quick Start
```bash
# Clone the repository
git clone https://github.com/lipe-pedras/poo-andrebernardi.git
cd poo-andrebernardi

# Build and run any laboratory (example: lab_1)
cd lab_1
make
./build/rectangle_demo

# For CMake projects (lab_5)
cd lab_5
mkdir build && cd build
cmake ..
make
./bin/point_demo
```

### Build System Overview
- **Labs 1-4, 6-9 and Assessment**: Makefile-based build system
- **Lab 5**: CMake build system with multiple targets

---

## 🧠 Object-Oriented Programming Concepts Mastered

### Core OOP Principles
**Encapsulation**
- Data hiding through private/protected access modifiers
- Clean public interfaces with controlled access
- Implementation details separated from interface

**Inheritance**
- Single and multiple inheritance hierarchies
- Base and derived class relationships
- Code reuse through inheritance

**Polymorphism**
- Virtual functions and dynamic binding
- Abstract base classes and pure virtual functions
- Runtime type resolution

**Abstraction**
- Interface design and implementation separation
- Abstract data types and their implementations
- Clean API design principles

### Advanced C++ Programming Features

**Operator Overloading**
```cpp
// Comprehensive operator support across multiple classes
class Complex {
public:
    Complex operator+(const Complex& other) const;      // Binary arithmetic
    Complex& operator+=(const Complex& other);          // Compound assignment
    Complex& operator++();                              // Pre-increment
    Complex operator++(int);                           // Post-increment
    friend ostream& operator<<(ostream&, const Complex&); // Stream output
    bool operator==(const Complex& other) const;       // Comparison
};
```

**Template Programming**
```cpp
// Generic programming with templates
template<typename T>
class Vector {
    T* data;
    size_t capacity, size;
public:
    T& operator[](size_t index);
    void push_back(const T& value);
    T pop_back();
    // STL-compatible interface design
};
```

**Memory Management and RAII**
```cpp
// Resource Acquisition Is Initialization
class LongInteger {
private:
    std::vector<int> digits;  // Automatic memory management
public:
    LongInteger(const LongInteger& other);           // Copy constructor
    LongInteger& operator=(const LongInteger& other); // Assignment operator
    ~LongInteger();                                  // Destructor
    // Rule of Three implementation
};
```

**Constructor and Destructor Patterns**
- Default constructors and parameterized constructors
- Copy constructors and assignment operators
- Virtual destructors for inheritance hierarchies
- Constructor initialization lists

---

## 🎯 Learning Outcomes

This portfolio demonstrates mastery of:

### Core Object-Oriented Principles
- ✅ **Encapsulation** - Data hiding and interface design
- ✅ **Inheritance** - Class hierarchies and code reuse
- ✅ **Polymorphism** - Virtual functions and dynamic dispatch
- ✅ **Abstraction** - Clean interface design and implementation hiding

### Advanced C++ Programming
- ✅ **Template Programming** - Generic code design and implementation
- ✅ **Operator Overloading** - Natural syntax for user-defined types
- ✅ **Memory Management** - RAII, smart pointers, and resource safety
- ✅ **STL Integration** - STL-compatible design patterns

### Software Development Skills
- ✅ **Build Systems** - Make and CMake proficiency
- ✅ **Code Organization** - Modular design and clean architecture
- ✅ **Documentation** - Professional README files and code comments
- ✅ **Testing** - Comprehensive example programs and validation

### Mathematical and Algorithmic Competency
- ✅ **Numerical Computing** - Precise mathematical implementations
- ✅ **Data Structures** - Custom container design and algorithms
- ✅ **Algorithm Implementation** - Efficient computational methods
- ✅ **Problem Solving** - Real-world application development

---

## 🔧 Development Environment

### Recommended Setup
```bash
# Development tools
sudo apt install build-essential cmake gdb valgrind

# Code formatting and analysis
sudo apt install clang-format cppcheck

# Documentation generation
sudo apt install doxygen graphviz
```

### IDE Integration
- **VS Code**: Excellent C++ support with extensions
- **CLion**: Professional C++ IDE with CMake integration
- **Code::Blocks**: Lightweight IDE with project management
- **Terminal**: All projects support command-line development

---

## 📊 Project Statistics

| Metric | Value |
|--------|-------|
| **Total Lines of Code** | ~8,000+ |
| **Number of Classes** | 25+ |
| **Projects Completed** | 10 |
| **C++ Standards Used** | C++11, C++14, C++17 |
| **Build Systems** | Make, CMake |
| **Documentation Files** | 10 README files |

---

## � C++ Programming Skills Demonstrated

### Language Features Mastered
**Modern C++ Standards (C++11/14/17)**
- `auto` keyword for type deduction
- Range-based for loops
- Uniform initialization syntax
- `nullptr` instead of NULL
- Default and delete keywords for constructors

**STL Integration**
- `std::vector` for dynamic arrays
- `std::string` for string manipulation
- STL algorithms and iterators
- Container-compatible class design

**Exception Handling**
- Custom exception classes
- Exception safety guarantees
- RAII for exception-safe resource management
- Proper error propagation

**Advanced Class Design**
- Friend functions and classes
- Static members and methods
- Const correctness throughout
- Method overloading and overriding

---

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

**⭐ Star this repository if it helped you learn Object-Oriented Programming!**

*This portfolio represents a comprehensive journey through Object-Oriented Programming with C++, demonstrating both theoretical understanding and practical implementation skills essential for professional software development.*
