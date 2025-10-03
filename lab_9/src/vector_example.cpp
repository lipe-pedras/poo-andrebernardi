#include <iostream>
#include "../include/Vector.h"

using namespace std;

int main()
{
    // Create integer vector with 5 elements
    Vector<int> intVector(5);
    
    // Create double vector with 3 elements  
    Vector<double> doubleVector(3);

    // Test integer vector
    cout << "=== Testing Integer Vector ===" << endl;
    cin >> intVector;
    cout << "Original vector: " << intVector << endl;
    intVector.sort();
    cout << "Sorted vector: " << intVector << endl << endl;

    // Test double vector
    cout << "=== Testing Double Vector ===" << endl;
    cin >> doubleVector;
    cout << "Original vector: " << doubleVector << endl;
    doubleVector.sort();
    cout << "Sorted vector: " << doubleVector << endl << endl;

    // Test exception handling
    cout << "=== Testing Exception Handling ===" << endl;
    try
    {
        cout << "Trying to access invalid index (5) in double vector: ";
        cout << doubleVector[5] << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error caught: " << e.what() << endl;
    }
    
    // Test copy constructor and assignment
    cout << "\n=== Testing Copy Operations ===" << endl;
    Vector<int> copiedVector = intVector;  // Copy constructor
    cout << "Copied vector: " << copiedVector << endl;
    
    Vector<int> assignedVector(3);
    assignedVector = intVector;  // Assignment operator
    cout << "Assigned vector: " << assignedVector << endl;
    
    return 0;
}