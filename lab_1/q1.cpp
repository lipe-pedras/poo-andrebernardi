#include <iostream>

using namespace std;

int fatorial (int n)
{
    if ( n == 0 ) { return 1; }
    else if ( n == 1 ) { return 1; }
    else return n * fatorial(n-1);
}

int main()
{
    int numero;
    cout << "Digite o numero cujo fatorial sera calculado.\n";
    cin >> numero;
    numero = fatorial(numero);
    cout << numero;

}

