#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
    Rectangle(int length = 1, int width = 1);
    ~Rectangle();

    void setLength(int length);
    void setWidth(int width);
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

#endif // RECTANGLE_H