// Fraction.cpp - Implementation of the Fraction class
#include "Fraction.h"
using namespace std;

//
// Private methods of the Fraction class
//
Fraction Fraction::simplified(void)
{
    int gcd = 1;
    int minimum = m_numerator;
    if (m_numerator > m_denominator)
        minimum = m_denominator;
    for (int i = 1; i <= minimum; i++)
    {
        if ((m_numerator % i == 0) && (m_denominator % i == 0))
            gcd = i;
    }
    m_numerator /= gcd;
    m_denominator /= gcd;
    return (*this);
}

//
// Arithmetic methods of the Fraction class
//
// returns a new Fraction that is the sum of the receiver with other
Fraction Fraction::operator+(Fraction other)
{
    Fraction temp(m_numerator * other.m_denominator +
                     m_denominator * other.m_numerator,
                 m_denominator * other.m_denominator);
    return temp.simplified();
}

// returns a new Fraction that is the subtraction of the receiver with other
Fraction Fraction::operator-(Fraction other)
{
    Fraction temp(m_numerator * other.m_denominator -
                     m_denominator * other.m_numerator,
                 m_denominator * other.m_denominator);
    return temp.simplified();
}

// returns a new Fraction that is the product of the receiver and other
Fraction Fraction::operator*(Fraction other)
{
    Fraction temp(m_numerator * other.m_numerator,
                 m_denominator * other.m_denominator);
    return temp.simplified();
}

// returns a new Fraction that is the quotient of the receiver and other
Fraction Fraction::operator/(Fraction other)
{
    Fraction temp(m_numerator * other.m_denominator,
                 m_denominator * other.m_numerator);
    return temp.simplified();
}

//
// Comparison methods of the Fraction class
//
// returns true if receiver is less than other
int Fraction::operator<(Fraction other)
{
    return (m_numerator * other.m_denominator <
            m_denominator * other.m_numerator);
}

// returns true if receiver is greater than other
int Fraction::operator>(Fraction other)
{
    return (m_numerator * other.m_denominator >
            m_denominator * other.m_numerator);
}

// returns true if receiver is equal to other
int Fraction::operator==(Fraction other)
{
    return (m_numerator * other.m_denominator ==
            m_denominator * other.m_numerator);
}

// returns true if receiver is less than or equal to other
int Fraction::operator<=(Fraction other)
{
    return (*this < other || *this == other);
}

// returns true if receiver is greater than or equal to other
int Fraction::operator>=(Fraction other)
{
    return (*this > other || *this == other);
}

// returns true if receiver is different from other
int Fraction::operator!=(Fraction other)
{
    return (!(*this == other));
}

// Function to print the fraction
ostream &operator<<(ostream &out, const Fraction &fraction)
{
    out << fraction.m_numerator << " / " << fraction.m_denominator;
    return out;
}

// Function for reading
istream &operator>>(istream &in, Fraction &fraction)
{
    cout << "Enter the numerator.\n";
    in >> fraction.m_numerator;
    cout << "Enter the denominator.\n";
    in >> fraction.m_denominator;
    return in;
}

// Conversion methods
//
// returns the value of the fraction as float
float Fraction::asFloat(void)
{
    return ((float)m_numerator / (float)m_denominator);
}

//
// Printing methods
//
// show the receiver in the format m_numerator/m_denominator
void Fraction::print(void)
{
    cout << m_numerator << "/" << m_denominator;
}