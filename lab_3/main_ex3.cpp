#include "triangulo.cpp"

using namespace std;

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