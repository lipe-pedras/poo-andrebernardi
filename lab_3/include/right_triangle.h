#ifndef RIGHT_TRIANGLE_H
#define RIGHT_TRIANGLE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class RightTriangle {
private:
    int side1;
    int side2;
    int side3;

public:
    RightTriangle(int a, int b, int c);
    bool isRightTriangle() const;
    void printSides() const;
};

#endif