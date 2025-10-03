#ifndef VECTOR_H
#define VECTOR_H

#define DEFAULT_SIZE 10

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector
{
private:
    int size;
    T *data;

public:
    // Default constructor
    Vector()
    {
        size = DEFAULT_SIZE;
        data = new T[DEFAULT_SIZE];
        for (int i = 0; i < size; i++)
        {
            data[i] = T(); // Use default constructor for type T
        }
    }
    
    // Constructor with size parameter
    Vector(int _size)
    {
        if (_size <= 0)
        {
            throw std::invalid_argument("Vector size must be positive");
        }
        data = new T[_size];
        size = _size;
        for (int i = 0; i < size; i++)
        {
            data[i] = T(); // Use default constructor for type T
        }
    }
    
    // Virtual destructor
    virtual ~Vector() 
    { 
        delete[] data; 
    }
    
    // Copy constructor
    Vector(const Vector<T> &other)
    {
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }
    
    // Assignment operator
    Vector &operator=(const Vector &other)
    {
        if (this != &other) // Self-assignment check
        {
            delete[] data; // Clean up existing memory
            size = other.size;
            data = new T[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Array access operator with bounds checking
    T &operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return data[index];
        }
        else
        {
            throw std::out_of_range("Index out of boundaries!");
        }
    }
    
    // Const array access operator
    const T &operator[](int index) const
    {
        if (index >= 0 && index < size)
        {
            return data[index];
        }
        else
        {
            throw std::out_of_range("Index out of boundaries!");
        }
    }
    
    // Bubble sort implementation
    void sort()
    {
        T temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (data[j] > data[j + 1])
                {
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }
    
    // Get size of vector
    int getSize() const
    {
        return size;
    }
    
    // Output stream operator
    friend std::ostream &operator<<(std::ostream &out, const Vector<T> &vector)
    {
        out << "[";
        for (int i = 0; i < vector.size; i++)
        {
            out << vector.data[i];
            if (i < vector.size - 1)
                out << ", ";
        }
        out << "]";
        return out;
    }

    // Input stream operator
    friend std::istream &operator>>(std::istream &in, Vector<T> &vector)
    {
        std::cout << "Enter " << vector.size << " values:\n";
        for (int i = 0; i < vector.size; i++)
        {
            std::cout << "Element " << i << ": ";
            in >> vector.data[i];
        }
        return in;
    }
};

#endif