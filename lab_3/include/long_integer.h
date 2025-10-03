#ifndef LONG_INTEGER_H
#define LONG_INTEGER_H

#include <iostream>
#include <string>
#include <cstring>

class LongInteger {
protected:
    int compareMagnitude(const LongInteger& other) const;
private:
    static const int MAX_DIGITS = 30;
    int digits[MAX_DIGITS]; // Storage for number digits
    int digitCount;         // Number of digits in the number
    int sign;               // Positive or negative sign

public:
    LongInteger();                // Default constructor
    LongInteger(const std::string& number); // Constructor with string
    ~LongInteger();               // Destructor

    void readFromKeyboard();      // Read number from keyboard
    void print() const;           // Print number
    LongInteger operator+(const LongInteger& other) const;  // Add two numbers
    LongInteger operator-(const LongInteger& other) const; // Subtract two numbers
};

#endif