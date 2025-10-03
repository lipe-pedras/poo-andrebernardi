#include "LongInteger.h"

using namespace std;

LongInteger::LongInteger()
{
    memset(digits, 0, sizeof(digits));
    numDigits = 0;
    sign = 1;
}

LongInteger::LongInteger(const string &number)
{
    this->numDigits = 0;
    memset(digits, 0, sizeof(digits));
    int len = number.length();
    int end = len;

    // handling the negative numbers
    if (number[0] == '-')
    {
        end--;
        sign = -1;
    }
    else
    {
        sign = 1;
    }

    for (int j = 0; j < end; j++)
    {
        digits[j] = number[len - 1 - j] - '0';
        numDigits++;
    }
}

LongInteger::~LongInteger()
{
}

void LongInteger::readFromKeyboard()
{
    string input;
    cout << "Enter the number.\n";
    cin >> input;

    *this = LongInteger(input);
}

void LongInteger::print() const
{
    if (sign < 0)
    {
        cout << "-";
    }
    for (int i = numDigits - 1; i >= 0; i--)
    {
        cout << digits[i];
    }
}

int LongInteger::operator>(const LongInteger &other) const
{
    if (this->sign > other.sign)
        return 1;
    else if (this->sign < other.sign)
        return 0;
    else if (numDigits > other.numDigits)
        return 1;
    else if (numDigits < other.numDigits)
        return 0;
    else
    {
        for (int i = numDigits - 1; i >= 0; i--)
        {
            if (digits[i] > other.digits[i])
                return 1;
            else if (digits[i] < other.digits[i])
                return 0;
        }
        return 0;
    }
}

int LongInteger::operator<(const LongInteger &other) const
{
    return (other > *this);
}

int LongInteger::operator<=(const LongInteger &other) const
{
    return ((*this < other) || ((!(*this > other)) && (!(other > *this))));
}

int LongInteger::operator>=(const LongInteger &other) const
{
    return ((*this > other) || ((!(*this < other) || (other < *this))));
}

int LongInteger::operator==(const LongInteger &other) const
{
    return (!((*this < other) || (other < *this)));
}

int LongInteger::operator!=(const LongInteger &other) const
{
    return (!(*this == other));
}

LongInteger LongInteger::operator+(const LongInteger &other) const
{
    if (((sign > 0) && (other.sign > 0)) || ((sign < 0) && (other.sign < 0)))
    {
        LongInteger sum;
        int result = 0;
        int carry = 0;
        int maxDigits = max(numDigits, other.numDigits);

        for (int i = 0; i < maxDigits || carry; i++)
        {
            result = (digits[i] + other.digits[i] + carry);
            sum.digits[i] = result % 10;
            carry = result / 10;
            sum.numDigits++;
        }

        if ((sign < 0) && (other.sign < 0))
            sum.sign = -1;

        return sum;
    }
    else if ((sign > 0) && (other.sign < 0))
    {
        LongInteger fake = other;
        fake.sign = 1;
        return *this - fake;
    }
    else
    {
        return other - *this;
    }
}

LongInteger LongInteger::operator-(const LongInteger &other) const
{
    if (sign == 1 && other.sign == -1)
    {
        LongInteger fake = other;
        fake.sign = 1;
        return *this + fake;
    }
    if (sign == -1 && other.sign == 1)
    {
        LongInteger fake = *this;
        fake.sign = 1;
        fake = fake + other;
        fake.sign = -1;
        return fake;
    }
    if (sign == -1 && other.sign == -1)
    {
        LongInteger fake = *this;
        LongInteger fakeOther = other;
        fake.sign = 1;
        fakeOther.sign = 1;
        return fakeOther - fake;
    }
    else
    {
        int compare;
        if (*this > other)
            compare = 1;
        if (*this < other)
            compare = -1;
        if (*this == other)
            compare = 0;
        if (compare == 1)
        {
            LongInteger subtraction;
            int result = 0;
            int borrow = 0;

            for (int i = 0; i < numDigits; i++)
            {
                result = digits[i] - other.digits[i] - borrow;
                if (result < 0)
                {
                    result = 10 + digits[i] - other.digits[i] - borrow;
                    borrow = 1;
                }
                else
                    borrow = 0;
                subtraction.digits[i] = result;
                subtraction.numDigits++;
            }
            return subtraction;
        }
        else if (compare == -1)
        {
            LongInteger subtraction = other - *this;
            subtraction.sign = -1;
            return subtraction;
        }
        else
        {
            LongInteger subtraction("0");
            return subtraction;
        }
    }
}

std::ostream &operator<<(std::ostream &out, const LongInteger &number)
{
    if (number.sign == -1)
        out << "-";

    for (int i = number.numDigits - 1; i >= 0; i--)
    {
        out << number.digits[i];
    }
    return out;
}

// Function for reading
std::istream &operator>>(std::istream &in, LongInteger &number)
{
    string input;
    in >> input;
    number = LongInteger(input);
    return in;
}