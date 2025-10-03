#include "Point.h"
#include <cmath>
using namespace std;

Point::Point(double x_value, double y_value) : x(x_value), y(y_value) {}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

Point &Point::operator++()
{
    ++x;
    ++y;
    return *this;
}

Point Point::operator++(int)
{
    Point temp = *this;
    ++(*this);
    return temp;
}

bool Point::operator!() const
{
    if(x == 0 && y == 0) return true;
    return false;
}

Point &Point::operator--()
{
    --x;
    --y;
    return *this;
}

Point Point::operator--(int)
{
    Point temp = *this;
    --(*this);
    return temp;
}

Point::operator int()
{
    return sqrt(x*x + y*y);
}

bool Point::operator==(Point& p)
{
    return (x == p.x && y == p.y);
}

bool Point::operator!=(Point& p)
{
    return (x != p.x && y != p.y);
}

std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "(" << p.getX() << ", " << p.getY() << ")";
    return os;
}

std::istream &operator>>(std::istream &in, Point &p)
{
    std::cout << "Enter the X value: ";
    in >> p.x;
    std::cout << "Enter the Y value: ";
    in >> p.y;
    return in;
}