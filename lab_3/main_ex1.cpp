#include "complexos.h"
#include <iostream>

using namespace std;

int main()
{
    Complexo c1;
    Complexo c2(2, 4);
    cout << "c1: " << c1.printRetangular() << "\n";
    cout << "c2: " << c2.printRetangular() << "\n";

    Complexo c3;

    c3 = c1.soma(c2);
    cout << "Soma: " << c3.printRetangular() << "\n";

    c3 = c1.subtracao(c2);
    cout << "Subtracao: " << c3.printRetangular() << "\n";

    c3 = c1.multiplicacao(c2);
    cout << "Multiplicacao: " << c3.printRetangular() << "\n";

    c3 = c1.divisao(c2);
    cout << "Divisao: " << c3.printRetangular() << "\n";

    cout << "Modulo c1: " << c1.modulo() << "\n";

    cout << "Numero de numeros complexos armazenados: " << c1.printNumberOfComplexes() << "\n";

    return 0;
}
