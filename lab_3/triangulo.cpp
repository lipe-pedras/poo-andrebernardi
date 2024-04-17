#include "triangulo.h"


TrianguloRetangulo::TrianguloRetangulo(int a, int b, int c) : lado1(a), lado2(b), lado3(c)
{
    if (!ehTrianguloRetangulo())
    {
        throw std::invalid_argument("Os lados fornecidos nao formam um triangulo valido.");
    }
}

bool TrianguloRetangulo::ehTrianguloRetangulo() const
{
    vector<int> lados{lado1, lado2, lado3};
    sort(lados.begin(), lados.end(), greater<int>());
    return ((lados[0] * lados[0] == lados[2] * lados[2] + lados[1] * lados[1]));
}

void TrianguloRetangulo::imprimirLados() const
{
    std::cout << "Lados do triangulo retangulo: " << lado1 << ", " << lado2 << ", " << lado3 << std::endl;
}
