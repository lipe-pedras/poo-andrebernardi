#include <iostream>
#include "../include/Stack.h"

using namespace std;

int main()
{
    cout << "=== Advanced Data Structure Testing ===" << endl;
    
    // Create different types of stacks
    Stack<int> intStack(5);
    Stack<char> charStack(5);
    Stack<float> floatStack(5);
    Stack<Stack<int>> stackOfStacks(3);
    
    // Test integer stack
    cout << "\n--- Testing Integer Stack ---" << endl;
    cout << "Enter integers for the stack (-1 to stop):" << endl;
    cin >> intStack;
    cout << "Integer stack contents: " << intStack << endl;
    
    // Test char stack
    cout << "\n--- Testing Character Stack ---" << endl;
    cout << "Enter characters for the stack:" << endl;
    cin >> charStack;
    cout << "Character stack contents: " << charStack << endl;
    
    // Test float stack
    cout << "\n--- Testing Float Stack ---" << endl;
    cout << "Enter floats for the stack (-1 to stop):" << endl;
    cin >> floatStack;
    cout << "Float stack contents: " << floatStack << endl;
    
    // Test stack operations
    cout << "\n--- Testing Stack Operations ---" << endl;
    Stack<int> operationStack(10);
    
    // Push some values
    cout << "Pushing values 10, 20, 30, 40, 50..." << endl;
    operationStack.push(10);
    operationStack.push(20);
    operationStack.push(30);
    operationStack.push(40);
    operationStack.push(50);
    
    cout << "Stack after pushes: " << operationStack << endl;
    cout << "Stack size: " << operationStack.size() << endl;
    cout << "Stack capacity: " << operationStack.getCapacity() << endl;
    cout << "Is empty: " << (operationStack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is full: " << (operationStack.isFull() ? "Yes" : "No") << endl;
    
    // Pop some values
    int poppedValue;
    cout << "\nPopping values:" << endl;
    while (!operationStack.isEmpty())
    {
        if (operationStack.pop(poppedValue))
        {
            cout << "Popped: " << poppedValue << endl;
        }
    }
    
    cout << "Stack after all pops: " << operationStack << endl;
    cout << "Is empty: " << (operationStack.isEmpty() ? "Yes" : "No") << endl;
    
    // Test copy operations
    cout << "\n--- Testing Copy Operations ---" << endl;
    Stack<int> originalStack(5);
    originalStack.push(100);
    originalStack.push(200);
    originalStack.push(300);
    
    Stack<int> copiedStack = originalStack;  // Copy constructor
    Stack<int> assignedStack(3);
    assignedStack = originalStack;  // Assignment operator
    
    cout << "Original stack: " << originalStack << endl;
    cout << "Copied stack: " << copiedStack << endl;
    cout << "Assigned stack: " << assignedStack << endl;
    
    return 0;
}