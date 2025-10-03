#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
    Rectangle(int l = 1, int w = 1);
    ~Rectangle();

    void setLength(int l);
    void setWidth(int w);
    int getLength() const;
    int getWidth() const;
    double getArea() const;
    double getPerimeter() const;
    void printRectangle() const;
    bool isSquare() const;

private:
    int length;
    int width;
};

#endif