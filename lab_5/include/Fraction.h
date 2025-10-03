#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include "Complex.h"

class Fraction
{
private:
    int numerator;
    int denominator;
    // Reduces the fraction to its simplest form
    Fraction reduce(void);

public:
    Fraction(void)
    {
        numerator = 1;
        denominator = 1;
    }
    // Constructor with parameters inline
    Fraction(int num, int denom) : numerator(num),
                                   denominator(denom){};
    Fraction(const Fraction &f) // Copy constructor inline
    {
        numerator = f.numerator;
        denominator = f.denominator;
    }
    ~Fraction(void){};
    // Destructor
    
    // Access methods
    int getNumerator(void) { return numerator; }
    int getDenominator(void) { return denominator; }
    
    // Arithmetic methods
    // Returns a new fraction that is the sum of the receiver with other
    Fraction operator+(Fraction other);
    // Returns a new fraction that is the subtraction of the receiver with other
    Fraction operator-(Fraction other);

    // Returns a new fraction that is the product of the receiver and other
    Fraction operator*(Fraction other);
    // Returns a new fraction that is the quotient of the receiver and other
    Fraction operator/(Fraction other);
    
    // Comparison methods
    // Returns true if receiver is less than other_fraction
    int operator<(Fraction other_fraction);
    // Returns true if receiver is greater than other_fraction
    int operator>(Fraction other_fraction);
    // Returns true if receiver equals other_fraction
    int operator==(Fraction other_fraction);
    
    int operator<=(Fraction other_fraction);
    int operator>=(Fraction other_fraction);
    int operator!=(Fraction other_fraction);
    
    Fraction &operator++();
    Fraction operator++(int);
    Fraction &operator--();
    Fraction operator--(int);
    explicit operator Complex() const;
    friend std::ostream &operator<<(std::ostream &out, const Fraction &fraction);
    friend std::istream &operator>>(std::istream &in, Fraction &fraction);

    // Conversion methods
    // Returns the value of the fraction as float
    float toFloat(void);
    
    // Printing methods
    // Show the receiver in the format "numerator/denominator"
    void print(void);
};
#endif // FRACTION_H