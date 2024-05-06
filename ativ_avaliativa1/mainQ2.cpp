#include "polinomio.h"
#include <iostream>

using namespace std;

int main()

{
    Polinomio p1, p2;

    cin >> p1 >> p2;

    cout << "p1 == p2: " << (p1 == p2) << endl
         << "p1 != p2: " << (p1 != p2) << endl
         << "p1 > p2: " << (p1 > p2) << endl
         << "p1 < p2: " << (p1 < p2) << endl
         << "p1 >= p2: " << (p1 >= p2) << endl
         << "p1 <= p2: " << (p1 <= p2) << endl;
}