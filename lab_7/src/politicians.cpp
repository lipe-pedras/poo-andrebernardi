#include "../include/classes.h"
#include <iostream>
#include <vector>
using namespace std;
int menu();
int main()
{
    vector<Politician*> politicians;
    while (true)
    {
        switch (menu())
        {
        case 1:
            politicians.push_back(new President);
            break;
        case 2:
            politicians.push_back(new Governor);
            break;
        case 3:
            politicians.push_back(new Mayor);
            break;
        case 0:
            cout << "\nPrinting all created politicians:\n";
            for (auto* p : politicians)
            {
                p->print();
                cout << endl;
            }
            for (auto* p : politicians)
            {
                delete p;
            }
            return 0;
        default:
            cout << "Invalid option! Try again.\n";
            break;
        }
    }
    return 0;
}
int menu()
{
    int option;
    cout << "\nChoose the type of politician to be created:" << endl;
    cout << "1 - President" << endl;
    cout << "2 - Governor" << endl;
    cout << "3 - Mayor" << endl;
    cout << "0 - Exit and print created politicians" << endl;
    cout << "Option: ";
    cin >> option;
    return option;
}
