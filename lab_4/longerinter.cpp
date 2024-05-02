#include "longerinter.h"

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
    cout << "Entre com o numero.\n";
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
        LongInteger soma;
        int result = 0;
        int next = 0;
        int maxd = max(numDigits, other.numDigits);

        for (int i = 0; i < maxd || next; i++)
        {
            result = (digits[i] + other.digits[i] + next);
            soma.digits[i] = result % 10;
            next = result / 10;
            soma.numDigits++;
        }

        if ((sign < 0) && (other.sign < 0))
            soma.sign = -1;

        return soma;
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
        LongInteger fake_other = other;
        fake.sign = 1;
        fake_other.sign = 1;
        return fake_other - fake;
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
            LongInteger sub;
            int result = 0;
            int empresta = 0;

            for (int i = 0; i < numDigits; i++)
            {
                result = digits[i] - other.digits[i] - empresta;
                if (result < 0)
                {
                    result = 10 + digits[i] - other.digits[i] - empresta;
                    empresta = 1;
                }
                else
                    empresta = 0;
                sub.digits[i] = result;
                sub.numDigits++;
            }
            return sub;
        }
        else if (compare == -1)
        {
            LongInteger sub = other - *this;
            sub.sign = -1;
            return sub;
        }
        else
        {
            LongInteger sub("0");
            return sub;
        }
    }
}

std::ostream &operator<<(std::ostream &out, const LongInteger &num)
{
    if (num.sign == -1)
        out << "-";

    for (int i = num.numDigits - 1; i >= 0; i--)
    {
        out << num.digits[i];
    }
    return out;
}

// Função para leitura
std::istream &operator>>(std::istream &in, LongInteger &num)
{
    string input;
    in >> input;
    num = LongInteger(input);
    return in;
}