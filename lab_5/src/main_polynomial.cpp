#include "Polynomial.h"

using namespace std;

int main()
{
    Polynomial p;
    cout << p << "\n";

    p = Polynomial(4);
    cout << p << "\n";

    Polynomial q;
    cin >> q;

    cout << p + q << "\n";
    cout << p - q << "\n";
    cout << p[9];
    return 0;
}