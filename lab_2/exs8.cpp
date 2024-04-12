#include <iostream>
#include "CFracao.cpp"
using namespace std;

int main() {
    CFracao f1(2, 4);

    cout << "Numerador F1 = " << f1.getNumerador() << "\n";
    cout << "Denominador F1 = " << f1.getDenominador() << "\n";

    CFracao f2(8, 4);

    cout << "Numerador F2 = " << f2.getNumerador() << "\n";
    cout << "Denominador F2 = " << f2.getDenominador() << "\n";

    CFracao f3 = f1.Somar(f2);
    cout << "Soma de F1 e F2: ";
    f3.Print();
    cout << "\n";


    f3 = f1.Subtrair(f2);
    cout << "Subtracao de F1 e F2: ";
    f3.Print();
    cout << "\n";


    f3 = f1.Multiplicar(f2);
    cout << "Multiplicacao de F1 e F2: ";
    f3.Print();
    cout << "\n";


    f3 = f1.Dividir(f2);
    cout << "Divisao de F1 e F2: ";
    f3.Print();
    cout << "\n";
    
    if (f1.MenorQue(f2))
    {
        cout << "Menor: ";
        f1.Print();
        cout << "\n";
    }

    else if (!(f1.Igual(f2)))
    {
        cout << "Menor: ";
        f2.Print();
        cout << "\n";
    }

    if (f1.MaiorQue(f2))
    {
        cout << "Maior: ";
        f1.Print();
        cout << "\n";
    }

    else if (!(f1.Igual(f2)))
    {
        cout << "Maior: ";
        f2.Print();
        cout << "\n";
    }

    else
    {
        cout << "Iguais\n\n";
    }

    cout << "F1 Floater: " << f1.ComoFloat();
    cout << "F2 Floater: " << f2.ComoFloat();

    return 0;
    
}