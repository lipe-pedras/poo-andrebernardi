// File Fraction.cpp - Implementation of the Fraction class
#include "Fraction.h"
#include "Complex.h"
using namespace std;

//
// Private methods of the Fraction class
//
Fraction Fraction::reduce(void)
{
    int gcd = 1;
    int minimum = numerator;
    if (numerator > denominator)
        minimum = denominator;
    for (int i = 1; i <= minimum; i++)
    {
        if ((numerator % i == 0) && (denominator % i == 0))
            gcd = i;
    }
    numerator /= gcd;
    denominator /= gcd;
    return (*this);
}

//
// Arithmetic methods of the Fraction class
//
// Returns a new Fraction that is the sum of the receiver with other
Fraction Fraction::operator+(Fraction other)
{
    Fraction temp(numerator * other.denominator +
                     denominator * other.numerator,
                 denominator * other.denominator);
    return temp.reduce();
}
// Returns a new Fraction that is the subtraction of the receiver with other
Fraction Fraction::operator-(Fraction other)
{
    Fraction temp(numerator * other.denominator -
                     denominator * other.numerator,
                 denominator * other.denominator);
    return temp.reduce();
}

// Returns a new Fraction that is the product of the receiver and other
Fraction Fraction::operator*(Fraction other)
{
    Fraction temp(numerator * other.numerator,
                 denominator * other.denominator);
    return temp.reduce();
}

// Returns a new Fraction that is the quotient of the receiver and other
Fraction Fraction::operator/(Fraction other)
{
    Fraction temp(numerator * other.denominator,
                 denominator * other.numerator);
    return temp.reduce();
}
//
// Comparison methods of the Fraction class
//
// Returns true if receiver is less than other
int Fraction::operator<(Fraction other)
{
    return (numerator * other.denominator <
            denominator * other.numerator);
}
// Returns true if receiver is greater than other
int Fraction::operator>(Fraction other)
{
    return (numerator * other.denominator >
            denominator * other.numerator);
}

// Returns true if receiver equals other
int Fraction::operator==(Fraction other)
{
    return (numerator * other.denominator ==
            denominator * other.numerator);
}
// Returns true if receiver is less than or equal to other
int Fraction::operator<=(Fraction other)
{
    return (*this < other || *this == other);
}
// Returns true if receiver is greater than or equal to other
int Fraction::operator>=(Fraction other)
{
    return (*this > other || *this == other);
}
// Returns true if receiver is different from other
int Fraction::operator!=(Fraction other)
{
    return (!(*this == other));
}

Fraction &Fraction::operator++()
{
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction temp(*this);
    numerator += denominator;
    return temp;
}

Fraction &Fraction::operator--()
{
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction temp(*this);
    numerator -= denominator;
    return temp;
}

Fraction::operator Complex() const
{
    return Complex((double) numerator / denominator, 0);
}

// Function to print the fraction
ostream &operator<<(ostream &out, const Fraction &fraction)
{
    out << fraction.numerator << " / " << fraction.denominator;
    return out;
}

// Function for reading input
istream &operator>>(istream &in, Fraction &fraction)
{
    cout << "Enter the numerator:\n";
    in >> fraction.numerator;
    cout << "Enter the denominator:\n";
    in >> fraction.denominator;
    return in;
}
// Conversion methods
//
// Returns the value of the fraction as float
float Fraction::toFloat(void)
{
    return ((float)numerator / (float)denominator);
}
//
// Printing methods
//
// Show the receiver in the format numerator/denominator
void Fraction::print(void)
{
    cout << numerator << "/" << denominator;
}