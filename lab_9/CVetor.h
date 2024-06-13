#ifndef CVETOR_H
#define CVETOR_H

#define STD_SIZE 10

#include <iostream>
using namespace std;

template <typename T>
class CVetor
{
private:
    int size;
    T *v;

public:
    CVetor()
    {
        size = 10;
        v = new T[STD_SIZE];
        for (int i = 0; i < size; i++)
        {
            v[i] = 0;
        }
    }
    CVetor(int _size)
    {
        v = new T[_size];
        size = _size;
        for (int i = 0; i < size; i++)
        {
            v[i] = 0;
        }
    }
    virtual ~CVetor() { delete[] v; }
    CVetor(const CVetor<T> &_other)
    {
        size = _other.size;
        v = new T[size];
        for (int i = 0; i < size; i++)
        {
            v[i] = _other.v[i];
        }
    }
    CVetor &operator=(const CVetor &_other)
    {
        size = _other.size;
        v = new T[size];
        for (int i = 0; i < size; i++)
        {
            v[i] = _other.v[i];
        }
    }

    T &operator[](int i)
    {
        if (i > 0 && i < size)
        {
            return v[i];
        }
        else
        {
            throw out_of_range("Index out of bounderies!");
        }
    }
    void ordena()
    {
        T aux;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (v[j] > v[j + 1])
                {
                    aux = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = aux;
                }
            }
        }
    }
    friend ostream &operator<<(ostream &out, const CVetor<T> &C)
    {
        for (int i = 0; i < C.size; i++)
        {
            out << C.v[i];
        }
        return out;
    }

    friend istream &operator>>(istream &in, CVetor<T> &C)
    {
        cout << "Enter with " << C.size << " values.\n";
        for (int i = 0; i < C.size; i++)
        {
            in >> C.v[i];
        }
        return in;
    }
};

#endif