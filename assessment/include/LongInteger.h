#ifndef LONGINTEGER_H
#define LONGINTEGER_H

#include <iostream>
#include <string>
#include <vector>

class LongInteger
{
private:
    std::vector<int> digits;  // Storage for digits
    bool is_negative;         // Sign of the number

public:
    LongInteger();                                    // Default constructor
    LongInteger(const std::string &number);          // Constructor with string
    LongInteger(const LongInteger &other);           // Copy constructor
    ~LongInteger();                                  // Destructor

    // Assignment operator
    LongInteger& operator=(const LongInteger& other);

    // Arithmetic operators
    LongInteger operator+(const LongInteger &other) const;
    LongInteger operator-(const LongInteger &other) const;
    
    // Increment/decrement operators
    LongInteger& operator++();      // Pre-increment
    LongInteger operator++(int);    // Post-increment
    LongInteger& operator--();      // Pre-decrement
    LongInteger operator--(int);    // Post-decrement
    
    // Compound assignment operators
    LongInteger& operator+=(const LongInteger &other);
    LongInteger& operator-=(const LongInteger &other);
    
    // Comparison operators
    bool operator>(const LongInteger &other) const;
    bool operator<(const LongInteger &other) const;
    bool operator>=(const LongInteger &other) const;
    bool operator<=(const LongInteger &other) const;
    bool operator==(const LongInteger &other) const;
    bool operator!=(const LongInteger &other) const;
    
    // Utility methods
    bool isPalindrome() const;
    int getSize() const;
    
    // Stream operators
    friend std::ostream& operator<<(std::ostream &out, const LongInteger &num);
    friend std::istream& operator>>(std::istream &in, LongInteger &num);
};

#endif