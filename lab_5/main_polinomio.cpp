#include "polinomio.h"

using namespace std;

int main()
{
    Polinomio p;
    cout << p << "\n";

    p = Polinomio(4);
    cout << p << "\n";

    Polinomio q;
    cin >> q;

    cout << p + q << "\n";
    cout << p - q << "\n";
    cout << p[9];
}