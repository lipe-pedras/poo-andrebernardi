#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Base class for politicians
class Politician {
public:
    Politician() {
        cout << "A politician was created.\n";
        fillData();
    }
    virtual ~Politician() {
        cout << "A politician was destroyed.\n";
    }

    virtual void print() const {
        cout << "Name: " << name << ", Party: " << party;
    }

    void fillData() {
        cout << "Enter the politician's name and party:\n";
        cin >> name >> party;
    }

    friend ostream& operator<<(ostream& os, const Politician& p) {
        os << "Name: " << p.name << ", Party: " << p.party;
        return os;
    }

    friend istream& operator>>(istream& is, Politician& p) {
        is >> p.name >> p.party;
        return is;
    }

    string name;
    string party;
};

// President class
class President : public Politician {
public:
    President() {
        cout << "A president was created.\n";
        fillData();
    }
    virtual ~President() {
        cout << "A president was destroyed.\n";
    }

    virtual void print() const override {
        Politician::print();
        cout << ", Country: " << country;
    }

    void fillData() {
        cout << "Enter the president's country:\n";
        cin >> country;
    }

    friend ostream& operator<<(ostream& os, const President& p) {
        os << static_cast<const Politician&>(p) << ", Country: " << p.country;
        return os;
    }

    friend istream& operator>>(istream& is, President& p) {
        is >> static_cast<Politician&>(p) >> p.country;
        return is;
    }

    string country;
};

// Governor class
class Governor : public President {
public:
    Governor() {
        cout << "A governor was created.\n";
        fillData();
    }
    virtual ~Governor() {
        cout << "A governor was destroyed.\n";
    }

    virtual void print() const override {
        President::print();
        cout << ", State: " << state;
    }

    void fillData() {
        cout << "Enter the governor's state:\n";
        cin >> state;
    }

    friend ostream& operator<<(ostream& os, const Governor& g) {
        os << static_cast<const President&>(g) << ", State: " << g.state;
        return os;
    }

    friend istream& operator>>(istream& is, Governor& g) {
        is >> static_cast<President&>(g) >> g.state;
        return is;
    }

    string state;
};

// Mayor class
class Mayor : public Governor {
public:
    Mayor() {
        cout << "A mayor was created.\n";
        fillData();
    }
    virtual ~Mayor() {
        cout << "A mayor was destroyed.\n";
    }

    virtual void print() const override {
        Governor::print();
        cout << ", City: " << city;
    }

    void fillData() {
        cout << "Enter the mayor's city:\n";
        cin >> city;
    }

    friend ostream& operator<<(ostream& os, const Mayor& m) {
        os << static_cast<const Governor&>(m) << ", City: " << m.city;
        return os;
    }

    friend istream& operator>>(istream& is, Mayor& m) {
        is >> static_cast<Governor&>(m) >> m.city;
        return is;
    }

    string city;
};

// Geometry classes
class Point {
public:
    double x, y;
    Point() {
        cin >> *this;
    }
    virtual ~Point() {}
    virtual void print() {
        cout << *this;
    }
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
    friend istream& operator>>(istream& is, Point& p) {
        cout << "Enter the X and Y values." << endl;
        is >> p.x >> p.y;
        return is;
    }
};

class Circle : public Point {
public:
    double radius;
    Circle() {
        cin >> *this;
    }
    virtual ~Circle() {}
    virtual void print() override {
        cout << *this;
    }
    virtual double area() const {
        return M_PI * radius * radius;
    }
    friend ostream& operator<<(ostream& os, const Circle& c) {
        os << "Center: " << static_cast<Point>(c) << ", Radius: " << c.radius;
        return os;
    }
    friend istream& operator>>(istream& is, Circle& c) {
        cout << "Enter the radius value." << endl;
        is >> c.radius;
        return is;
    }
};

class Cylinder : public Circle {
public:
    double height;
    Cylinder() {
        cin >> *this;
    }
    virtual ~Cylinder() {}
    virtual void print() override {
        cout << *this;
    }
    virtual double volume() const {
        return area() * height;
    }
    friend ostream& operator<<(ostream& os, const Cylinder& c) {
        os << "Base = { " << static_cast<Circle>(c) << " } | Height: " << c.height;
        return os;
    }
    friend istream& operator>>(istream& is, Cylinder& c) {
        cout << "Enter the height." << endl;
        is >> c.height;
        return is;
    }
};

#endif // CLASSES_H
