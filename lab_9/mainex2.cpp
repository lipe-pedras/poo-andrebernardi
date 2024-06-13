#include <iostream>
#include "pilha.h"
using namespace std;
int main()
{
    CPilha<int> pInt;
    CPilha<char> pChar;
    CPilha<float> pFloat;
    CPilha<CPilha<int>> ppInt;
    // usando a pilha de inteiros
    cin >> pInt;
    cout << pInt;
    // usando a pilha de char
    cin >> pChar;
    cout << pChar;
    // usando a pilha de float
    cin >> pInt;
    cout << pInt;
    // usando a pilha de pilha de inteiros
    cin >> ppInt;
    cout << ppInt;
    return 0;
}