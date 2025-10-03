#include "../include/long_integer.h"

using namespace std;

LongInteger::LongInteger()
{
    memset(digits, 0, sizeof(digits));
    digitCount = 0;
    sign = 1;
}

LongInteger::LongInteger(const string &number)
{
    this->digitCount = 0;
    memset(digits, 0, sizeof(digits));
    int length = number.length();
    int end = length;

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
        digits[j] = number[length - 1 - j] - '0';
        digitCount++;
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
    for (int i = digitCount - 1; i >= 0; i--)
    {
        cout << digits[i];
    }
}

int LongInteger::compareMagnitude(const LongInteger &other) const
{
    if (digitCount > other.digitCount)
        return 1;
    else if (digitCount < other.digitCount)
        return -1;
    else
    {
        for (int i = digitCount - 1; i >= 0; i--)
        {
            if (digits[i] > other.digits[i])
                return 1;
            else if (digits[i] < other.digits[i])
                return -1;
        }
        return 0;
    }
}

LongInteger LongInteger::operator+(const LongInteger &other) const
{
    LongInteger sum;
    int result = 0;
    int carry = 0;
    int maxDigits = max(digitCount, other.digitCount);

    for (int i = 0; i < maxDigits || carry; i++)
    {
        result = (digits[i] * sign + other.digits[i] * other.sign + carry);
        sum.digits[i] = result % 10;
        carry = result / 10;
        sum.digitCount++;
    }

    return sum;
}

LongInteger LongInteger::operator-(const LongInteger &other) const
{
    if (sign == 1 && other.sign == -1)
    {
        LongInteger temp = other;
        temp.sign = 1;
        return *this + temp;
    }
    if (sign == -1 && other.sign == 1)
    {
        LongInteger temp = *this;
        temp.sign = 1;
        return temp + other;
    }
    if (sign == -1 && other.sign == -1)
    {
        LongInteger temp = *this;
        LongInteger tempOther = other;
        temp.sign = 1;
        tempOther.sign = 1;
        return tempOther - temp;
    }
    else
    {
        int comparison = compareMagnitude(other);
        if (comparison == 1)
        {
            LongInteger difference;
            int result = 0;
            int borrow = 0;

            for (int i = digitCount - 1; i >= 0; i--)
            {
                result = digits[i] - other.digits[i] - borrow;
                if (result < 0)
                {
                    result = 10 + digits[i] - other.digits[i] - borrow;
                    borrow = 1;
                }
                else
                    borrow = 0;
                difference.digits[i] = result;
                difference.digitCount++;
            }
            return difference;
        }
        else if (comparison == -1)
        {
            LongInteger difference = other - *this;
            difference.sign = -1;
            return difference;
        }
        else
        {
            LongInteger difference("0");
            return difference;
        }
    }
}