// arquivo pilha.h
// header file para classe pilha
#ifndef PILHA_H
#define PILHA_H

#include <iostream>
using namespace std;

template <typename T>
class CPilha
{
private:
    T *m_dados;          // ponteiro para dados da pilha
    int m_ponteirodaPilha; // apontador do topo da pilha
    int m_tamanho;         // espaço de memória reservado para o objeto
public:
    CPilha(int memoria = 0); // construtor com parametro
    virtual ~CPilha(void);   // destrutor
    bool pop(T &pop_to);
    bool push(T push_this);

    CPilha(const CPilha&);
    CPilha& operator = (const CPilha&);

    template <typename T1>
    friend ostream& operator<< (ostream& , const CPilha<T1>&);
    template <typename T1>
    friend istream& operator>> (istream& , CPilha<T1>&);
};

#endif