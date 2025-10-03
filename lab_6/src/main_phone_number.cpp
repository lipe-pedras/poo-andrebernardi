/**
 * @file main_phone_number.cpp
 * @brief Demonstration program for the PhoneNumber class
 * 
 * This program demonstrates the PhoneNumber class functionality including
 * input validation, formatting, and output operations for Brazilian phone numbers.
 */

#include <iostream>
#include <stdexcept>
#include "PhoneNumber.h"

using namespace std;

int main() 
{ 
    cout << "=== Brazilian Phone Number Validator ===" << endl;
    cout << "This program validates and formats Brazilian phone numbers." << endl;
    cout << "Supported formats:" << endl;
    cout << "- 8-digit: (XX) XXXX-XXXX" << endl;
    cout << "- 9-digit: (XX) XXXXX-XXXX" << endl << endl;
    
    try {
        PhoneNumber phone; // Create phone number object
        
        // Input phone number using overloaded >> operator
        cin >> phone; 
        
        // Display the formatted phone number using overloaded << operator
        cout << "\nThe phone number entered was: " << phone << endl;
        
        // Display individual components
        cout << "Area code: " << phone.getAreaCode() << endl;
        cout << "Number: " << phone.getNumber() << endl;
        
        // Test constructor with validation
        cout << "\n=== Testing Constructor Validation ===" << endl;
        try {
            PhoneNumber validPhone("11", "987654321");
            cout << "Valid phone created: " << validPhone << endl;
            
            PhoneNumber invalidPhone("1", "123"); // This should throw an exception
        } catch (const invalid_argument &e) {
            cout << "Constructor validation caught: " << e.what() << endl;
        }
        
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
} // end main