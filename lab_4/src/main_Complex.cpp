#include "Complex.h"

using namespace std;

int main()
{
    Complex c1;
    Complex c2(2, 4);
    cout << "c1: " << c1 << "\n";
    cout << "c2: " << c2 << "\n";

    Complex c3;

    c3 = c1 + (c2);
    cout << "Sum: " << c3 << "\n";

    c3 = c1 - (c2);
    cout << "Subtraction: " << c3 << "\n";

    c3 = c1 * (c2);
    cout << "Multiplication: " << c3 << "\n";

    c3 = c1 / (c2);
    cout << "Division: " << c3 << "\n";

    cout << "Modulus c1: " << c1.modulus() << "\n";

    cout << "Number of complex numbers stored: " << c1.printNumberOfComplexes() << "\n";

    return 0;
}