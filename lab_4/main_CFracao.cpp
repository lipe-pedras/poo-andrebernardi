#include <iostream>
#include "CFracao.h"
using namespace std;

int main() {
    CFracao f1;
    cin >> f1;

    cout << "Numerador F1 = " << f1.getNumerador() << "\n";
    cout << "Denominador F1 = " << f1.getDenominador() << "\n";

    CFracao f2;
    cin >> f2;

    cout << "Numerador F2 = " << f2.getNumerador() << "\n";
    cout << "Denominador F2 = " << f2.getDenominador() << "\n";

    CFracao f3 = f1 + (f2);
    cout << "Soma de F1 e F2: ";
    cout << f3 << "\n";


    f3 = f1 - (f2);
    cout << "Subtracao de F1 e F2: " <<  f3 <<"\n";


    f3 = f1 * f2;
    cout << "Multiplicacao de F1 e F2: " << f3 << "\n";


    f3 = f1 / f2;
    cout << "Divisao de F1 e F2: " << f3 << "\n";
    
    if (f1 < f2)
    {
        cout << "Menor: " << f1 << "\n";
    }

    else if (f1 != f2)
    {
        cout << "Menor: " << f2 << "\n";
    }

    if (f1 > f2)
    {
        cout << "Maior: " << f1 << "\n";
    }

    else if (f1 != f2)
    {
        cout << "Maior: " << f2 << "\n";
    }

    else if (f1 == f2)
    {
        cout << "Iguais\n\n";
    }
    else
    {
         cout << "Diferentes\n\n";
    }

    cout << "F1 Floater: " << f1.ComoFloat();
    cout << "F2 Floater: " << f2.ComoFloat();

    return 0;
    
}