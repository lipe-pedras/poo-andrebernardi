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
