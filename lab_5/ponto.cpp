#include "Ponto.h"

Ponto::Ponto(double x_val, double y_val) : x(x_val), y(y_val) {}

double Ponto::getX() const
{
    return x;
}

double Ponto::getY() const
{
    return y;
}

Ponto &Ponto::operator++()
{
    ++x;
    ++y;
    return *this;
}

Ponto Ponto::operator++(int)
{
    Ponto temp = *this;
    ++(*this);
    return temp;
}

std::ostream &operator<<(std::ostream &os, const Ponto &p)
{
    os << "(" << p.getX() << ", " << p.getY() << ")";
    return os;
}

std::istream &operator>>(std::istream &in, Ponto &p)
{
    std::cout << "Entre com o valor de X: ";
    in >> p.x;
    std::cout << "Entre com o valor de Y: ";
    in >> p.y;
    return in;
}