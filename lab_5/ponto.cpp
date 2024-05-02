#include "Ponto.h"
#include <cmath>
using namespace std;

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

bool Ponto::operator! () const
{
    if(x==0 && y==0) return true;
    return false;
}

Ponto &Ponto::operator--()
{
    --x;
    --y;
    return *this;
}

Ponto Ponto::operator--(int)
{
    Ponto temp = *this;
    --(*this);
    return temp;
}

Ponto::operator int()
{
    return sqrt(x*x + y*y);
}

bool Ponto::operator== (Ponto& p)
{
    return (x == p.x && y == p.y);
}

bool Ponto::operator!= (Ponto& p)
{
    return (x != p.x && y != p.y);
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