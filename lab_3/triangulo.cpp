#include <iostream>
#include <stdexcept>
#include <bits/stdc++.h>

using namespace std;

class TrianguloRetangulo
{
private:
    int lado1;
    int lado2;
    int lado3;

public:
    TrianguloRetangulo(int a, int b, int c) : lado1(a), lado2(b), lado3(c)
    {
        if (!ehTrianguloRetangulo())
        {
            throw std::invalid_argument("Os lados fornecidos nao formam um triangulo valido.");
        }
    }

    bool ehTrianguloRetangulo() const
    {
        vector<int> lados{lado1, lado2, lado3};
        sort(lados.begin(), lados.end(), greater<int>());
        return ((lados[0] * lados[0] == lados[2] * lados[2] + lados[1] * lados[1]));
    }

    void imprimirLados() const
    {
        std::cout << "Lados do triangulo retangulo: " << lado1 << ", " << lado2 << ", " << lado3 << std::endl;
    }
};

int main()
{
    int triangulos = 0;
    for (int a = 1; a < 201; a++)
    {
        for (int b = 1; b < 201; b++)
        {
            for (int c = 1; c < 201; c++)
            {
                try
                {
                    // Criar um triângulo retângulo válido
                    TrianguloRetangulo t1(a, b, c);
                    t1.imprimirLados();
                    triangulos++;
                }
                catch (const std::invalid_argument &e)
                {
                    continue;
                }
            }
        }
    }

    cout << "\n\n" << triangulos;

    return 0;
}
