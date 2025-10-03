#include "../include/classes.h"
#include <iostream>
#include <vector>
using namespace std;
int menu();
int main()
{
    vector<Point*> shapes;
    while (true)
    {
        switch (menu())
        {
        case 1:
            shapes.push_back(new Point);
            break;
        case 2:
            shapes.push_back(new Circle);
            break;
        case 3:
            shapes.push_back(new Cylinder);
            break;
        case 0:
            cout << "\nPrinting all created objects:\n";
            for (auto* p : shapes)
            {
                p->print();
                cout << endl;
            }
            for (auto* p : shapes)
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
    cout << "\nChoose the type of object to be created:" << endl;
    cout << "1 - Point" << endl;
    cout << "2 - Circle" << endl;
    cout << "3 - Cylinder" << endl;
    cout << "0 - Exit and print created objects" << endl;
    cout << "Option: ";
    cin >> option;
    return option;
}
