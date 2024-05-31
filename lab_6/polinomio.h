#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>
using namespace std;

class Polinomio
{
private:
    double *valores;
    int n;

public:
    Polinomio();
    Polinomio(int);
    Polinomio(const Polinomio &);

    ~Polinomio();

    int operator>(const Polinomio &p) const;
    int operator>=(const Polinomio &p) const;
    int operator<(const Polinomio &p) const;
    int operator<=(const Polinomio &p) const;
    int operator==(const Polinomio &p) const;
    int operator!=(const Polinomio &p) const;

    Polinomio operator=(const Polinomio &);
    Polinomio operator+(const Polinomio &) const;
    Polinomio operator-(const Polinomio &) const;

    double operator[](int) const;

    Polinomio derivada() const; // Nova função para calcular a derivada
    double calcular(double x) const; // Nova função para calcular o valor do polinômio em um ponto
    double newton(double x0, int m, double epsilon) const; // Nova função para encontrar uma raiz real usando o método de Newton

    friend ostream &operator<<(ostream &out, const Polinomio &p);
    friend istream &operator>>(istream &in, Polinomio &p);
};

#endif
