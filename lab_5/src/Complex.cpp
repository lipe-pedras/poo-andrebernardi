#include "Complex.h"
#include <iostream>
#include <cmath>
#include <sstream>

unsigned int Complex::count = 0;

Complex::Complex()
{
    count++;
    real = 1;
    imaginary = 1;
}

Complex::Complex(double real_part, double imaginary_part) : real(real_part), imaginary(imaginary_part)
{
    count++;
}

Complex::~Complex()
{
    count--;
}

std::vector<double> Complex::toPolar() const
{
    std::vector<double> polar_form;
    polar_form.push_back(sqrt(real * real + imaginary * imaginary));
    if (real != 0)
    {
        if (real >= 0)
        {
            polar_form.push_back(atan(imaginary / real) * (180 / M_PI));
        }
        else
        {
            polar_form.push_back((atan(imaginary / real) * (180 / M_PI) + 180));
        }
    }
    else
    {
        std::cerr << "Error: division by zero.\n\n";
    }
    return polar_form;
}

Complex &Complex::operator++()
{
    real++;
    imaginary++;
    return *this;
}

Complex Complex::operator++(int)
{
    Complex temp(*this);
    real++;
    imaginary++;
    return temp;
}

Complex &Complex::operator--()
{
    real--;
    imaginary--;
    return *this;
}

Complex Complex::operator--(int)
{
    Complex temp(*this);
    real--;
    imaginary--;
    return temp;
}

Complex Complex::fromPolar(const std::vector<double> &vector)
{
    double real_part = cos(vector[1]) * vector[0];
    double imaginary_part = sin(vector[1]) * vector[0];
    return Complex(real_part, imaginary_part);
}

Complex Complex::operator+(const Complex &other) const
{
    double real_part = real + other.real;
    double imaginary_part = imaginary + other.imaginary;
    return Complex(real_part, imaginary_part);
}

Complex Complex::operator-(const Complex &other) const
{
    double real_part = real - other.real;
    double imaginary_part = imaginary - other.imaginary;
    return Complex(real_part, imaginary_part);
}

Complex Complex::operator*(const Complex &other) const
{
    std::vector<double> c1_polar = toPolar();
    std::vector<double> c2_polar = other.toPolar();
    std::vector<double> c3;
    c3.push_back(c1_polar[0] * c2_polar[0]);
    c3.push_back(c1_polar[1] + c2_polar[1]);
    return fromPolar(c3);
}

Complex Complex::operator/(const Complex &other) const
{
    std::vector<double> c1_polar = toPolar();
    std::vector<double> c2_polar = other.toPolar();
    std::vector<double> c3;
    if (c2_polar[0] == 0)
    {
        std::cerr << "Error: division by zero.\n\n";
    }
    else
    {
        c3.push_back(c1_polar[0] / c2_polar[0]);
        c3.push_back(c1_polar[1] - c2_polar[1]);
    }
    return fromPolar(c3);
}

double Complex::magnitude() const
{
    return sqrt(real * real + imaginary * imaginary);
}

int Complex::getInstanceCount()
{
    return count;
}

std::ostream &operator<<(std::ostream &out, const Complex &number)
{
    out << number.real << " " << number.imaginary << "i";
    return out;
}

// Function for reading input
std::istream &operator>>(std::istream &in, Complex &number)
{
    std::cout << "Enter the real part:\n";
    in >> number.real;
    std::cout << "Enter the imaginary part:\n";
    in >> number.imaginary;
    return in;
}