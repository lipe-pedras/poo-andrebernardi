#include "Fraction.h"
#include "Complex.h"
#include <iostream>

using namespace std;

int main()
{
    Fraction f1(2, 3), f2(3, 4);

    cout << "f1: " << f1 << "\nf2: " << f2 << "\n";
    f1++;
    ++f2;
    cout << "post increment f1: " << f1 << "\npre increment f2: " << f2 << "\n";

    f1--;
    --f2;
    cout << "post decrement f1: " << f1 << "\npre decrement f2: " << f2 << "\n\n\n";

    Complex c1 = static_cast<Complex>(f2), c2(3, 4);

    cout << "c1: " << c1 << "\nc2: " << c2 << "\n";
    c1++;
    ++c2;
    cout << "post increment c1: " << c1 << "\npre increment c2: " << c2 << "\n";

    c1--;
    --c2;
    cout << "post decrement c1: " << c1 << "\npre decrement c2: " << c2 << "\n";
    
    return 0;
}