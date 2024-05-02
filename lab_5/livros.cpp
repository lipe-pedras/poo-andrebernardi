#include "livros.h"

using namespace std;

Livro::Livro()
{
    cin >> *this;
}

Livro::Livro(const std::string &titulo, const std::string &autor, const std::string &isbn)
    : titulo(titulo), autor(autor), isbn(isbn) {}

string Livro::getTitulo() const
{
    return titulo;
}

string Livro::getISBN() const
{
    return isbn;
}

string Livro::getAutor() const
{
    return autor;
}

void Livro::imprimirDetalhes() const
{
    cout << titulo << endl << autor << endl << isbn << endl;
}

istream &operator>>(istream &in, Livro &book)
{
    cout << "Digite o titulo do livro.\n";
    getline(in, book.titulo);
    cout << "Digite o nome do autor.\n";
    getline(in, book.autor);
    cout << "Digite o codigo IBSN do livro.\n";
    getline(in, book.isbn);
    return in;
}

ostream &operator<<(ostream &out, const Livro &book)
{
    out << book.titulo << " - " << book.autor;
    return out;
}