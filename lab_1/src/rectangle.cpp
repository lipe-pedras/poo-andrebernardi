#include "rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle(int l, int w) : length(l), width(w)
{
    cout << "Creating rectangle object...\n"; // Question 1
    setLength(l);
    setWidth(w);
    cout << "Object created successfully!\n\n"; // Question 1
}

Rectangle::~Rectangle()
{
    cout << "Object destroyed.\n"; // Question 1
}

void Rectangle::setLength(int l) // Question 2
{
    if (l <= 0 || l > 20)
    {
        length = 1;
        cerr << "Invalid value for length. Enter a value from 1 to 20.\n";
    }
    else
    {
        length = l;
    }
}

void Rectangle::setWidth(int w) // Question 2
{
    if (w <= 0 || w > 20)
    {
        width = 1;
        cerr << "Invalid value for width. Enter a value from 1 to 20.\n";
    }
    else
    {
        width = w;
    }
}

int Rectangle::getLength() const
{
    return length;
}

int Rectangle::getWidth() const
{
    return width;
}

double Rectangle::getArea() const
{
    return length * width;
}

double Rectangle::getPerimeter() const
{
    return (length + width) * 2;
}

void Rectangle::printRectangle() const
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cout << '*';
        }
        cout << "\n";
    }
    cout << "\n\n";
}

bool Rectangle::isSquare() const
{
    return (length == width);
}