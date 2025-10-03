#ifndef COMPLEX_H
#define COMPLEX_H

#include <vector>
#include <string>
#include <iostream>

class Complex
{
private:
    double real;                   // Real part
    double imaginary;              // Imaginary part
    static unsigned int count;     // Static member to count instances

public:
    Complex();
    Complex(double real, double imaginary);
    ~Complex();

    std::vector<double> toPolar() const;                            // Convert to polar form
    static Complex fromPolar(const std::vector<double> &vector);    // Create from polar form

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    Complex operator+(const Complex &other) const;
    Complex operator-(const Complex &other) const;
    Complex operator*(const Complex &other) const;
    Complex operator/(const Complex &other) const;
    Complex &operator++();
    Complex operator++(int);
    Complex &operator--();
    Complex operator--(int);
    friend std::ostream &operator<<(std::ostream &out, const Complex &number);
    friend std::istream &operator>>(std::istream &in, Complex &number);

    double magnitude() const;

    static int getInstanceCount();
};

#endif