#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <bits/stdc++.h>
#include <iostream>
#include <stdexcept>


using namespace std;

class TrianguloRetangulo
{
private:
    int lado1;
    int lado2;
    int lado3;

public:
    TrianguloRetangulo(int a, int b, int c);
    bool ehTrianguloRetangulo() const;
    void imprimirLados() const;
};

#endif