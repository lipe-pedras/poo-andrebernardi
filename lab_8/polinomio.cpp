#include "polinomio.h"

using namespace std;

Polinomio::Polinomio()
{
    n = 0;
    valores = new double[1];
    valores[0] = 0;
}

Polinomio::Polinomio(int grade) : n(grade)
{
    valores = new double[n + 1];
    for (int i = 0; i <= n; i++)
    {
        cout << "coeficient for grade " << i << "\n";
        cin >> valores[i];
    }
}

Polinomio::Polinomio(const Polinomio &p)
{
    n = p.n;
    valores = new double[n + 1];

    memcpy(valores, p.valores, (n + 1) * sizeof(double));
}

Polinomio::~Polinomio()
{
    delete [] valores;
}

Polinomio Polinomio::operator=(const Polinomio &p)
{
    delete [] valores;
    n = p.n;
    valores = new double[n+1];
    memcpy(valores, p.valores, (n + 1) * sizeof(double));
    return *this;
}

Polinomio Polinomio::operator+(const Polinomio &p) const
{
    Polinomio sum;
    int lesser_n = min(n, p.n);
    if (lesser_n == n)
    {
        sum = Polinomio(p);
        for (int i = 0; i <= lesser_n; i++)
        {
            sum.valores[i] += valores[i];
        }
    }
    else
    {
        sum = Polinomio(*this);
        for (int i = 0; i <= lesser_n; i++)
        {
            sum.valores[i] += p.valores[i];
        }
    }
    return sum;
}

Polinomio Polinomio::operator-(const Polinomio &p) const
{
    Polinomio sub;
    int lesser_n = min(n, p.n);
    if (lesser_n == n)
    {
        sub = Polinomio(p);
        for (int i=0; i <= p.n; i++)
        {
            sub.valores[i] *= -1;
        }
        for (int i = 0; i <= lesser_n; i++)
        {
            sub.valores[i] += valores[i];
        }
    }
    else
    {
        sub = Polinomio(*this);
        for (int i = 0; i <= lesser_n; i++)
        {
            sub.valores[i] -= p.valores[i];
        }
    }
    return sub;
}

double Polinomio::operator[] (int pos) const
{
    if (pos >= n) throw std::out_of_range("Indice fora da faixa.");
    return (pos > n || pos < 0) ? 0.0 : valores[pos];
}

ostream& operator<< (ostream &out, const Polinomio &p)
{
    for (int x = 0; x <= p.n; x++)
    {
        out << p.valores[x] << "x^" << x << " ";
    }
    return out;
}

istream& operator>> (istream &in, Polinomio &p)
{
    int grade;
    cout << "grade: ";
    cin >> grade;
    p.n = grade;
    p.valores = new double[grade+1];
    
    for (int i = 0; i <= grade; i++)
    {
        cout << "coeficient for " << i << " grade.\n";
        in >> p.valores[i];
    }
    return in;
}