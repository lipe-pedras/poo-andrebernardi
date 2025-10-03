#include "../include/Rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle(int length, int width) : length(length), width(width)
{
    cout << "Creating rectangle object...\n";
    setLength(length);
    setWidth(width);
    cout << "Object created successfully!\n\n";
}

Rectangle::~Rectangle()
{
    cout << "Object destroyed.\n";
}

void Rectangle::setLength(int length)
{
    if (length <= 0 || length > 20)
    {
        this->length = 1;
        cerr << "Invalid value for length. Enter a value from 1 to 20.\n";
    }
    else
    {
        this->length = length;
    }
}

void Rectangle::setWidth(int width)
{
    if (width <= 0 || width > 20)
    {
        this->width = 1;
        cerr << "Invalid value for width. Enter a value from 1 to 20.\n";
    }
    else
    {
        this->width = width;
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