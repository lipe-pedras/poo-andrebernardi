#include "../include/Polygon.h"
#include <iostream>
#include <cmath>

using namespace std;

Polygon::Polygon(int sides, float sideLength) : sides(sides), sideLength(sideLength)
{
    cout << "Polygon created" << endl;
}

Polygon::~Polygon() {}

void Polygon::set(int sides, float sideLength)
{
    this->sides = sides;
    this->sideLength = sideLength;
}

string Polygon::getName() const
{
    switch (sides)
    {
    case 3:
        return "Triangle";
        break;

    case 4:
        return "Quadrilateral";
        break;

    case 5:
        return "Pentagon";
        break;

    case 6:
        return "Hexagon";
        break;

    case 7:
        return "Heptagon";
        break;

    case 8:
        return "Octagon";
        break;

    case 9:
        return "Enneagon";
        break;

    case 10:
        return "Decagon";
        break;

    default:
        cerr << "This method was programmed only for polygons from 3 to 10 sides.\n";
        return "";
        break;
    }
}

float Polygon::getArea()
{
    return 0.25 * sides * sideLength * sideLength * (cos(3.1415 / sides) / sin(3.1415 / sides));
}

float Polygon::getPerimeter()
{
    return sides * sideLength;
}