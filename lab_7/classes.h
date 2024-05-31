#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Politico {
public:
    Politico() {
        cout << "Um politico foi criado.\n";
        PreencheDados();
    }
    virtual ~Politico() {
        cout << "Um politico foi destruido.\n";
    }

    void virtual Imprime() const {
        cout << "Nome: " << Nome << ", Partido: " << Partido;
    }

    void PreencheDados() {
        cout << "Digite o nome e o partido do politico:\n";
        cin >> Nome >> Partido;
    }

    friend ostream& operator<<(ostream& os, const Politico& p) {
        os << "Nome: " << p.Nome << ", Partido: " << p.Partido;
        return os;
    }

    friend istream& operator>>(istream& is, Politico& p) {
        is >> p.Nome >> p.Partido;
        return is;
    }

    string Nome;
    string Partido;
};

class Presidente : public Politico {
public:
    Presidente() {
        cout << "Um presidente foi criado.\n";
        PreencheDados();
    }
    virtual ~Presidente() {
        cout << "Um presidente foi destruido.\n";
    }

    void virtual Imprime() const {
        Politico::Imprime();
        cout << ", Pais: " << Pais;
    }

    void PreencheDados() {
        cout << "Digite o pais do presidente:\n";
        cin >> Pais;
    }

    friend ostream& operator<<(ostream& os, const Presidente& p) {
        os << static_cast<const Politico&>(p) << ", Pais: " << p.Pais;
        return os;
    }

    friend istream& operator>>(istream& is, Presidente& p) {
        is >> static_cast<Politico&>(p) >> p.Pais;
        return is;
    }

    string Pais;
};

class Governador : public Presidente {
public:
    Governador() {
        cout << "Um governador foi criado.\n";
        PreencheDados();
    }
    virtual ~Governador() {
        cout << "Um governador foi destruido.\n";
    }

    void virtual Imprime() const {
        Presidente::Imprime();
        cout << ", Estado: " << Estado;
    }

    void PreencheDados() {
        cout << "Digite o estado do governador:\n";
        cin >> Estado;
    }

    friend ostream& operator<<(ostream& os, const Governador& g) {
        os << static_cast<const Presidente&>(g) << ", Estado: " << g.Estado;
        return os;
    }

    friend istream& operator>>(istream& is, Governador& g) {
        is >> static_cast<Presidente&>(g) >> g.Estado;
        return is;
    }

    string Estado;
};

class Prefeito : public Governador {
public:
    Prefeito() {
        cout << "Um prefeito foi criado.\n";
        PreencheDados();
    }
    virtual ~Prefeito() {
        cout << "Um prefeito foi destruido.\n";
    }

    void virtual Imprime() const {
        Governador::Imprime();
        cout << ", Cidade: " << Cidade;
    }

    void PreencheDados() {
        cout << "Digite a cidade do prefeito:\n";
        cin >> Cidade;
    }

    friend ostream& operator<<(ostream& os, const Prefeito& p) {
        os << static_cast<const Governador&>(p) << ", Cidade: " << p.Cidade;
        return os;
    }

    friend istream& operator>>(istream& is, Prefeito& p) {
        is >> static_cast<Governador&>(p) >> p.Cidade;
        return is;
    }

    string Cidade;
};

// exs 2
class Ponto
{
public:
    double x, y;
    Ponto()
    {
        cin >> *this;
    }

    virtual ~Ponto() {};

    virtual void imprime()
    {
        cout << *this;
    }

    friend ostream &operator<<(ostream &os, const Ponto &p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    friend istream &operator>>(istream &is, Ponto &p)
    {
        cout << "Entre com os valores de X e Y." << endl;
        is >> p.x >> p.y;
        return is;
    }
};

class Circulo : public Ponto
{
public:
    double raio;
    Circulo()
    {
        cin >> *this;
    }

    virtual ~Circulo() {};

    virtual void imprime()
    {
        cout << *this;
    }

    virtual double area() const
    {
        return M_PI * raio * raio;
    }

    friend ostream &operator<<(ostream &os, const Circulo &c)
    {
        os << "Centro: " << static_cast<Ponto>(c) << ", Raio: " << c.raio;
        return os;
    }

    friend istream &operator>>(istream &is, Circulo &c)
    {
        cout << "Entre com o valor do Raio." << endl;
        is >> c.raio;
        return is;
    }
};

class Cilindro : public Circulo
{
public:
    double altura;
    Cilindro()
    {
        cin >> *this;
    }

    virtual ~Cilindro() {};

    virtual void imprime()
    {
        cout << *this;
    }

     virtual double volume() const
    {
        return area() * altura;
    }

    friend ostream &operator<<(ostream &os, const Cilindro &c)
    {
        os << "Base = { " << static_cast<Circulo>(c) << " } | Altura: " << c.altura;
        return os;
    }

    friend istream &operator>>(istream &is, Cilindro &c)
    {
        cout << "Entre com a altura." << endl;
        is >> c.altura;
        return is;
    }
};

