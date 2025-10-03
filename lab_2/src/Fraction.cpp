// Fraction.cpp - Implementation of Fraction class
#include "../include/Fraction.h"
#include <iostream>

using namespace std;

//
// Private methods of Fraction class
//
Fraction Fraction::Reduced(void)
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
// Arithmetic methods of Fraction class
//
// Returns a new Fraction that is the sum of the receiver with other
Fraction Fraction::Add(Fraction other)
{
    Fraction temp(m_numerator * other.m_denominator +
                     m_denominator * other.m_numerator,
                 m_denominator * other.m_denominator);
    return temp.Reduced();
}

// Returns a new Fraction that is the subtraction of the receiver with other
Fraction Fraction::Subtract(Fraction other)
{
    Fraction temp(m_numerator * other.m_denominator -
                     m_denominator * other.m_numerator,
                 m_denominator * other.m_denominator);
    return temp.Reduced();
}

// Returns a new Fraction that is the product of the receiver and other
Fraction Fraction::Multiply(Fraction other)
{
    Fraction temp(m_numerator * other.m_numerator,
                 m_denominator * other.m_denominator);
    return temp.Reduced();
}

// Returns a new Fraction that is the quotient of the receiver and other
Fraction Fraction::Divide(Fraction other)
{
    Fraction temp(m_numerator * other.m_denominator,
                 m_denominator * other.m_numerator);
    return temp.Reduced();
}

//
// Comparison methods of Fraction class
//
// Returns true if receiver is less than other
int Fraction::LessThan(Fraction other)
{
    return (m_numerator * other.m_denominator <
            m_denominator * other.m_numerator);
}

// Returns true if receiver is greater than other
int Fraction::GreaterThan(Fraction other)
{
    return (m_numerator * other.m_denominator >
            m_denominator * other.m_numerator);
}

// Returns true if receiver is equal to other
int Fraction::Equal(Fraction other)
{
    return (m_numerator * other.m_denominator ==
            m_denominator * other.m_numerator);
}

//
// Conversion methods
//
// Returns the fraction value as float
float Fraction::AsFloat(void)
{
    return ((float)m_numerator / (float)m_denominator);
}

//
// Print methods
//
// Show the receiver in format numerator/denominator
void Fraction::Print(void)
{
    cout << m_numerator << "/" << m_denominator;
}