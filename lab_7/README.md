# Lab 7 - Inheritance and Polymorphism

**Object-Oriented Programming Laboratory - All code translated to English**

This laboratory demonstrates advanced Object-Oriented Programming concepts using inheritance hierarchies and polymorphism in C++. The project has been completely translated to English and organized with a clean structure.

## 📁 Project Structure

```
lab_7/
├── include/
│   └── classes.h          # All class definitions
├── src/
│   ├── politicians.cpp    # Political hierarchy demo
│   └── geometry.cpp       # Geometric shapes demo
├── build/                 # Compiled executables
├── Makefile              # Build system
└── README.md             # This file
```

## 🏗️ Build and Run

### Quick Start
```bash
# Navigate to lab_7 directory
cd lab_7

# Build both programs
make

# Run the politicians demo
./build/politicians

# Run the geometry demo
./build/geometry

# Clean build files
make clean
```

## 🎯 Learning Objectives

### 1. Political Hierarchy System (`politicians.cpp`)

**Class Hierarchy:**
```
Politician (base class)
    ↓
President (inherits from Politician)
    ↓
Governor (inherits from President)
    ↓
Mayor (inherits from Governor)
```

**Key Features:**
- Multi-level inheritance chain
- Virtual functions for polymorphic behavior
- Virtual destructors for proper cleanup
- Method overriding at each inheritance level
- Stream operators for input/output

### 2. Geometric Shape System (`geometry.cpp`)

**Class Hierarchy:**
```
Point (base class)
    ↓
Circle (inherits from Point)
    ↓
Cylinder (inherits from Circle)
```

## 🔧 Technical Concepts Demonstrated

### Inheritance
- **Single inheritance:** Each class inherits from one parent
- **Multi-level inheritance:** Deep hierarchy chains
- **Method inheritance:** Child classes inherit parent methods
- **Attribute inheritance:** Child classes inherit parent data

### Polymorphism
- **Virtual functions:** Runtime method resolution
- **Method overriding:** Specialized behavior in derived classes
- **Dynamic binding:** Correct method called based on object type
- **Polymorphic containers:** Store different types in same container

### Memory Management
- **Dynamic allocation:** Using `new` for object creation
- **Virtual destructors:** Proper cleanup in inheritance hierarchies
- **Memory cleanup:** Using `delete` to prevent memory leaks
- **Container management:** Proper cleanup of vector contents

### Advanced C++ Features
- **Stream operators:** Custom `<<` and `>>` operators
- **Friend functions:** Access to private/protected members
- **Static casting:** Safe type conversions in inheritance
- **Override keyword:** Explicit method overriding

## 📊 Example Output

### Politicians Demo
```
A politician was created.
Enter the politician's name and party:
Alice Johnson Democrat
A president was created.
Enter the president's country:
USA

A politician was created.
Enter the politician's name and party:
Bob Smith Republican
A president was created.
Enter the president's country:
USA
A governor was created.
Enter the governor's state:
California

Printing all created politicians:
Name: Alice Johnson, Party: Democrat, Country: USA
Name: Bob Smith, Party: Republican, Country: USA, State: California

A president was destroyed.
A politician was destroyed.
A governor was destroyed.
A president was destroyed.
A politician was destroyed.
```

### Geometry Demo
```
Enter the X and Y values.
0 0
Enter the radius value.
3

Enter the X and Y values.
1 1
Enter the radius value.
2
Enter the height.
5

Printing all created objects:
Center: (0, 0), Radius: 3
Base = { Center: (1, 1), Radius: 2 } | Height: 5
```

## 🎓 Educational Value

This laboratory teaches:

1. **Object-Oriented Design**
   - Modeling real-world relationships through inheritance
   - Creating flexible and extensible class hierarchies
   - Understanding "is-a" relationships vs "has-a" relationships

2. **C++ Advanced Features**
   - Virtual function tables and dynamic dispatch
   - Proper resource management with virtual destructors
   - Stream operator overloading for custom types
   - Friend functions for controlled access

3. **Software Engineering Principles**
   - Code organization and structure
   - Separation of interface and implementation
   - Polymorphic programming patterns
   - Memory safety and leak prevention

4. **Problem Solving Skills**
   - Hierarchical thinking and modeling
   - Interface design and implementation
   - Testing and debugging inheritance hierarchies
