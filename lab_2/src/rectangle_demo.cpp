#include <iostream>
#include "../include/Rectangle.h"

using namespace std;

int main()
{
    cout << "Rectangle Demo - Questions 5 & 6\n\n";    

    Rectangle* rectangles[5];
    int length, width;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the values for length and width of rectangle " << i + 1 << "\n";
        cin >> length >> width;
        rectangles[i] = new Rectangle(length, width);
    }

    for (int i = 0; i < 5; i++)
    {
        rectangles[i]->printRectangle();
    }

    for (int i = 0; i < 5; i++)
    {
        delete rectangles[i];
    }

    return 0;
}