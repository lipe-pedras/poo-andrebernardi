#include "complexos.h"

using namespace std;

int main()
{
    Complexo c1;
    Complexo c2(2, 4);
    cout << "c1: " << c1 << "\n";
    cout << "c2: " << c2 << "\n";

    Complexo c3;

    c3 = c1 + (c2);
    cout << "Soma: " << c3 << "\n";

    c3 = c1 - (c2);
    cout << "Subtracao: " << c3 << "\n";

    c3 = c1 * (c2);
    cout << "Multiplicacao: " << c3 << "\n";

    c3 = c1 / (c2);
    cout << "Divisao: " << c3 << "\n";

    cout << "Modulo c1: " << c1.modulo() << "\n";

    cout << "Numero de numeros complexos armazenados: " << c1.printNumberOfComplexes() << "\n";

    return 0;
}
