#include <iostream>
#include <vector>
#include "classes.h" 

using namespace std;

int menu();

int main()
{
    vector<Ponto*> politicos;

    while (true)
    {
        switch (menu())
        {
        case 1:
            politicos.push_back(new Ponto);
            break;

        case 2:
            politicos.push_back(new Circulo);
            break;

        case 3:
            politicos.push_back(new Cilindro);
            break;

        case 0:
            // Imprimir todos os políticos criados
            cout << "\nImprimindo todos os objetos criados:\n";
            for (auto* p : politicos)
            {
                p->imprime();
                cout << endl;
            }

            // Liberar a memória alocada
            for (auto* p : politicos)
            {
                delete p;
            }

            return 0;

        default:
            cout << "Opcao invalida! Tente novamente.\n";
            break;
        }
    }

    return 0;
}

int menu()
{
    int opcao;
    cout << "\nEscolha o tipo de objeto a ser criado:" << endl;
    cout << "1 - Ponto" << endl;
    cout << "2 - Circulo" << endl;
    cout << "3 - Cilindro" << endl;
    cout << "0 - Encerrar e imprimir politicos criados" << endl;
    cout << "Opcao: ";
    cin >> opcao;
    return opcao;
}
