#include "include/complex.h"
#include <iostream>

using namespace std;

int main()
{
    Complex c1;
    Complex c2(2, 4);
    cout << "c1: " << c1.printRectangular() << "\n";
    cout << "c2: " << c2.printRectangular() << "\n";

    Complex c3;

    c3 = c1 + (c2);
    cout << "Sum: " << c3.printRectangular() << "\n";

    c3 = c1 - (c2);
    cout << "Subtraction: " << c3.printRectangular() << "\n";

    c3 = c1 * (c2);
    cout << "Multiplication: " << c3.printRectangular() << "\n";

    c3 = c1 / (c2);
    cout << "Division: " << c3.printRectangular() << "\n";

    cout << "Magnitude c1: " << c1.magnitude() << "\n";

    cout << "Number of complex numbers stored: " << Complex::getComplexCount() << "\n";

    return 0;
}