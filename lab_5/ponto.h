#ifndef PONTO_H
#define PONTO_H

#include <iostream>

class Ponto
{
private:
    double x;
    double y;

public:
    Ponto(double x_val = 0.0, double y_val = 0.0);
    double getX() const;
    double getY() const;
    Ponto &operator++();
    Ponto operator++(int);
    friend std::ostream &operator<<(std::ostream &os, const Ponto &p);
    friend std::istream &operator>>(std::istream &in, Ponto &p);
};

#endif // PONTO_H
