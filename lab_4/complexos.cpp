// complexos.cpp
#include "complexos.h"
#include <iostream>
#include <cmath>
#include <sstream>

unsigned int Complexo::count = 0;

Complexo::Complexo() {
    count++;
    r = 1;
    c = 1;
}

Complexo::Complexo(double real, double imag) : r(real), c(imag) {
    count++;
}

Complexo::~Complexo() {
    count--;
}

std::vector<double> Complexo::polar() const {
    std::vector<double> polarr;
    polarr.push_back(sqrt(r * r + c * c));
    if (r != 0) {
        if (r >= 0) {
            polarr.push_back(atan(c / r) * (180 / M_PI));
        } else {
            polarr.push_back((atan(c / r) * (180 / M_PI) + 180));
        }
    } else {
        std::cerr << "Erro: divisao por zero.\n\n";
    }
    return polarr;
}

Complexo Complexo::retangular(const std::vector<double>& vetor) {
    double realPart = cos(vetor[1]) * vetor[0];
    double imagPart = sin(vetor[1]) * vetor[0];
    return Complexo(realPart, imagPart);
}

Complexo Complexo::operator+(const Complexo& _c2) const {
    double realPart = r + _c2.r;
    double imagPart = c + _c2.c;
    return Complexo(realPart, imagPart);
}

Complexo Complexo::operator-(const Complexo& _c2) const {
    double realPart = r - _c2.r;
    double imagPart = c - _c2.c;
    return Complexo(realPart, imagPart);
}

Complexo Complexo::operator*(const Complexo& _c2) const {
    std::vector<double> c1_polar = polar();
    std::vector<double> c2_polar = _c2.polar();
    std::vector<double> c3;
    c3.push_back(c1_polar[0] * c2_polar[0]);
    c3.push_back(c1_polar[1] + c2_polar[1]);
    return retangular(c3);
}

Complexo Complexo::operator/(const Complexo& _c2) const {
    std::vector<double> c1_polar = polar();
    std::vector<double> c2_polar = _c2.polar();
    std::vector<double> c3;
    if (c2_polar[0] == 0) {
        std::cerr << "Erro: divisao por zero.\n\n";
    } else {
        c3.push_back(c1_polar[0] / c2_polar[0]);
        c3.push_back(c1_polar[1] - c2_polar[1]);
    }
    return retangular(c3);
}

double Complexo::modulo() const {
    return sqrt(r * r + c * c);
}

std::string Complexo::printRetangular() const {
    std::ostringstream oss;

    oss << r;

    if (c >= 0)
        oss << " + " << c << "i";
    else
        oss << " - " << -c << "i"; // Adjusted for negative complex part

    return oss.str();
}

int Complexo::printNumberOfComplexes() {
    return count;
}

std::ostream &operator<<(std::ostream &out, const Complexo &num)
{
    out << num.r << " " << num.c <<  "i";
    return out;
}

// Função para leitura
std::istream &operator>>(std::istream &in, Complexo &num)
{
    std::cout << "Entre com a parte real.\n";
    in >> num.r;
    std::cout << "Entre com a parte imaginaria.\n";
    in >> num.c;
    return in;
}
