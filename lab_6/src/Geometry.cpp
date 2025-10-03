/**
 * @file Geometry.cpp
 * @brief Implementation of geometric and political hierarchy classes
 */

#include "Geometry.h"

using namespace std;

// ===== POLITICAL HIERARCHY IMPLEMENTATIONS =====

/**
 * @brief Constructor for Politician class
 */
Politician::Politician()
{
    cout << "A politician was created.\n";
}

/**
 * @brief Destructor for Politician class
 */
Politician::~Politician()
{
    cout << "A politician was destroyed.\n";
}

/**
 * @brief Print politician information
 */
void Politician::print()
{
    cout << "Name: " << name << ", Party: " << party << endl;
}

/**
 * @brief Constructor for President class
 */
President::President()
{
    cout << "A president was created.\n";
}

/**
 * @brief Destructor for President class
 */
President::~President()
{
    cout << "A president was destroyed.\n";
}

/**
 * @brief Print president information
 */
void President::print()
{
    Politician::print(); // Call the base class print function
    cout << "Country: " << country << endl;
}

/**
 * @brief Constructor for Governor class
 */
Governor::Governor()
{
    cout << "A governor was created.\n";
}

/**
 * @brief Destructor for Governor class
 */
Governor::~Governor()
{
    cout << "A governor was destroyed.\n";
}

/**
 * @brief Print governor information
 */
void Governor::print()
{
    President::print(); // Call the base class print function
    cout << "State: " << state << endl;
}

/**
 * @brief Constructor for Mayor class
 */
Mayor::Mayor()
{
    cout << "A mayor was created.\n";
}

/**
 * @brief Destructor for Mayor class
 */
Mayor::~Mayor()
{
    cout << "A mayor was destroyed.\n";
}

/**
 * @brief Print mayor information
 */
void Mayor::print()
{
    Governor::print(); // Call the base class print function
    cout << "City: " << city << endl;
}

// ===== GEOMETRIC HIERARCHY IMPLEMENTATIONS =====

/**
 * @brief Constructor for Point class
 * @param x X-coordinate
 * @param y Y-coordinate
 */
Point::Point(double x, double y) : x(x), y(y) {}

/**
 * @brief Output stream operator for Point
 */
ostream &operator<<(ostream &os, const Point &p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

/**
 * @brief Input stream operator for Point
 */
istream &operator>>(istream &is, Point &p)
{
    cout << "Enter x and y coordinates: ";
    is >> p.x >> p.y;
    return is;
}

/**
 * @brief Constructor for Circle class
 * @param x X-coordinate of center
 * @param y Y-coordinate of center  
 * @param radius Radius of the circle
 */
Circle::Circle(double x, double y, double radius) : Point(x, y), radius(radius) {}

/**
 * @brief Calculate the area of the circle
 * @return Area of the circle
 */
double Circle::area() const
{
    return M_PI * radius * radius;
}

/**
 * @brief Output stream operator for Circle
 */
ostream &operator<<(ostream &os, const Circle &c)
{
    os << "Center: " << static_cast<Point>(c) << ", Radius: " << c.radius;
    return os;
}

/**
 * @brief Input stream operator for Circle
 */
istream &operator>>(istream &is, Circle &c)
{
    cout << "Enter circle center ";
    is >> static_cast<Point &>(c);
    cout << "Enter radius: ";
    is >> c.radius;
    return is;
}

/**
 * @brief Constructor for Cylinder class
 * @param x X-coordinate of base center
 * @param y Y-coordinate of base center
 * @param radius Radius of the base circle
 * @param height Height of the cylinder
 */
Cylinder::Cylinder(double x, double y, double radius, double height) 
    : Circle(x, y, radius), height(height) {}

/**
 * @brief Calculate the volume of the cylinder
 * @return Volume of the cylinder
 */
double Cylinder::volume() const
{
    return area() * height;
}

/**
 * @brief Calculate the surface area of the cylinder
 * @return Surface area of the cylinder
 */
double Cylinder::surfaceArea() const
{
    return 2 * area() + 2 * M_PI * radius * height;
}

/**
 * @brief Output stream operator for Cylinder
 */
ostream &operator<<(ostream &os, const Cylinder &c)
{
    os << "Base: " << static_cast<Circle>(c) << ", Height: " << c.height;
    return os;
}

/**
 * @brief Input stream operator for Cylinder
 */
istream &operator>>(istream &is, Cylinder &c)
{
    is >> static_cast<Circle &>(c);
    cout << "Enter height: ";
    is >> c.height;
    return is;
}