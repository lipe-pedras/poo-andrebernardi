#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// exs  1
class Politico
{
public:
    Politico()
    {
        cout << "Um politico foi criado.\n";
    }
    ~Politico()
    {
        cout << "Um politico foi destruido.\n";
    }
    void Imprime()
    {
        cout << "Nome: " << Nome << ", Partido: " << Partido << endl;
    }
    string Nome;
    string Partido;
};

class Presidente : public Politico
{
public:
    Presidente()
    {
        cout << "Um presidente foi criado.\n";
    }
    ~Presidente()
    {
        cout << "Um presidente foi destruido.\n";
    }
    void Imprime()
    {
        Politico::Imprime(); // Chama a função Imprime da classe base
        cout << "País: " << Pais << endl;
    }
    string Pais;
};

class Governador : public Presidente
{
public:
    Governador()
    {
        cout << "Um governador foi criado.\n";
    }
    ~Governador()
    {
        cout << "Um governador foi destruido.\n";
    }
    void Imprime()
    {
        Presidente::Imprime(); // Chama a função Imprime da classe base
        cout << "Estado: " << Estado << endl;
    }
    string Estado;
};

class Prefeito : public Governador
{
public:
    Prefeito()
    {
        cout << "Um prefeito foi criado.\n";
    }
    ~Prefeito()
    {
        cout << "Um prefeito foi destruido.\n";
    }
    void Imprime()
    {
        Governador::Imprime(); // Chama a função Imprime da classe base
        cout << "Cidade: " << Cidade << endl;
    }
    string Cidade;
};


// exs 2
class Ponto
{
public:
    double x, y;

    Ponto(double x = 0, double y = 0) : x(x), y(y) {}

    friend ostream &operator<<(ostream &os, const Ponto &p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    friend istream &operator>>(istream &is, Ponto &p)
    {
        is >> p.x >> p.y;
        return is;
    }
};

class Circulo : public Ponto
{
public:
    double raio;

    Circulo(double x = 0, double y = 0, double raio = 0) : Ponto(x, y), raio(raio) {}

    double area() const
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
        is >> static_cast<Ponto &>(c) >> c.raio;
        return is;
    }
};

class Cilindro : public Circulo
{
public:
    double altura;

    Cilindro(double x = 0, double y = 0, double raio = 0, double altura = 0) : Circulo(x, y, raio), altura(altura) {}

    double volume() const
    {
        return area() * altura;
    }

    friend ostream &operator<<(ostream &os, const Cilindro &c)
    {
        os << "Base: " << static_cast<Circulo>(c) << ", Altura: " << c.altura;
        return os;
    }

    friend istream &operator>>(istream &is, Cilindro &c)
    {
        is >> static_cast<Circulo &>(c) >> c.altura;
        return is;
    }
};

//exs 3


int main()
{
    //exs 1
    Prefeito prefeito;
    prefeito.Nome = "Joao da Silva";
    prefeito.Partido = "Partido X";
    prefeito.Pais = "Brasil";
    prefeito.Estado = "Sao Paulo";
    prefeito.Cidade = "Sao Paulo";

    prefeito.Imprime();

    //exs 2
    Ponto p(1, 2);
    cout << "Ponto: " << p << endl;

    Circulo c(1, 2, 3);
    cout << "Circulo: " << c << ", Area: " << c.area() << endl;

    Cilindro cl(1, 2, 3, 4);
    cout << "Cilindro: " << cl << ", Volume: " << cl.volume() << endl;

    return 0;
}