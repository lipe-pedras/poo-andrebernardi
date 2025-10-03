#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>

class Polynomial
{
private:
    std::vector<double> coefficients;  // Polynomial coefficients

public:
    Polynomial();                                     // Default constructor
    Polynomial(int degree);                          // Constructor with degree
    Polynomial(const Polynomial &other);            // Copy constructor
    ~Polynomial();                                   // Destructor

    // Assignment operator
    Polynomial& operator=(const Polynomial& other);

    // Arithmetic operators
    Polynomial operator+(const Polynomial &other) const;
    Polynomial operator-(const Polynomial &other) const;
    Polynomial operator*(const Polynomial &other) const;

    // Compound assignment operators
    Polynomial& operator+=(const Polynomial &other);
    Polynomial& operator-=(const Polynomial &other);

    // Comparison operators
    bool operator==(const Polynomial &other) const;
    bool operator!=(const Polynomial &other) const;

    // Access operators
    double& operator[](int index);
    const double& operator[](int index) const;

    // Utility methods
    int getDegree() const;
    double evaluate(double x) const;
    void setCoefficient(int power, double value);
    double getCoefficient(int power) const;

    // Stream operators
    friend std::ostream& operator<<(std::ostream &out, const Polynomial &poly);
    friend std::istream& operator>>(std::istream &in, Polynomial &poly);
};

#endif