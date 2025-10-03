#include <iostream>
#include "../include/Polygon.h"
#include "../include/Rectangle.h"

using namespace std;

int main()
{
    cout << "Laboratory 2 - Main Program\n\n";
    
    // Test Polygon class
    cout << "=== Polygon Demo ===\n";
    Polygon triangle(3, 5.0);
    cout << "Name: " << triangle.getName() << endl;
    cout << "Area: " << triangle.getArea() << endl;
    cout << "Perimeter: " << triangle.getPerimeter() << endl;
    cout << endl;
    
    Polygon hexagon(6, 3.0);
    cout << "Name: " << hexagon.getName() << endl;
    cout << "Area: " << hexagon.getArea() << endl;
    cout << "Perimeter: " << hexagon.getPerimeter() << endl;
    cout << endl;
    
    // Test Rectangle class
    cout << "=== Rectangle Demo ===\n";
    Rectangle rect(5, 3);
    cout << "Length: " << rect.getLength() << endl;
    cout << "Width: " << rect.getWidth() << endl;
    cout << "Area: " << rect.getArea() << endl;
    cout << "Perimeter: " << rect.getPerimeter() << endl;
    cout << "Is square: " << (rect.isSquare() ? "Yes" : "No") << endl;
    cout << "Rectangle visualization:" << endl;
    rect.printRectangle();
    
    return 0;
}