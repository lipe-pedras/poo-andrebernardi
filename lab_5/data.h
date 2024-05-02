// data.h
#ifndef DATA_H
#define DATA_H

#include <iostream>
using namespace std;

static const int dias_meses[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Data
{
private:
    int dia;
    int mes;
    int ano;
    bool bissexto;

public:
    Data();
    Data(int d, int m, int a);

    void setData(int d, int m, int a);
    Data &operator++();
    Data operator++(int);

    Data &operator--();
    Data operator--(int);

    friend ostream &operator<<(ostream &out, const Data &d);
    friend istream &operator>>(istream &in, Data &d);
};
#endif
