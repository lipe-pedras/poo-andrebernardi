#include <iostream>
#include "Ponto.h"

int main()
{
    // Criando pontos e testando metodos
    Ponto p1(3.0, 4.0);
    Ponto p2(0.0, 0.0);

    // Imprimindo os pontos
    std::cout << "Ponto p1: " << p1 << std::endl;
    std::cout << "Ponto p2: " << p2 << std::endl;

    // Testando operadores de incremento
    ++p1;
    std::cout << "Apos ++p1: " << p1 << std::endl;

    Ponto p3 = p2++;
    std::cout << "Apos p2++: " << p2 << std::endl;
    std::cout << "Ponto p3 (resultado de p2++): " << p3 << std::endl;

    // Testando operador de negaçao (!)
    if (!p1)
    {
        std::cout << "p1 esta no ponto (0,0)" << std::endl;
    }
    else
    {
        std::cout << "p1 nao esta no ponto (0,0)" << std::endl;
    }

    // Testando operadores de decremento
    --p1;
    std::cout << "Apos --p1: " << p1 << std::endl;

    Ponto p4 = p2--;
    std::cout << "Apos p2--: " << p2 << std::endl;
    std::cout << "Ponto p4 (resultado de p2--): " << p4 << std::endl;

    // Testando operadores de pre-incremento e pre-decremento
    Ponto p5(1.0, 1.0);
    std::cout << "Ponto p5 inicial: " << p5 << std::endl;

    ++(++p5); // Chaining de pre-incrementos
    std::cout << "Apos pre-incrementos encadeados: " << p5 << std::endl;

    --(--p5); // Chaining de pre-decrementos
    std::cout << "Apos pre-decrementos encadeados: " << p5 << std::endl;

    // Testando entrada de valores pelo usuário
    Ponto p6;
    std::cout << "Entre com os valores de p6:" << std::endl;
    std::cin >> p6;
    std::cout << "Voce inseriu o ponto: " << p6 << std::endl;

    return 0;
}
