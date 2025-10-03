// stack.h
// Header file for Stack class
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class Stack
{
private:
    int *data;          // pointer to stack data
    int stackPointer;   // pointer to the top of the stack
    int size;           // memory space reserved for the object
public:
    Stack(int memory = 0); // constructor with parameter
    virtual ~Stack(void);  // destructor
    int pop(int &pop_to);
    int push(int push_this);

    Stack(const Stack&);
    Stack& operator = (const Stack&);

    friend ostream& operator<< (ostream& , const Stack&);
    friend istream& operator>> (istream& , Stack&);
};

#endif
