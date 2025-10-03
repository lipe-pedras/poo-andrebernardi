#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// ===== POLITICAL HIERARCHY CLASSES =====

/**
 * @brief Base class representing a politician
 */
class Politician
{
public:
    Politician();
    virtual ~Politician();
    virtual void print();
    
    string name;
    string party;
};

/**
 * @brief President class derived from Politician
 */
class President : public Politician
{
public:
    President();
    ~President();
    void print() override;
    
    string country;
};

/**
 * @brief Governor class derived from President
 */
class Governor : public President
{
public:
    Governor();
    ~Governor();
    void print() override;
    
    string state;
};

/**
 * @brief Mayor class derived from Governor
 */
class Mayor : public Governor
{
public:
    Mayor();
    ~Mayor();
    void print() override;
    
    string city;
};

// ===== GEOMETRIC HIERARCHY CLASSES =====

/**
 * @brief Point class representing a 2D coordinate
 */
class Point
{
public:
    double x, y;

    Point(double x = 0, double y = 0);
    
    friend ostream &operator<<(ostream &os, const Point &p);
    friend istream &operator>>(istream &is, Point &p);
};

/**
 * @brief Circle class derived from Point (representing the center)
 */
class Circle : public Point
{
public:
    double radius;

    Circle(double x = 0, double y = 0, double radius = 0);
    
    double area() const;
    
    friend ostream &operator<<(ostream &os, const Circle &c);
    friend istream &operator>>(istream &is, Circle &c);
};

/**
 * @brief Cylinder class derived from Circle (representing the base)
 */
class Cylinder : public Circle
{
public:
    double height;

    Cylinder(double x = 0, double y = 0, double radius = 0, double height = 0);
    
    double volume() const;
    double surfaceArea() const;
    
    friend ostream &operator<<(ostream &os, const Cylinder &c);
    friend istream &operator>>(istream &is, Cylinder &c);
};

#endif