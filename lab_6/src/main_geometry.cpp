/**
 * @file main_geometry.cpp
 * @brief Demonstration of inheritance hierarchies and geometric calculations
 * 
 * This program demonstrates object-oriented programming concepts including
 * inheritance, polymorphism, and operator overloading using political and
 * geometric class hierarchies.
 */

#include <iostream>
#include "Geometry.h"

using namespace std;

/**
 * @brief Main function demonstrating inheritance and polymorphism
 * @return 0 on successful execution
 */
int main()
{
    cout << "=== Object-Oriented Programming Demonstration ===" << endl;
    
    // Political hierarchy demonstration
    cout << "\n=== Political Hierarchy Example ===" << endl;
    cout << "Demonstrating constructor/destructor chain and inheritance:" << endl;
    
    Mayor mayor;
    mayor.name = "João da Silva";
    mayor.party = "Progressive Party";
    mayor.country = "Brazil";
    mayor.state = "São Paulo";
    mayor.city = "São Paulo";

    cout << "\nMayor information:" << endl;
    mayor.print();

    // Geometric hierarchy demonstration
    cout << "\n=== Geometric Hierarchy Example ===" << endl;
    
    Point p(1, 2);
    cout << "Point: " << p << endl;

    Circle c(1, 2, 3);
    cout << "Circle: " << c << ", Area: " << c.area() << endl;

    Cylinder cylinder(1, 2, 3, 4);
    cout << "Cylinder: " << cylinder << endl;
    cout << "Volume: " << cylinder.volume() << endl;
    cout << "Surface Area: " << cylinder.surfaceArea() << endl;

    // Interactive geometric input demonstration
    cout << "\n=== Interactive Input Example ===" << endl;
    cout << "Let's create a cylinder interactively:" << endl;
    
    Cylinder userCylinder;
    cin >> userCylinder;
    
    cout << "\nYour cylinder: " << userCylinder << endl;
    cout << "Volume: " << userCylinder.volume() << endl;
    cout << "Surface Area: " << userCylinder.surfaceArea() << endl;

    cout << "\n=== End of Demonstration ===" << endl;
    return 0;
}