#include <iostream>
#include "Point.h"

int main()
{
    // Creating points and testing methods
    Point p1(3.0, 4.0);
    Point p2(0.0, 0.0);

    // Printing the points
    std::cout << "Point p1: " << p1 << std::endl;
    std::cout << "Point p2: " << p2 << std::endl;

    // Testing increment operators
    ++p1;
    std::cout << "After ++p1: " << p1 << std::endl;

    Point p3 = p2++;
    std::cout << "After p2++: " << p2 << std::endl;
    std::cout << "Point p3 (result of p2++): " << p3 << std::endl;

    // Testing negation operator (!)
    if (!p1)
    {
        std::cout << "p1 is at point (0,0)" << std::endl;
    }
    else
    {
        std::cout << "p1 is not at point (0,0)" << std::endl;
    }

    // Testing decrement operators
    --p1;
    std::cout << "After --p1: " << p1 << std::endl;

    Point p4 = p2--;
    std::cout << "After p2--: " << p2 << std::endl;
    std::cout << "Point p4 (result of p2--): " << p4 << std::endl;

    // Testing pre-increment and pre-decrement operators
    Point p5(1.0, 1.0);
    std::cout << "Initial point p5: " << p5 << std::endl;

    ++(++p5); // Chaining pre-increments
    std::cout << "After chained pre-increments: " << p5 << std::endl;

    --(--p5); // Chaining pre-decrements
    std::cout << "After chained pre-decrements: " << p5 << std::endl;

    // Testing user input
    Point p6;
    std::cout << "Enter values for p6:" << std::endl;
    std::cin >> p6;
    std::cout << "You entered the point: " << p6 << std::endl;

    return 0;
}