#include <iostream>
#include "../include/Fraction.h"

using namespace std;

int main() {
    Fraction f1(2, 4);

    cout << "Numerator F1 = " << f1.getNumerator() << "\n";
    cout << "Denominator F1 = " << f1.getDenominator() << "\n";

    Fraction f2(8, 4);

    cout << "Numerator F2 = " << f2.getNumerator() << "\n";
    cout << "Denominator F2 = " << f2.getDenominator() << "\n";

    Fraction f3 = f1.Add(f2);
    cout << "Sum of F1 and F2: ";
    f3.Print();
    cout << "\n";

    f3 = f1.Subtract(f2);
    cout << "Subtraction of F1 and F2: ";
    f3.Print();
    cout << "\n";

    f3 = f1.Multiply(f2);
    cout << "Multiplication of F1 and F2: ";
    f3.Print();
    cout << "\n";

    f3 = f1.Divide(f2);
    cout << "Division of F1 and F2: ";
    f3.Print();
    cout << "\n";
    
    if (f1.LessThan(f2))
    {
        cout << "Smaller: ";
        f1.Print();
        cout << "\n";
    }
    else if (!(f1.Equal(f2)))
    {
        cout << "Smaller: ";
        f2.Print();
        cout << "\n";
    }

    if (f1.GreaterThan(f2))
    {
        cout << "Greater: ";
        f1.Print();
        cout << "\n";
    }
    else if (!(f1.Equal(f2)))
    {
        cout << "Greater: ";
        f2.Print();
        cout << "\n";
    }
    else
    {
        cout << "Equal\n\n";
    }

    cout << "F1 as float: " << f1.AsFloat() << "\n";
    cout << "F2 as float: " << f2.AsFloat() << "\n";

    return 0;
}