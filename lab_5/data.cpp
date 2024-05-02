#include "data.h"

Data::Data()
{
    setData(1, 1, 1);
}

Data::Data(int d, int m, int a)
{
    setData(d, m, a);
}

void Data::setData(int d, int m, int a)
{
    if (d > dias_meses[m])
    {
        d = 1;
        m++;
    }
    else if (d < 1)
    {
        m--;
        d = dias_meses[m];
    }
    if (m < 1)
    {
        m = 12;
        a--;
    }
    else if (m > 12)
    {
        m = 1;
        a++;
    }
    if (a <= 0)
        a = 1;

    bissexto = ((ano % d) == 0);

    dia = d;
    mes = m;
    ano = a;
}

Data &Data::operator++()
{
    setData(dia + 1, mes, ano);
    return *this;
}

Data Data::operator++(int)
{
    Data temp{*this};
    setData(dia + 1, mes, ano);
    return temp;
}

Data &Data::operator--()
{
    setData(dia - 1, mes, ano);
    return *this;
}

Data Data::operator--(int)
{
    Data temp{*this};
    setData(dia - 1, mes, ano);
    return temp;
}

istream &operator>>(istream &in, Data &d)
{
    cout << "Entre com o dia.\n";
    in >> d.dia;
    cout << "Entre com o mes.\n";
    in >> d.mes;
    cout << "Entre com o ano.\n";
    in >> d.ano;
    d.setData(d.dia, d.mes, d.ano);
    return in;
}

ostream &operator<<(ostream &out, const Data &d)
{
    static const string nome_meses[13] = {"", "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    out << d.dia << " de " << nome_meses[d.mes] << " de " << d.ano;
    return out;
}