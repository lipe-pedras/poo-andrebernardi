#include "../include/polynomial.h"
#include <iostream>

using namespace std;

int main()
{
    Polynomial p(2);

    try
    {
        cout << "Coefficient at position 0: " << p[0] << endl;
        cout << "Coefficient at position 10: " << p[10] << endl;
    }
    catch (const out_of_range &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
