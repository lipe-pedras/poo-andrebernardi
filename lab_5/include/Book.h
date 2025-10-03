#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

using namespace std;

class Book
{
public:
    Book();
    Book(const string &title, const string &author, const string &isbn);

    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;

    friend istream &operator>>(istream &in, Book &book);
    friend ostream &operator<<(ostream &out, const Book &book);

    void printDetails() const;

private:
    string title;
    string author;
    string isbn;
};

#endif // BOOK_H