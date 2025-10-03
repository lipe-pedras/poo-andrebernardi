#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

static const int days_per_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date
{
private:
    int day;
    int month;
    int year;
    bool leap_year;

public:
    Date();
    Date(int d, int m, int y);

    void setDate(int d, int m, int y);
    Date &operator++();
    Date operator++(int);

    Date &operator--();
    Date operator--(int);

    friend ostream &operator<<(ostream &out, const Date &d);
    friend istream &operator>>(istream &in, Date &d);
};
#endif