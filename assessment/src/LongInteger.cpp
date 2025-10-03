#include "LongInteger.h"
#include <algorithm>
#include <sstream>

// Default constructor
LongInteger::LongInteger() : is_negative(false) {
    digits.push_back(0);
}

// Constructor with string
LongInteger::LongInteger(const std::string &number) : is_negative(false) {
    if (number.empty()) {
        digits.push_back(0);
        return;
    }
    
    size_t start = 0;
    if (number[0] == '-') {
        is_negative = true;
        start = 1;
    } else if (number[0] == '+') {
        start = 1;
    }
    
    // Store digits in reverse order for easier arithmetic
    for (size_t i = number.length(); i > start; --i) {
        char c = number[i - 1];
        if (c >= '0' && c <= '9') {
            digits.push_back(c - '0');
        }
    }
    
    if (digits.empty()) {
        digits.push_back(0);
        is_negative = false;
    }
    
    // Remove leading zeros
    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }
    
    // If result is zero, make it positive
    if (digits.size() == 1 && digits[0] == 0) {
        is_negative = false;
    }
}

// Copy constructor
LongInteger::LongInteger(const LongInteger &other) 
    : digits(other.digits), is_negative(other.is_negative) {
}

// Destructor
LongInteger::~LongInteger() {
}

// Assignment operator
LongInteger& LongInteger::operator=(const LongInteger& other) {
    if (this != &other) {
        digits = other.digits;
        is_negative = other.is_negative;
    }
    return *this;
}

// Addition operator
LongInteger LongInteger::operator+(const LongInteger &other) const {
    LongInteger result;
    result.digits.clear();
    
    // Simple implementation - handle same sign case
    if (is_negative == other.is_negative) {
        int carry = 0;
        size_t max_size = std::max(digits.size(), other.digits.size());
        
        for (size_t i = 0; i < max_size || carry; ++i) {
            int sum = carry;
            if (i < digits.size()) sum += digits[i];
            if (i < other.digits.size()) sum += other.digits[i];
            
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        
        result.is_negative = is_negative;
    } else {
        // For different signs, convert to subtraction
        // This is a simplified version
        result = *this;  // Placeholder - would need full implementation
    }
    
    return result;
}

// Subtraction operator (simplified implementation)
LongInteger LongInteger::operator-(const LongInteger &other) const {
    // This is a simplified implementation
    // For full functionality, would need proper subtraction algorithm
    LongInteger result = *this;
    
    // Basic case: subtract same number gives zero
    if (*this == other) {
        result = LongInteger("0");
    }
    
    return result;
}

// Pre-increment
LongInteger& LongInteger::operator++() {
    LongInteger one("1");
    *this = *this + one;
    return *this;
}

// Post-increment
LongInteger LongInteger::operator++(int) {
    LongInteger temp = *this;
    ++(*this);
    return temp;
}

// Pre-decrement
LongInteger& LongInteger::operator--() {
    LongInteger one("1");
    *this = *this - one;
    return *this;
}

// Post-decrement
LongInteger LongInteger::operator--(int) {
    LongInteger temp = *this;
    --(*this);
    return temp;
}

// Compound assignment operators
LongInteger& LongInteger::operator+=(const LongInteger &other) {
    *this = *this + other;
    return *this;
}

LongInteger& LongInteger::operator-=(const LongInteger &other) {
    *this = *this - other;
    return *this;
}

// Comparison operators
bool LongInteger::operator==(const LongInteger &other) const {
    return (is_negative == other.is_negative) && (digits == other.digits);
}

bool LongInteger::operator!=(const LongInteger &other) const {
    return !(*this == other);
}

bool LongInteger::operator<(const LongInteger &other) const {
    if (is_negative != other.is_negative) {
        return is_negative;
    }
    
    if (digits.size() != other.digits.size()) {
        bool size_less = digits.size() < other.digits.size();
        return is_negative ? !size_less : size_less;
    }
    
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) {
            bool digit_less = digits[i] < other.digits[i];
            return is_negative ? !digit_less : digit_less;
        }
    }
    
    return false;
}

bool LongInteger::operator>(const LongInteger &other) const {
    return other < *this;
}

bool LongInteger::operator<=(const LongInteger &other) const {
    return !(*this > other);
}

bool LongInteger::operator>=(const LongInteger &other) const {
    return !(*this < other);
}

// Utility methods
bool LongInteger::isPalindrome() const {
    std::string str;
    for (int i = digits.size() - 1; i >= 0; --i) {
        str += std::to_string(digits[i]);
    }
    
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return str == reversed;
}

int LongInteger::getSize() const {
    return digits.size();
}

// Stream operators
std::ostream& operator<<(std::ostream &out, const LongInteger &num) {
    if (num.is_negative && !(num.digits.size() == 1 && num.digits[0] == 0)) {
        out << "-";
    }
    
    for (int i = num.digits.size() - 1; i >= 0; --i) {
        out << num.digits[i];
    }
    
    return out;
}

std::istream& operator>>(std::istream &in, LongInteger &num) {
    std::string input;
    in >> input;
    num = LongInteger(input);
    return in;
}