#include "Book.h"

int main()
{
    Book book1;
    cout << book1 << "\nISBN: " << book1.getISBN() << endl;
    Book book2("The Midnight Library", "Matt Haig", "9786558380542");
    book2.printDetails();
    return 0;
}