#include <iostream>
#include "Fraction.h"
using namespace std;

int main() {
    Fraction f1;
    cin >> f1;

    cout << "Numerator F1 = " << f1.getNumerator() << "\n";
    cout << "Denominator F1 = " << f1.getDenominator() << "\n";

    Fraction f2;
    cin >> f2;

    cout << "Numerator F2 = " << f2.getNumerator() << "\n";
    cout << "Denominator F2 = " << f2.getDenominator() << "\n";

    Fraction f3 = f1 + (f2);
    cout << "Sum of F1 and F2: ";
    cout << f3 << "\n";

    f3 = f1 - (f2);
    cout << "Subtraction of F1 and F2: " <<  f3 <<"\n";

    f3 = f1 * f2;
    cout << "Multiplication of F1 and F2: " << f3 << "\n";

    f3 = f1 / f2;
    cout << "Division of F1 and F2: " << f3 << "\n";
    
    if (f1 < f2)
    {
        cout << "Lesser: " << f1 << "\n";
    }
    else if (f1 != f2)
    {
        cout << "Lesser: " << f2 << "\n";
    }

    if (f1 > f2)
    {
        cout << "Greater: " << f1 << "\n";
    }
    else if (f1 != f2)
    {
        cout << "Greater: " << f2 << "\n";
    }
    else if (f1 == f2)
    {
        cout << "Equal\n\n";
    }
    else
    {
         cout << "Different\n\n";
    }

    cout << "F1 as Float: " << f1.asFloat() << "\n";
    cout << "F2 as Float: " << f2.asFloat() << "\n";

    return 0;
}