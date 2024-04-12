#include <iostream>
#include "retangulo.h"

using namespace std;

int main()
{
    cout << "Questao 5 & 6\n\n";    

    Retangulo* retangulos[5];

    int c, l;

    for (int i=0; i<5;i++)
    {

        cout << "Entre com os valores para o comprimento e a largura do retangulo " << i+1 << "\n";
        cin >> c >> l;
        retangulos[i] = new Retangulo(c, l);
    }

    for (int i=0; i<5; i++)
    {
        retangulos[i]->printRetangulo();
    }

    for (int i=0; i<5; i++)
    {
        delete retangulos[i];
    }

    return 0;
}