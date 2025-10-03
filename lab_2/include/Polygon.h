#ifndef POLYGON_H
#define POLYGON_H

#include <string>

using namespace std;

class Polygon
{
private:
    int sides;        // Number of sides
    float sideLength; // Side length

public:
    Polygon(int sides = 3, float sideLength = 1);
    ~Polygon();

    void set(int sides, float sideLength);
    string getName() const;  // Returns polygon name based on number of sides
    float getArea();         // Calculates polygon area
    float getPerimeter();    // Calculates polygon perimeter
};

#endif // POLYGON_H