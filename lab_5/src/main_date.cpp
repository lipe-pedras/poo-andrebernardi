#include "Date.h"
#include <iostream>
using namespace std;

int main() {
    // Test default constructor
    Date d1;
    cout << "Default Constructor: " << d1 << endl;

    // Test constructor with parameters
    Date d2(25, 12, 2023);
    cout << "Constructor with parameters: " << d2 << endl;

    // Test input operator (operator>>)
    cout << "Enter a date (DD MM YYYY): ";
    cin >> d1;
    cout << "You entered: " << d1 << endl;

    // Test pre-increment operator (operator++)
    ++d1;
    cout << "After pre-increment: " << d1 << endl;

    // Test post-increment operator (operator++)
    d1++;
    cout << "After post-increment: " << d1 << endl;

    // Test pre-decrement operator (operator--)
    --d2;
    cout << "After pre-decrement: " << d2 << endl;

    // Test post-decrement operator (operator--)
    d2--;
    cout << "After post-decrement: " << d2 << endl;

    return 0;
}