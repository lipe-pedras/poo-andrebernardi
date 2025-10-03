// complex.h
#ifndef COMPLEX_H
#define COMPLEX_H

#include <vector>
#include <string>

class Complex {
private:
    double real; // Real part
    double imaginary; // Imaginary part
    static unsigned int count; // Static member to count instances

public:
    Complex();
    Complex(double real, double imaginary);
    ~Complex();

    std::vector<double> toPolar() const; // Convert to polar form
    static Complex fromPolar(const std::vector<double>& polarVector); // Static method to create from polar

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    double magnitude() const;
    std::string printRectangular() const;

    static int getComplexCount();
};

#endif