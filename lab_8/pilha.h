// arquivo pilha.h
// header file para classe pilha
#ifndef PILHA_H
#define PILHA_H

#include <iostream>
using namespace std;

class CPilha
{
private:
    int *m_dados;          // ponteiro para dados da pilha
    int m_ponteirodaPilha; // apontador do topo da pilha
    int m_tamanho;         // espaço de memória reservado para o objeto
public:
    CPilha(int memoria = 0); // construtor com parametro
    virtual ~CPilha(void);   // destrutor
    int pop(int &pop_to);
    int push(int push_this);

    CPilha(const CPilha&);
    CPilha& operator = (const CPilha&);

    friend ostream& operator<< (ostream& , const CPilha&);
    friend istream& operator>> (istream& , CPilha&);
};

#endif