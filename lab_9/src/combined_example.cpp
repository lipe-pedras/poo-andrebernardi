#include <iostream>
#include <string>
#include "../include/Vector.h"
#include "../include/Stack.h"

using namespace std;

int main()
{
    cout << "=== Combined Data Structures Demo ===" << endl;
    
    // Create a vector of stacks
    cout << "\n--- Creating Vector of Integer Stacks ---" << endl;
    Vector<Stack<int>> vectorOfStacks(3);
    
    // Initialize each stack in the vector
    for (int i = 0; i < vectorOfStacks.getSize(); i++)
    {
        cout << "Initializing stack " << i << ":" << endl;
        for (int j = 1; j <= 3; j++)
        {
            vectorOfStacks[i].push((i + 1) * 10 + j);
        }
        cout << "Stack " << i << ": " << vectorOfStacks[i] << endl;
    }
    
    cout << "\nVector of stacks: " << vectorOfStacks << endl;
    
    // Test with custom data type
    cout << "\n--- Testing with String Vector ---" << endl;
    Vector<string> stringVector(4);
    
    cout << "Enter 4 strings:" << endl;
    cin >> stringVector;
    cout << "Original string vector: " << stringVector << endl;
    stringVector.sort();
    cout << "Sorted string vector: " << stringVector << endl;
    
    // Advanced template usage - Stack of Vectors
    cout << "\n--- Testing Stack of Integer Vectors ---" << endl;
    Stack<Vector<int>> stackOfVectors(3);
    
    // Create and push some vectors
    Vector<int> vec1(2);
    vec1[0] = 10; vec1[1] = 20;
    
    Vector<int> vec2(3);
    vec2[0] = 30; vec2[1] = 40; vec2[2] = 50;
    
    Vector<int> vec3(2);
    vec3[0] = 60; vec3[1] = 70;
    
    stackOfVectors.push(vec1);
    stackOfVectors.push(vec2);
    stackOfVectors.push(vec3);
    
    cout << "Stack of vectors: " << stackOfVectors << endl;
    
    // Pop and display vectors
    cout << "\nPopping vectors from stack:" << endl;
    Vector<int> poppedVector(1);
    while (!stackOfVectors.isEmpty())
    {
        if (stackOfVectors.pop(poppedVector))
        {
            cout << "Popped vector: " << poppedVector << endl;
        }
    }
    
    // Demonstrate exception handling with both classes
    cout << "\n--- Exception Handling Demo ---" << endl;
    try
    {
        Vector<int> testVector(-5);  // This should throw an exception
    }
    catch (const exception& e)
    {
        cout << "Vector exception caught: " << e.what() << endl;
    }
    
    try
    {
        Vector<int> testVector(3);
        cout << "Accessing valid index [1]: " << testVector[1] << endl;
        cout << "Trying to access invalid index [10]..." << endl;
        cout << testVector[10] << endl;  // This should throw an exception
    }
    catch (const exception& e)
    {
        cout << "Index exception caught: " << e.what() << endl;
    }
    
    // Memory management demonstration
    cout << "\n--- Memory Management Demo ---" << endl;
    {
        Vector<int> scopedVector(1000);  // Large vector
        Stack<double> scopedStack(500);  // Large stack
        cout << "Created large data structures in local scope" << endl;
    } // Destructors called automatically here
    cout << "Data structures destroyed automatically when leaving scope" << endl;
    
    return 0;
}