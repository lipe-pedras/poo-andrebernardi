# Laboratory 9 - Generic Data Structures

A comprehensive C++ project demonstrating advanced template programming, generic data structures, and modern C++ design patterns with complete memory management and exception handling.

## 🏗️ Project Structure

```
lab_9/
├── include/           # Header files
│   ├── Vector.h      # Template vector class
│   └── Stack.h       # Template stack class
├── src/              # Source files
│   ├── Stack.cpp           # Stack implementation
│   ├── vector_example.cpp  # Vector demonstration
│   ├── stack_example.cpp   # Stack demonstration
│   └── combined_example.cpp # Advanced usage examples
├── build/            # Build output directory
├── Makefile          # Build configuration
└── README.md         # This file
```

## 📋 Contents

### Core Classes

#### Vector Class (`Vector.h`)
A complete template-based dynamic array implementation featuring:
- **Generic Type Support**: Works with any type T supporting comparison and assignment
- **Dynamic Memory Management**: Proper allocation and deallocation with RAII
- **Exception Safety**: Bounds checking with meaningful error messages
- **Copy Semantics**: Deep copying with proper copy constructor and assignment operator
- **Sorting Algorithm**: Built-in bubble sort implementation
- **Stream Operations**: Input/output operators for easy I/O

#### Stack Class (`Stack.h` / `Stack.cpp`)
An enhanced template-based stack implementation featuring:
- **Generic Type Support**: Template-based for type safety
- **Capacity Management**: Configurable stack size with full/empty checking
- **Exception Safety**: Robust error handling and memory management
- **Copy Operations**: Proper deep copying support
- **Stream Operations**: Convenient input/output functionality

### Example Programs

#### `vector_example.cpp`
Demonstrates Vector class capabilities:
- Basic vector operations (creation, input, output)
- Sorting functionality
- Exception handling for out-of-bounds access
- Copy constructor and assignment operator usage

#### `stack_example.cpp`
Showcases Stack class features:
- Multiple stack types (int, char, float)
- Push/pop operations
- Stack state checking (empty, full, size)
- Copy operations demonstration

#### `combined_example.cpp`
Advanced template usage examples:
- Vector of Stacks
- Stack of Vectors
- String vector operations
- Complex nested data structures
- Comprehensive exception handling

## 🔧 Building the Project

### Build Commands

```bash
# Build all examples
make all

# Build individual examples
make vector      # Vector example only
make stack       # Stack example only  
make combined    # Combined example only

# Build and run examples
make run-vector     # Build and run vector example
make run-stack      # Build and run stack example
make run-combined   # Build and run combined example
make run-all        # Build and run all examples

# Build variants
make debug          # Debug build with symbols
make release        # Optimized release build

# Cleanup
make clean          # Remove object files
make clean-all      # Remove all build files
make distclean      # Remove entire build directory
```

## � Usage Examples

### Vector Usage
```cpp
#include "Vector.h"

// Create vectors of different types
Vector<int> intVec(5);
Vector<double> doubleVec(3);
Vector<string> stringVec(4);

// Input and output
cin >> intVec;
cout << "Vector: " << intVec << endl;

// Sorting
intVec.sort();

// Safe element access with bounds checking
try {
    cout << intVec[0] << endl;  // Safe access
    cout << intVec[10] << endl; // Throws exception
} catch (const out_of_range& e) {
    cout << "Error: " << e.what() << endl;
}
```

### Stack Usage
```cpp
#include "Stack.h"

// Create stack with capacity of 10
Stack<int> intStack(10);

// Push elements
intStack.push(10);
intStack.push(20);
intStack.push(30);

// Pop elements
int value;
while (!intStack.isEmpty()) {
    if (intStack.pop(value)) {
        cout << "Popped: " << value << endl;
    }
}

// Check stack state
cout << "Size: " << intStack.size() << endl;
cout << "Capacity: " << intStack.getCapacity() << endl;
cout << "Is full: " << intStack.isFull() << endl;
```

### Advanced Template Usage
```cpp
// Vector of Stacks
Vector<Stack<int>> vectorOfStacks(3);

// Stack of Vectors
Stack<Vector<int>> stackOfVectors(5);

// Custom types
struct Point {
    double x, y;
    bool operator>(const Point& other) const {
        return (x*x + y*y) > (other.x*other.x + other.y*other.y);
    }
};

Vector<Point> points(10);
points.sort(); // Sort by distance from origin
```

## 🎯 Key Features

### Template Programming
- **Generic Design**: Classes work with any type meeting basic requirements
- **Type Safety**: Compile-time type checking prevents runtime errors
- **Code Reusability**: Single implementation supports multiple data types
- **STL Compatibility**: Design follows standard library conventions

### Memory Management
- **RAII Compliance**: Resources managed through object lifetime
- **Exception Safety**: Strong exception safety guarantees
- **Deep Copying**: Proper copy semantics for dynamic memory
- **Leak Prevention**: Automatic cleanup in destructors

### Error Handling
- **Bounds Checking**: Array access validation with meaningful errors
- **Exception Safety**: Functions provide strong exception guarantees
- **Resource Safety**: No memory leaks even when exceptions occur
- **Input Validation**: Constructor parameter validation

## 📚 Educational Objectives

This laboratory demonstrates mastery of:

1. **Advanced Template Programming**
   - Generic class design and implementation
   - Template instantiation and specialization
   - Template friend functions and operators

2. **Memory Management Excellence**
   - Dynamic memory allocation and deallocation
   - RAII (Resource Acquisition Is Initialization)
   - Exception-safe resource management

3. **Modern C++ Design Patterns**
   - Copy semantics (copy constructor, assignment operator)
   - Operator overloading for natural syntax
   - Stream integration for I/O operations

4. **Software Engineering Best Practices**
   - Modular design with proper separation of concerns
   - Comprehensive error handling and validation
   - Clear API design with intuitive interfaces

5. **Data Structure Implementation**
   - Generic container design principles
   - Algorithm integration (sorting, searching)
   - Performance considerations and optimizations