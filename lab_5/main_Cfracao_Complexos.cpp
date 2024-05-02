#include "CFracao.h"
#include "complexos.h"
#include <iostream>

using namespace std;

int main()
{
    CFracao f1(2, 3), f2(3, 4);

    cout << "f1: " << f1 << "\nf2: " << f2 << "\n";
    f1++;
    ++f2;
    cout << "pos incre f1: " << f1 << "\npre incre f2: " << f2 << "\n";

    f1--;
    --f2;
    cout << "pos decre f1: " << f1 << "\npre decre f2: " << f2 << "\n\n\n";

    Complexo c1 = static_cast<Complexo>(f2), c2(3, 4);

    cout << "c1: " << c1 << "\nc2: " << c2 << "\n";
    c1++;
    ++c2;
    cout << "pos incre c1: " << c1 << "\npre incre c2: " << c2 << "\n";

    c1--;
    --c2;
    cout << "pos decre c1: " << c1 << "\npre decre c2: " << c2 << "\n";
}