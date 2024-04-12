#include "poligono.h"
#include <iostream>
#include <cmath>


using namespace std;

Poligono::Poligono(int n = 3, float c = 1) : n(n), c(c)
{
    cout << "Poligono criado" << endl;
}

Poligono::~Poligono() {}

void Poligono::set(int n, float c)
{
    this->n = n;
    this->c = c;
}

string Poligono::nome() const
{
    switch (n)
    {
    case 3:
        return "Triangulo";
        break;

    case 4:
        return "Retangulo";
        break;

    case 5:
        return "Pentagono";
        break;

    case 6:
        return "Hexagono";
        break;

    case 7:
        return "Heptagono";
        break;

    case 8:
        return "Octogono";
        break;

    case 9:
        return "Eneagono";
        break;

    case 10:
        return "Decagono";
        break;

    default:
        cerr << "Este metodo foi programado apenas para poligonos de 3 ate 10 lados.\n";
        return "";
        break;
    }
}

float Poligono::area()
{
    return 0.25 * n * c * c * (cos(3.1415 / n) / sin(3.1415 / n));
}

float Poligono::perimetro()
{
    return n * c;
}
