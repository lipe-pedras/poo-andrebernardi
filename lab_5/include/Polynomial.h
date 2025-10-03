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
    Polynomial(int grade);
    Polynomial(const Polynomial &p);

    ~Polynomial();

    Polynomial operator=(const Polynomial &p);
    Polynomial operator+(const Polynomial &p) const;
    Polynomial operator-(const Polynomial &p) const;

    double operator[](int index) const;

    friend ostream &operator<<(ostream &out, const Polynomial &p);
    friend istream &operator>>(istream &in, Polynomial &p);
};

#endif