// Fraction.h - interface for the Fraction class
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
    // reduces the fraction to its simplest form
    Fraction simplified(void);

public:
    Fraction(void)
    {
        m_numerator = 1;
        m_denominator = 1;
    }
    // Constructor with parameters inline
    Fraction(int numerator, int denominator) : m_numerator(numerator),
                                  // Constructor without parameters inline
                                  m_denominator(denominator){};
    Fraction(const Fraction &fraction) // Copy constructor inline
    {
        m_numerator = fraction.m_numerator;
        m_denominator = fraction.m_denominator;
    }
    ~Fraction(void){}; // Destructor

    // access methods
    int getNumerator(void) { return m_numerator; }
    int getDenominator(void) { return m_denominator; }

    // arithmetic methods
    // returns a new fraction that is the sum of the receiver with other
    Fraction operator+(Fraction other);
    // returns a new fraction that is the subtraction of the receiver with other
    Fraction operator-(Fraction other);
    // returns a new fraction that is the product of the receiver and other
    Fraction operator*(Fraction other);
    // returns a new fraction that is the quotient of the receiver and other
    Fraction operator/(Fraction other);

    // comparison methods
    // returns true if receiver is less than other
    int operator<(Fraction other);
    // returns true if receiver is greater than other
    int operator>(Fraction other);
    // returns true if receiver is equal to other
    int operator==(Fraction other);
    //
    int operator<=(Fraction other);
    //
    int operator>=(Fraction other);
    //
    int operator!=(Fraction other);
    //
    friend std::ostream &operator<<(std::ostream &out, const Fraction &fraction);
    friend std::istream &operator>>(std::istream &in, Fraction &fraction);

    // conversion methods
    // returns the value of the fraction as float
    float asFloat(void);

    // printing methods
    // show the receiver in the format "m_numerator/m_denominator"
    void print(void);
};
#endif // FRACTION_H