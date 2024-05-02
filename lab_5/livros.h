#ifndef LIVRO_H
#define LIVRO_H

#include <string>
#include <iostream>

using namespace std;

class Livro
{
public:
    Livro();
    Livro(const string &titulo, const string &autor, const string &isbn);

    string getTitulo() const;
    string getAutor() const;
    string getISBN() const;

    friend istream &operator>>(istream &in, Livro &book);
    friend ostream &operator<<(ostream &out, const Livro &book);

    void imprimirDetalhes() const;

private:
    string titulo;
    string autor;
    string isbn;
};

#endif // LIVRO_H
