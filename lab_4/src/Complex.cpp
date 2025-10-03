// Complex.cpp
#include "Complex.h"
#include <iostream>
#include <cmath>
#include <sstream>

unsigned int Complex::count = 0;

Complex::Complex() {
    count++;
    real = 1;
    imaginary = 1;
}

Complex::Complex(double realPart, double imaginaryPart) : real(realPart), imaginary(imaginaryPart) {
    count++;
}

Complex::~Complex() {
    count--;
}

std::vector<double> Complex::polar() const {
    std::vector<double> polarForm;
    polarForm.push_back(sqrt(real * real + imaginary * imaginary));
    if (real != 0) {
        if (real >= 0) {
            polarForm.push_back(atan(imaginary / real) * (180 / M_PI));
        } else {
            polarForm.push_back((atan(imaginary / real) * (180 / M_PI) + 180));
        }
    } else {
        std::cerr << "Error: division by zero.\n\n";
    }
    return polarForm;
}

Complex Complex::rectangular(const std::vector<double>& vector) {
    double realPart = cos(vector[1]) * vector[0];
    double imaginaryPart = sin(vector[1]) * vector[0];
    return Complex(realPart, imaginaryPart);
}

Complex Complex::operator+(const Complex& other) const {
    double realPart = real + other.real;
    double imaginaryPart = imaginary + other.imaginary;
    return Complex(realPart, imaginaryPart);
}

Complex Complex::operator-(const Complex& other) const {
    double realPart = real - other.real;
    double imaginaryPart = imaginary - other.imaginary;
    return Complex(realPart, imaginaryPart);
}

Complex Complex::operator*(const Complex& other) const {
    std::vector<double> c1_polar = polar();
    std::vector<double> c2_polar = other.polar();
    std::vector<double> c3;
    c3.push_back(c1_polar[0] * c2_polar[0]);
    c3.push_back(c1_polar[1] + c2_polar[1]);
    return rectangular(c3);
}

Complex Complex::operator/(const Complex& other) const {
    std::vector<double> c1_polar = polar();
    std::vector<double> c2_polar = other.polar();
    std::vector<double> c3;
    if (c2_polar[0] == 0) {
        std::cerr << "Error: division by zero.\n\n";
    } else {
        c3.push_back(c1_polar[0] / c2_polar[0]);
        c3.push_back(c1_polar[1] - c2_polar[1]);
    }
    return rectangular(c3);
}

double Complex::modulus() const {
    return sqrt(real * real + imaginary * imaginary);
}

std::string Complex::printRectangular() const {
    std::ostringstream oss;

    oss << real;

    if (imaginary >= 0)
        oss << " + " << imaginary << "i";
    else
        oss << " - " << -imaginary << "i"; // Adjusted for negative imaginary part

    return oss.str();
}

int Complex::printNumberOfComplexes() {
    return count;
}

std::ostream &operator<<(std::ostream &out, const Complex &number)
{
    out << number.real << " " << number.imaginary <<  "i";
    return out;
}

// Function for reading
std::istream &operator>>(std::istream &in, Complex &number)
{
    std::cout << "Enter the real part.\n";
    in >> number.real;
    std::cout << "Enter the imaginary part.\n";
    in >> number.imaginary;
    return in;
}