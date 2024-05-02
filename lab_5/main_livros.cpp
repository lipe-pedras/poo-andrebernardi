#include "livros.h"

int main()
{
    Livro l1;
    cout << l1 << "\nISBN: " << l1.getISBN() << endl;
    Livro l2("A Biblioteca da Meia-Noite", "Matt Haig", "9786558380542");
    l2.imprimirDetalhes();
}