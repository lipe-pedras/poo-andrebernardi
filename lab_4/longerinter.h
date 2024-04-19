#ifndef LONGINTEGER_H
#define LONGINTEGER_H

#include <iostream>
#include <string>
#include <cstring>


class LongInteger {
protected:

private:
    static const int MAX_DIGITS = 30;
    int digits[MAX_DIGITS]; // Armazenamento dos dígitos do número
    int numDigits;          // Número de dígitos no número
    int sign;               // Sinal positivo ou negativo

public:
    LongInteger();                // Construtor padrão
    LongInteger(const std::string& number); // Construtor com string
    ~LongInteger();               // Destrutor

    void readFromKeyboard();      // Ler número do teclado
    void print() const;           // Imprimir número
    LongInteger operator+(const LongInteger& other) const;  // Somar dois números
    LongInteger operator-(const LongInteger& other) const; // Subtrair dois números
    int operator>(const LongInteger& other) const;
    int operator<(const LongInteger& other) const;
    int operator>=(const LongInteger& other) const;
    int operator<=(const LongInteger& other) const;
    int operator==(const LongInteger& other) const;
    int operator!=(const LongInteger& other) const;
    friend std::ostream &operator<<(std::ostream &out, const LongInteger &num);
    friend std::istream &operator>>(std::istream &in, LongInteger &num);

};

#endif
