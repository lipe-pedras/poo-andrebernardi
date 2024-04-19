// arquivo CFracao.h - interface para a classe CFracao
#ifndef ID_CFRACAO
#define ID_CFRACAO

#include <iostream>

class CFracao
{
private:
    int m_numerador;
    int m_denominador;
    // reduz a fração em sua forma mínima
    CFracao Reduzida(void);

public:
    CFracao(void)
    {
        m_numerador = 1;
        m_denominador = 1;
    }
    // Construtor com parâmetros inline
    CFracao(int Num, int Denom) : m_numerador(Num),
                                  // Construtor sem parâmetros inline
                                  m_denominador(Denom){};
    CFracao(const CFracao &f) // Construtor de copia inline
    {
        m_numerador = f.m_numerador;
        m_denominador = f.m_denominador;
    }
    ~CFracao(void){};
    // Destrutor
    //
    // métodos de acesso
    int getNumerador(void) { return m_numerador; }
    int getDenominador(void) { return m_denominador; }
    //
    // métodos aritméticos
    // retorna uma nova fração que é a soma do receptor com _F
    CFracao operator+(CFracao _F);
    // retorna uma nova fração que é a subtração do receptor com _F
    CFracao operator-(CFracao _F);

    // retorna uma nova Fracao que o produto do receptor e _F
    CFracao operator*(CFracao _F);
    // retorna uma nova Fracao que o quociente do receptor e _F
    CFracao operator/(CFracao _F);
    //
    // métodos de comparação
    // devolve verdadeiro se receptor menor que _Fracao
    int operator<(CFracao _Fracao);
    // devolve verdadeiro se receptor maior que _Fracao
    int operator>(CFracao _Fracao);
    // devolve verdadeiro se receptor igual a _Fracao
    int operator==(CFracao _Fracao);
    //
    int operator<=(CFracao _Fracao);
    //
    int operator>=(CFracao _Fracao);
    //
    int operator!=(CFracao _Fracao);
    //
    friend std::ostream &operator<<(std::ostream &out, const CFracao &_Fracao);
    friend std::istream &operator>>(std::istream &in, CFracao &_Fracao);

    // métodos de conversão
    // devolve o valor da fração como float
    float ComoFloat(void);
    //
    // métodos de impressão
    // mostrar o receptor no formato “m_numerador/m_denominador”
    void Print(void);
};
#endif // ID_CFRACAO