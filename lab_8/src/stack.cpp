#include "../include/stack.h"
#include <stdexcept>

using namespace std;

Stack::Stack(int memory)
{
    stackPointer = -1;
    size = (memory > 0) ? memory : 10;
    data = new int[size];
}

Stack::~Stack()
{
    delete[] data;
}

int Stack::pop(int &pop_to)
{
    if (stackPointer == -1)
    {
        throw runtime_error("The stack is already empty!");
    }
    else
    {
        pop_to = data[stackPointer--];
        return pop_to;
    }
}

int Stack::push(int value)
{
    if (stackPointer == size - 1)
    {
        throw runtime_error("Stack is full!");
    }
    else
    {
        data[++stackPointer] = value;
        return value;
    }
}

Stack::Stack(const Stack &s)
{
    stackPointer = s.stackPointer;
    size = s.size;
    data = new int[size];
    for (int i = 0; i < size + 1; i++)
    {
        data[i] = s.data[i];
    }
}

Stack &Stack::operator=(const Stack &s)
{
    delete[] data;
    stackPointer = s.stackPointer;
    size = s.size;
    data = new int[size];
    for (int i = 0; i < size + 1; i++)
    {
        data[i] = s.data[i];
    }
    return *this;
}

ostream& operator<< (ostream& out, const Stack& s)
{
    for (int i = 0; i <= s.stackPointer; i++)
    {
        out << s.data[i] << " ";
    }
    return out;
}

istream& operator>> (istream& in, Stack& s)
{
    int a;
    s.stackPointer = -1;
    cout << "Enter the stack data: ";
    try
    {
        for (int i = 0; i < s.size; i++)
        {
            in >> a;
            s.push(a);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return in;
}
