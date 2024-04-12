#include "complexos.h"
#include <iostream>
#include <cmath>

using namespace std;

static int count = 0;

Complexo::Complexo()
{
    count++;
    r = 0;
    c = 0;
}

Complexo::Complexo(double r, double c) : r(r), c(c)
{
    count++;
}

Complexo::~Complexo() {}

vector<double> Complexo::polar(Complexo C)
{
    vector<double> polarr;
    polarr.push_back(sqrt(r * r + c * c));
    if (r >= 0)
    {
        polarr.push_back(atan(c / r) * (180 / M_PI));
    }
    else
    {
        polarr.push_back((atan(c / r) * (180 / M_PI) + 180));
    }

    return polarr;
}

Complexo Complexo::retangular(vector<double> vetor)
{
    return Complexo(r = cos(vetor[1]) * vetor[0], c = sin(vetor[1]) * vetor[0]);
}

Complexo Complexo::soma(Complexo _c2)
{
    return Complexo(r = r + _c2.r, c = c + _c2.c);
}

Complexo Complexo::subtracao(Complexo _c2)
{
    return Complexo(r = r - _c2.r, c = c - _c2.c);
}

Complexo Complexo::multiplicacao(Complexo _c2)
{
    vector<double> c1_polar = polar(Complexo(r, c));
    vector<double> c2_polar = polar(_c2);
    vector<double> c3;
    c3.push_back(c1_polar[0] * c2_polar[0]);
    c3.push_back(c1_polar[1] + c2_polar[1]);
    return retangular(c3);
}

Complexo Complexo::divisao(Complexo _c2)
{
    vector<double> c1_polar = polar(Complexo(r, c));
    vector<double> c2_polar = polar(_c2);
    vector<double> c3;
    c3.push_back(c1_polar[0] / c2_polar[0]);
    c3.push_back(c1_polar[1] - c2_polar[1]);
    return retangular(c3);
}

double Complexo::modulo()
{
    return sqrt(r * r + c * c);
}