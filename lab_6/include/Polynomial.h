#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using namespace std;

/**
 * @brief Polynomial class with dynamic coefficient management
 * 
 * This class represents a polynomial with floating-point coefficients
 * and provides various mathematical operations including arithmetic,
 * comparison, calculus operations, and root finding.
 */
class Polynomial
{
private:
    double *coefficients;  // Array of polynomial coefficients
    int degree;           // Degree of the polynomial

public:
    // Constructors and destructor
    Polynomial();                           // Default constructor (zero polynomial)
    Polynomial(int degree);                 // Constructor with specified degree
    Polynomial(const Polynomial &other);    // Copy constructor
    ~Polynomial();                          // Destructor

    // Comparison operators
    int operator>(const Polynomial &p) const;
    int operator>=(const Polynomial &p) const;
    int operator<(const Polynomial &p) const;
    int operator<=(const Polynomial &p) const;
    int operator==(const Polynomial &p) const;
    int operator!=(const Polynomial &p) const;

    // Assignment and arithmetic operators
    Polynomial operator=(const Polynomial &other);
    Polynomial operator+(const Polynomial &other) const;
    Polynomial operator-(const Polynomial &other) const;

    // Access operator
    double operator[](int index) const;

    // Mathematical operations
    Polynomial derivative() const;                                          // Calculate derivative
    double evaluate(double x) const;                                        // Evaluate polynomial at point x
    double newtonMethod(double x0, int maxIterations, double epsilon) const; // Find root using Newton's method

    // Input/output operators
    friend ostream &operator<<(ostream &out, const Polynomial &p);
    friend istream &operator>>(istream &in, Polynomial &p);
};

#endif