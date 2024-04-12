#include "retangulo.h"
#include <iostream>

using namespace std;

Retangulo::Retangulo(int c, int l) : comprimento(c), largura(l)
{
    cout << "criando objeto retangulo...\n"; // Questão 1
    setComprimento(c);
    setLargura(l);
    cout << "objeto criado com sucesso!\n\n"; // Questão 1
}

Retangulo::~Retangulo()
{
    cout << "objeto destruido.\n"; // Questão 1
}

void Retangulo::setComprimento(int c) // Questão 2
{
    if (c <= 0 || c > 20)
    {
        comprimento = 1;
        cerr << "Valor inválido para o comprimento. Entre com um valor de 0 a 20.\n";
    }
    else
    {
        comprimento = c;
    }
}

void Retangulo::setLargura(int l) // Questão 2
{
    if (l <= 0 || l > 20)
    {
        largura = 1;
        cerr << "Valor inválido para a largura. Entre com um valor de 0 a 20.\n";
    }
    else
    {
        largura = l;
    }
}

int Retangulo::getComprimento() const
{
    return comprimento;
}

int Retangulo::getLargura() const
{
    return largura;
}

double Retangulo::getArea() const
{
    return comprimento * largura;
}

double Retangulo::getPerimetro() const
{
    return (comprimento + largura) * 2;
}

void Retangulo::printRetangulo() const
{
    for (int i = 0; i < largura; i++)
    {
        for (int j = 0; j < comprimento; j++)
        {
            cout << '*';
        }
        cout << "\n";
    }
    cout << "\n\n";
}

bool Retangulo::Is_Square() const
{
    return (comprimento == largura);
}
