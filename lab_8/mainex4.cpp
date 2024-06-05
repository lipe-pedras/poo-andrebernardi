#include <iostream>
#include "pilha.cpp"

using namespace std;

int main()
{
    CPilha pInt;
    int aux;
    try
    {
        // usando a pilha de inteiros
        cin >> pInt;
        cout << "Valor no topo da pilha: " << pInt.pop(aux) << endl;
        cout << pInt;
    }
    catch (runtime_error &rt)
    {
        cout << rt.what() << endl;
    }
    return 0;
}