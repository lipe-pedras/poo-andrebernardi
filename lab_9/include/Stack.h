#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Stack
{
private:
    T *data;          // pointer to stack data
    int topPointer;   // stack top pointer
    int capacity;     // memory space reserved for the object

public:
    // Constructor with parameter
    Stack(int memory = 10)
    {
        topPointer = -1;
        capacity = (memory > 0) ? memory : 10;
        data = new T[capacity];
    }
    
    // Virtual destructor
    virtual ~Stack()
    {
        delete[] data;
    }
    
    // Pop element from stack
    bool pop(T &element)
    {
        if (isEmpty())
            return false;
        element = data[topPointer--];
        return true;
    }
    
    // Push element to stack
    bool push(const T &element)
    {
        if (isFull())
            return false;
        data[++topPointer] = element;
        return true;
    }
    
    // Copy constructor
    Stack(const Stack &other)
    {
        topPointer = other.topPointer;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i <= topPointer; i++)
        {
            data[i] = other.data[i];
        }
    }
    
    // Assignment operator
    Stack& operator=(const Stack &other)
    {
        if (this != &other) // Self-assignment check
        {
            delete[] data;
            topPointer = other.topPointer;
            capacity = other.capacity;
            data = new T[capacity];
            for (int i = 0; i <= topPointer; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    
    // Check if stack is empty
    bool isEmpty() const
    {
        return topPointer == -1;
    }
    
    // Check if stack is full
    bool isFull() const
    {
        return topPointer == capacity - 1;
    }
    
    // Get current size
    int size() const
    {
        return topPointer + 1;
    }
    
    // Get capacity
    int getCapacity() const
    {
        return capacity;
    }

    // Template friend functions for stream operators
    template <typename U>
    friend std::ostream& operator<<(std::ostream &out, const Stack<U> &stack);
    
    template <typename U>
    friend std::istream& operator>>(std::istream &in, Stack<U> &stack);
};

// Stream operators implementation
template <typename T>
std::ostream &operator<<(std::ostream &out, const Stack<T> &stack)
{
    out << "Stack [";
    for (int i = 0; i <= stack.topPointer; i++)
    {
        out << stack.data[i];
        if (i < stack.topPointer)
            out << ", ";
    }
    out << "]";
    return out;
}

template <typename T>
std::istream &operator>>(std::istream &in, Stack<T> &stack)
{
    T element;
    stack.topPointer = -1; // empty the stack
    std::cout << "Enter up to " << stack.capacity << " stack values: ";
    for (int i = 0; i < stack.capacity; i++)
    {
        in >> element;
        if (!stack.push(element))
            break; // if couldn't insert, abort
    }
    return in;
}

#endif