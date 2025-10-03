#include <iostream>
#include "../include/stack.h"

using namespace std;

int main()
{
    Stack intStack;
    int aux;
    try
    {
        // using the integer stack
        cin >> intStack;
        cout << "Value at the top of the stack: " << intStack.pop(aux) << endl;
        cout << intStack;
    }
    catch (runtime_error &rt)
    {
        cout << rt.what() << endl;
    }
    return 0;
}
