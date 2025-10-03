// polynomial.h
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using namespace std;

class Polynomial
{
private:
    double *coefficients;
    int degree;

public:
    Polynomial();
    Polynomial(int);
    Polynomial(const Polynomial &);

    ~Polynomial();

    Polynomial operator=(const Polynomial &);
    Polynomial operator+(const Polynomial &) const;
    Polynomial operator-(const Polynomial &) const;

    double operator[](int) const;

    friend ostream &operator<<(ostream &out, const Polynomial &p);
    friend istream &operator>>(istream &in, Polynomial &p);
};

#endif
