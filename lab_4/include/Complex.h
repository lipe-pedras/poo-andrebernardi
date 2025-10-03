// Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H

#include <vector>
#include <string>
#include <iostream>

class Complex {
private:
    double real; // Real part
    double imaginary; // Imaginary part
    static unsigned int count; // Static member to count instances

public:
    Complex();
    Complex(double real, double imaginary);
    ~Complex();

    std::vector<double> polar() const;
    static Complex rectangular(const std::vector<double>& vector);

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    friend std::ostream &operator<<(std::ostream &out, const Complex &complex);
    friend std::istream &operator>>(std::istream &in, Complex &complex);

    double modulus() const;
    std::string printRectangular() const;

    static int printNumberOfComplexes();
};

#endif