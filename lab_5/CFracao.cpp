// Arquivo  CFracao.cpp - Implementação da classe CFracao
#include "CFracao.h"
#include "complexos.h"
using namespace std;

//
// Métodos Privativos da classe CFracao
//
CFracao CFracao::Reduzida(void)
{
    int gcd = 1;
    int minimo = m_numerador;
    if (m_numerador > m_denominador)
        minimo = m_denominador;
    for (int i = 1; i <= minimo; i++)
    {
        if ((m_numerador % i == 0) && (m_denominador % i == 0))
            gcd = i;
    }
    m_numerador /= gcd;
    m_denominador /= gcd;
    return (*this);
}

//
// Métodos Aritméticos da classe CFracao
//
// retorna uma nova Fracao que é a soma do receptor com _Fracao
CFracao CFracao::operator+(CFracao _Fracao)
{
    CFracao temp(m_numerador * _Fracao.m_denominador +
                     m_denominador * _Fracao.m_numerador,
                 m_denominador * _Fracao.m_denominador);
    return temp.Reduzida();
}
// retorna uma nova Fracao que é a subtração do receptor com _Fracao
CFracao CFracao::operator-(CFracao _Fracao)
{
    CFracao temp(m_numerador * _Fracao.m_denominador -
                     m_denominador * _Fracao.m_numerador,
                 m_denominador * _Fracao.m_denominador);
    return temp.Reduzida();
}

// retorna uma nova Fracao que o produto do receptor e _Fracao
CFracao CFracao::operator*(CFracao _Fracao)
{
    CFracao temp(m_numerador * _Fracao.m_numerador,
                 m_denominador * _Fracao.m_denominador);
    return temp.Reduzida();
}

// retorna uma nova Fracao que o quociente do receptor e _Fracao
CFracao CFracao::operator/(CFracao _Fracao)
{
    CFracao temp(m_numerador * _Fracao.m_denominador,
                 m_denominador * _Fracao.m_numerador);
    return temp.Reduzida();
}
//
// Métodos de comparação da classe CFracao
//
// devolve verdadeiro se receptor menor que _Fracao
int CFracao::operator<(CFracao _Fracao)
{
    return (m_numerador * _Fracao.m_denominador <
            m_denominador * _Fracao.m_numerador);
}
// devolve verdadeiro se receptor maior que _Fracao
int CFracao::operator>(CFracao _Fracao)
{
    return (m_numerador * _Fracao.m_denominador >
            m_denominador * _Fracao.m_numerador);
}

// devolve verdadeiro se receptor igual a _Fracao
int CFracao::operator==(CFracao _Fracao)
{
    return (m_numerador * _Fracao.m_denominador ==
            m_denominador * _Fracao.m_numerador);
}
// devolve verdadeiro se receptor menor ou igual a _Frcao
int CFracao::operator<=(CFracao _Fracao)
{
    return (*this < _Fracao || *this == _Fracao);
}
// devolve verdadeiro se receptor maior ou igual a _Fracao
int CFracao::operator>=(CFracao _Fracao)
{
    return (*this > _Fracao || *this == _Fracao);
}
// devolve verdadeiro se receptor for diferente de _Fracao
int CFracao::operator!=(CFracao _Fracao)
{
    return (!(*this == _Fracao));
}

CFracao &CFracao::operator++()
{
    m_numerador += m_denominador;
    return *this;
}

CFracao CFracao::operator++(int)
{
    CFracao temp(*this);
    m_numerador += m_denominador;
    return temp;
}

CFracao &CFracao::operator--()
{
    m_numerador -= m_denominador;
    return *this;
}

CFracao CFracao::operator--(int)
{
    CFracao temp(*this);
    m_numerador -= m_denominador;
    return temp;
}

CFracao::operator Complexo() const
{
    return Complexo((double) m_numerador / m_denominador, 0);
}

// Função para imprimir a fração
ostream &operator<<(ostream &out, const CFracao &_Fracao)
{
    out << _Fracao.m_numerador << " / " << _Fracao.m_denominador;
    return out;
}

// Função para leitura
istream &operator>>(istream &in, CFracao &_Fracao)
{
    cout << "Entre com o numerador.\n";
    in >> _Fracao.m_numerador;
    cout << "Entre com o denominador.\n";
    in >> _Fracao.m_denominador;
    return in;
}
// Métodos de conversão
//
// devolve o valor da fração como float
float CFracao::ComoFloat(void)
{
    return ((float)m_numerador / (float)m_denominador);
}
//
// Métodos de impressão
//
// mostrar o receptor no formato m_numerador/m_denominador
void CFracao::Print(void)
{
    cout << m_numerador << "/" << m_denominador;
}