// complex.cpp
#include "../include/complex.h"
#include <iostream>
#include <cmath>
#include <sstream>

unsigned int Complex::count = 0;

Complex::Complex() {
    count++;
    real = 1;
    imaginary = 1;
}

Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {
    count++;
}

Complex::~Complex() {
    count--;
}

std::vector<double> Complex::toPolar() const {
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

Complex Complex::fromPolar(const std::vector<double>& polarVector) {
    double realPart = cos(polarVector[1]) * polarVector[0];
    double imagPart = sin(polarVector[1]) * polarVector[0];
    return Complex(realPart, imagPart);
}

Complex Complex::operator+(const Complex& other) const {
    double realPart = real + other.real;
    double imagPart = imaginary + other.imaginary;
    return Complex(realPart, imagPart);
}

Complex Complex::operator-(const Complex& other) const {
    double realPart = real - other.real;
    double imagPart = imaginary - other.imaginary;
    return Complex(realPart, imagPart);
}

Complex Complex::operator*(const Complex& other) const {
    std::vector<double> thisPolar = toPolar();
    std::vector<double> otherPolar = other.toPolar();
    std::vector<double> resultPolar;
    resultPolar.push_back(thisPolar[0] * otherPolar[0]);
    resultPolar.push_back(thisPolar[1] + otherPolar[1]);
    return fromPolar(resultPolar);
}

Complex Complex::operator/(const Complex& other) const {
    std::vector<double> thisPolar = toPolar();
    std::vector<double> otherPolar = other.toPolar();
    std::vector<double> resultPolar;
    if (otherPolar[0] == 0) {
        std::cerr << "Error: division by zero.\n\n";
    } else {
        resultPolar.push_back(thisPolar[0] / otherPolar[0]);
        resultPolar.push_back(thisPolar[1] - otherPolar[1]);
    }
    return fromPolar(resultPolar);
}

double Complex::magnitude() const {
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

int Complex::getComplexCount() {
    return count;
}