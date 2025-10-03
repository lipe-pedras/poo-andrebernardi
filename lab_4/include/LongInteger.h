#ifndef LONGINTEGER_H
#define LONGINTEGER_H

#include <iostream>
#include <string>
#include <cstring>

class LongInteger {
protected:

private:
    static const int MAX_DIGITS = 30;
    int digits[MAX_DIGITS]; // Storage for the number digits
    int numDigits;          // Number of digits in the number
    int sign;               // Positive or negative sign

public:
    LongInteger();                // Default constructor
    LongInteger(const std::string& number); // Constructor with string
    ~LongInteger();               // Destructor

    void readFromKeyboard();      // Read number from keyboard
    void print() const;           // Print number
    LongInteger operator+(const LongInteger& other) const;  // Add two numbers
    LongInteger operator-(const LongInteger& other) const; // Subtract two numbers
    int operator>(const LongInteger& other) const;
    int operator<(const LongInteger& other) const;
    int operator>=(const LongInteger& other) const;
    int operator<=(const LongInteger& other) const;
    int operator==(const LongInteger& other) const;
    int operator!=(const LongInteger& other) const;
    friend std::ostream &operator<<(std::ostream &out, const LongInteger &number);
    friend std::istream &operator>>(std::istream &in, LongInteger &number);

};

#endif