#include "ponto.h"

using namespace std;

int main() {
    Ponto ponto(3.0, 4.0);

    cout << "ponto: " << ponto << endl;

    ++ponto;
    cout << "++ponto: " << ponto << endl;

    Ponto outroPonto = ponto++;
    cout << "ponto++: " << ponto << endl;
    cout << "outro ponto: " << outroPonto << endl;

    cin >> ponto;
    cout << ponto;

    return 0;
}
