#include <iostream>
#include "LongInteger.h"

using namespace std;

int main() {
    cout << "=== LongInteger Demonstration ===" << endl;
    
    // Create some long integers
    LongInteger a("12345");
    LongInteger b("67890");
    LongInteger c("123321");  // Palindrome
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    
    // Test palindrome
    cout << "\nPalindrome test:" << endl;
    cout << "a is palindrome: " << (a.isPalindrome() ? "Yes" : "No") << endl;
    cout << "c is palindrome: " << (c.isPalindrome() ? "Yes" : "No") << endl;
    
    // Test arithmetic
    cout << "\nArithmetic operations:" << endl;
    LongInteger sum = a + b;
    cout << "a + b = " << sum << endl;
    
    // Test increment/decrement
    cout << "\nIncrement/Decrement operations:" << endl;
    cout << "Original a: " << a << endl;
    cout << "++a: " << ++a << endl;
    cout << "a++: " << a++ << endl;
    cout << "a after a++: " << a << endl;
    
    // Test comparison
    cout << "\nComparison operations:" << endl;
    cout << "a == b: " << (a == b ? "Yes" : "No") << endl;
    cout << "a < b: " << (a < b ? "Yes" : "No") << endl;
    cout << "a > b: " << (a > b ? "Yes" : "No") << endl;
    
    // Test user input
    cout << "\nEnter a long integer: ";
    LongInteger user_input;
    cin >> user_input;
    cout << "You entered: " << user_input << endl;
    cout << "Is palindrome: " << (user_input.isPalindrome() ? "Yes" : "No") << endl;
    
    return 0;
}