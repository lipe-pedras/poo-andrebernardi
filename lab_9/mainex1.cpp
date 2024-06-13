#include <iostream>
#include "CVetor.h"

using namespace std;

int main()
{
    CVetor<int> a(5);
    CVetor<double> b(3);

    cin >> a;
    cout << a << endl;
    a.ordena();
    cout << a << endl << endl;

    cin >> b;
    cout << b << endl;
    b.ordena();
    cout << b << endl;

    try
    {
        cout << b[5];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}