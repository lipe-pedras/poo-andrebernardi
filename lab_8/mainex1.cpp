#include "polinomio.cpp"
#include <iostream>

using namespace std;

int main()
{
    Polinomio p(2);

    try
    {
        cout << "Coef posi 0: " << p[0] << endl;
        cout << "Coef posi 10: " << p[10] << endl;
    }
    catch (const out_of_range &e)
    {
        cerr << "exception: " << e.what() << endl;
    }

    return 0;
}