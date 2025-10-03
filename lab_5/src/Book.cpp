#include "Book.h"

using namespace std;

Book::Book()
{
    cin >> *this;
}

Book::Book(const std::string &title, const std::string &author, const std::string &isbn)
    : title(title), author(author), isbn(isbn) {}

string Book::getTitle() const
{
    return title;
}

string Book::getISBN() const
{
    return isbn;
}

string Book::getAuthor() const
{
    return author;
}

void Book::printDetails() const
{
    cout << title << endl << author << endl << isbn << endl;
}

istream &operator>>(istream &in, Book &book)
{
    cout << "Enter the book title:\n";
    getline(in, book.title);
    cout << "Enter the author's name:\n";
    getline(in, book.author);
    cout << "Enter the book's ISBN code:\n";
    getline(in, book.isbn);
    return in;
}

ostream &operator<<(ostream &out, const Book &book)
{
    out << book.title << " - " << book.author;
    return out;
}