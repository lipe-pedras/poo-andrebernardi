#include "pilha.h"
#include <stdexcept>

using namespace std;

CPilha::CPilha(int memoria)
{
    m_ponteirodaPilha = -1;
    m_tamanho = (memoria > 0) ? memoria : 10;
    m_dados = new int[m_tamanho];
}

CPilha::~CPilha()
{
    delete[] m_dados;
}

int CPilha::pop(int &pop_to)
{
    if (m_ponteirodaPilha == -1)
    {
        throw runtime_error("A pilha ja esta vazia!");
    }
    else
    {
        pop_to = m_dados[m_ponteirodaPilha--];
        return pop_to;
    }
}

int CPilha::push(int value)
{
    if (m_ponteirodaPilha == m_tamanho - 1)
    {
        throw runtime_error("Pilha cheia!");
    }
    else
    {
        m_dados[++m_ponteirodaPilha] = value;
        return value;
    }
}

CPilha::CPilha(const CPilha &p)
{
    m_ponteirodaPilha = p.m_ponteirodaPilha;
    m_tamanho = p.m_tamanho;
    for (int i = 0; i < m_tamanho + 1; i++)
    {
        m_dados[i] = p.m_dados[i];
    }
}

CPilha &CPilha::operator=(const CPilha &p)
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

ostream& operator<< (ostream& out, const CPilha& p)
{
    for (int i = 0; i <= p.m_ponteirodaPilha; i++)
    {
        out << p.m_dados[i] << " ";
    }
    return out;
}

istream& operator>> (istream& in, CPilha& p)
{
    int a;
    p.m_ponteirodaPilha = -1;
    cout << "Entre com os dados da Pilha: ";
    try
    {
        for (int i = 0; i < p.m_tamanho; i++)
        {
            in >> a;
            p.push(a);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return in;
}