#include "Polynomial.h"
#include <cstring>

using namespace std;

Polynomial::Polynomial()
{
    degree = 0;
    coefficients = new double[1];
    coefficients[0] = 0;
}

Polynomial::Polynomial(int grade) : degree(grade)
{
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; i++)
    {
        cout << "coefficient for degree " << i << "\n";
        cin >> coefficients[i];
    }
}

Polynomial::Polynomial(const Polynomial &p)
{
    degree = p.degree;
    coefficients = new double[degree + 1];

    memcpy(coefficients, p.coefficients, (degree + 1) * sizeof(double));
}

Polynomial::~Polynomial()
{
    delete [] coefficients;
}

Polynomial Polynomial::operator=(const Polynomial &p)
{
    delete [] coefficients;
    degree = p.degree;
    coefficients = new double[degree+1];
    memcpy(coefficients, p.coefficients, (degree + 1) * sizeof(double));
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial &p) const
{
    Polynomial sum;
    int lesser_degree = min(degree, p.degree);
    if (lesser_degree == degree)
    {
        sum = Polynomial(p);
        for (int i = 0; i <= lesser_degree; i++)
        {
            sum.coefficients[i] += coefficients[i];
        }
    }
    else
    {
        sum = Polynomial(*this);
        for (int i = 0; i <= lesser_degree; i++)
        {
            sum.coefficients[i] += p.coefficients[i];
        }
    }
    return sum;
}

Polynomial Polynomial::operator-(const Polynomial &p) const
{
    Polynomial sub;
    int lesser_degree = min(degree, p.degree);
    if (lesser_degree == degree)
    {
        sub = Polynomial(p);
        for (int i=0; i <= p.degree; i++)
        {
            sub.coefficients[i] *= -1;
        }
        for (int i = 0; i <= lesser_degree; i++)
        {
            sub.coefficients[i] += coefficients[i];
        }
    }
    else
    {
        sub = Polynomial(*this);
        for (int i = 0; i <= lesser_degree; i++)
        {
            sub.coefficients[i] -= p.coefficients[i];
        }
    }
    return sub;
}

double Polynomial::operator[](int position) const
{
    return (position > degree || position < 0) ? 0.0 : coefficients[position];
}

ostream& operator<<(ostream &out, const Polynomial &p)
{
    for (int x = 0; x <= p.degree; x++)
    {
        out << p.coefficients[x] << "x^" << x << " ";
    }
    return out;
}

istream& operator>>(istream &in, Polynomial &p)
{
    int grade;
    cout << "degree: ";
    cin >> grade;
    p.degree = grade;
    p.coefficients = new double[grade+1];
    
    for (int i = 0; i <= grade; i++)
    {
        cout << "coefficient for degree " << i << ":\n";
        in >> p.coefficients[i];
    }
    return in;
}