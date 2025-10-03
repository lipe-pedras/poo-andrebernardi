#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
private:
    double x;
    double y;

public:
    Point(double x_value = 0.0, double y_value = 0.0);
    double getX() const;
    double getY() const;
    Point &operator++();
    Point operator++(int);

    Point &operator--();
    Point operator--(int);

    explicit operator int();

    bool operator!() const;
    bool operator==(Point &p);
    bool operator!=(Point &p);

    friend std::ostream &operator<<(std::ostream &os, const Point &p);
    friend std::istream &operator>>(std::istream &in, Point &p);
};

#endif // POINT_H