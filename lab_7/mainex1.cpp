#include <iostream>
#include <vector>
#include "classes.h" 

using namespace std;

int menu();

int main()
{
    vector<Politico*> politicos;

    while (true)
    {
        switch (menu())
        {
        case 1:
            politicos.push_back(new Presidente);
            break;

        case 2:
            politicos.push_back(new Governador);
            break;

        case 3:
            politicos.push_back(new Prefeito);
            break;

        case 0:
            // Imprimir todos os políticos criados
            cout << "\nImprimindo todos os politicos criados:\n";
            for (auto* p : politicos)
            {
                p->Imprime();
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
    cout << "\nEscolha o tipo de politico a ser criado:" << endl;
    cout << "1 - Presidente" << endl;
    cout << "2 - Governador" << endl;
    cout << "3 - Prefeito" << endl;
    cout << "0 - Encerrar e imprimir politicos criados" << endl;
    cout << "Opcao: ";
    cin >> opcao;
    return opcao;
}
