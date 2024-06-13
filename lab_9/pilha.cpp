#include "pilha.h"
#include <stdexcept>

using namespace std;

template <typename T>
CPilha<T>::CPilha(int memoria)
{
    m_ponteirodaPilha = -1;
    m_tamanho = (memoria > 0) ? memoria : 10;
    m_dados = new T[m_tamanho];
}

template <typename T>
CPilha<T>::~CPilha()
{
    delete[] m_dados;
}

template <typename T>
bool CPilha<T>::pop(T &pop_to)
{
    if (m_ponteirodaPilha == -1)
        return false;
    pop_to = m_dados[m_ponteirodaPilha--];
    return true;
}
// empurrar dados para a pilha
template <typename T>
bool CPilha<T>::push(T push_this) // melhor seria constT&
{
    if (m_ponteirodaPilha == m_tamanho - 1)
        return false;
    m_dados[++m_ponteirodaPilha] = push_this;
    return true;
}

template <typename T>
CPilha<T>::CPilha(const CPilha<T> &p)
{
    m_ponteirodaPilha = p.m_ponteirodaPilha;
    m_tamanho = p.m_tamanho;
    for (int i = 0; i < m_tamanho + 1; i++)
    {
        m_dados[i] = p.m_dados[i];
    }
}

template <typename T>
CPilha<T> &CPilha<T>::operator=(const CPilha<T> &p)
{
    delete[] m_dados;
    m_ponteirodaPilha = p.m_ponteirodaPilha;
    m_tamanho = p.m_tamanho;
    m_dados = new int[m_tamanho];
    for (int i = 0; i < m_tamanho + 1; i++)
    {
        m_dados[i] = p.m_dados[i];
    }
    return *this;
}

// implementação de templates direto com a definição
template <typename T>
ostream &operator<<(ostream &out, const CPilha<T> &p)
{
    for (int i = 0; i <= p.m_ponteirodaPilha; i++)
        out << p.m_dados[i] << " ";
    out << endl;
    return out;
}
template <typename T>
istream &operator>>(istream &in, CPilha<T> &p)
{
    T a;
    p.m_ponteirodaPilha = -1; // esvaziar a pilha
    cout << "Entre com os " << p.m_tamanho << " dados da pilha: ";
    for (int i = 0; i < p.m_tamanho; i++)
    {
        in >> a;
        if (!p.push(a))
            break; // se não conseguiu inserir aborta.
    }
    return in;
}