#include <iostream>
#include "polinomio.h"

using namespace std;

int main() {
    Polinomio p;
    cin >> p;

    // Calcula e exibe a derivada do polinomio
    Polinomio derivada = p.derivada();
    cout << "Derivada do polinomio: " << derivada << endl;

    // Calcula e exibe o valor do polinomio em um ponto específico
    double x;
    cout << "Digite um valor para calcular o polinomio nesse ponto: ";
    cin >> x;
    double valor = p.calcular(x);
    cout << "Valor do polinomio em x = " << x << " e: " << valor << endl;

    // Encontra uma raiz usando o metodo de Newton
    double x0;
    int max_iter;
    double epsilon;
    cout << "Digite um valor inicial para o metodo de Newton: ";
    cin >> x0;
    cout << "Digite o numero maximo de iteracoes: ";
    cin >> max_iter;
    cout << "Digite o valor de epsilon (tolerancia): ";
    cin >> epsilon;

    double raiz = p.newton(x0, max_iter, epsilon);
    cout << "Raiz encontrada pelo metodo de Newton: " << raiz << endl;

    return 0;
}
