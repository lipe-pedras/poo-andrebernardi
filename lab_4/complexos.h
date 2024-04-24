// complexos.h
#ifndef COMPLEXOS_H
#define COMPLEXOS_H

#include <vector>
#include <string>
#include <iostream>

class Complexo {
private:
    double r; // Real part
    double c; // Complex part
    static unsigned int count; // Static member to count instances

public:
    Complexo();
    Complexo(double r, double c);
    ~Complexo();

    std::vector<double> polar() const; // No need to pass Complexo here
    static Complexo retangular(const std::vector<double>& vetor); // Static method

    double getReal() const { return r; }
    double getComplex() const { return c; }

    Complexo operator+(const Complexo& _c2) const;
    Complexo operator-(const Complexo& _c2) const;
    Complexo operator*(const Complexo& _c2) const;
    Complexo operator/(const Complexo& _c2) const;
    friend std::ostream &operator<<(std::ostream &out, const Complexo &c2);
    friend std::istream &operator>>(std::istream &in, Complexo &c2);



    double modulo() const;
    std::string printRetangular() const;

    static int printNumberOfComplexes();
};

#endif
