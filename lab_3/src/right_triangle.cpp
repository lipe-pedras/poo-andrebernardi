#include "../include/right_triangle.h"

using namespace std;

RightTriangle::RightTriangle(int a, int b, int c) : side1(a), side2(b), side3(c)
{
    if (!isRightTriangle())
    {
        throw std::invalid_argument("The provided sides do not form a valid right triangle.");
    }
}

bool RightTriangle::isRightTriangle() const
{
    vector<int> sides{side1, side2, side3};
    sort(sides.begin(), sides.end(), greater<int>());
    return ((sides[0] * sides[0] == sides[2] * sides[2] + sides[1] * sides[1]));
}

void RightTriangle::printSides() const
{
    std::cout << "Right triangle sides: " << side1 << ", " << side2 << ", " << side3 << std::endl;
}