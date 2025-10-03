#include "Date.h"

Date::Date()
{
    setDate(1, 1, 1);
}

Date::Date(int d, int m, int y)
{
    setDate(d, m, y);
}

void Date::setDate(int d, int m, int y)
{
    if (d > days_per_month[m])
    {
        d = 1;
        m++;
    }
    else if (d < 1)
    {
        m--;
        d = days_per_month[m];
    }
    if (m < 1)
    {
        m = 12;
        y--;
    }
    else if (m > 12)
    {
        m = 1;
        y++;
    }
    if (y <= 0)
        y = 1;

    leap_year = ((year % d) == 0);

    day = d;
    month = m;
    year = y;
}

Date &Date::operator++()
{
    setDate(day + 1, month, year);
    return *this;
}

Date Date::operator++(int)
{
    Date temp{*this};
    setDate(day + 1, month, year);
    return temp;
}

Date &Date::operator--()
{
    setDate(day - 1, month, year);
    return *this;
}

Date Date::operator--(int)
{
    Date temp{*this};
    setDate(day - 1, month, year);
    return temp;
}

istream &operator>>(istream &in, Date &d)
{
    cout << "Enter the day:\n";
    in >> d.day;
    cout << "Enter the month:\n";
    in >> d.month;
    cout << "Enter the year:\n";
    in >> d.year;
    d.setDate(d.day, d.month, d.year);
    return in;
}

ostream &operator<<(ostream &out, const Date &d)
{
    static const string month_names[13] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    out << d.day << " of " << month_names[d.month] << " of " << d.year;
    return out;
}