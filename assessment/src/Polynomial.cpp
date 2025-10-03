#include "Polynomial.h"
#include <algorithm>
#include <cmath>

// Default constructor
Polynomial::Polynomial() {
    coefficients.push_back(0.0);  // Polynomial 0
}

// Constructor with degree
Polynomial::Polynomial(int degree) {
    if (degree < 0) degree = 0;
    coefficients.resize(degree + 1, 0.0);
}

// Copy constructor
Polynomial::Polynomial(const Polynomial &other) : coefficients(other.coefficients) {
}

// Destructor
Polynomial::~Polynomial() {
}

// Assignment operator
Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        coefficients = other.coefficients;
    }
    return *this;
}

// Addition operator
Polynomial Polynomial::operator+(const Polynomial &other) const {
    size_t max_size = std::max(coefficients.size(), other.coefficients.size());
    Polynomial result;
    result.coefficients.resize(max_size, 0.0);
    
    for (size_t i = 0; i < max_size; ++i) {
        double a = (i < coefficients.size()) ? coefficients[i] : 0.0;
        double b = (i < other.coefficients.size()) ? other.coefficients[i] : 0.0;
        result.coefficients[i] = a + b;
    }
    
    return result;
}

// Subtraction operator
Polynomial Polynomial::operator-(const Polynomial &other) const {
    size_t max_size = std::max(coefficients.size(), other.coefficients.size());
    Polynomial result;
    result.coefficients.resize(max_size, 0.0);
    
    for (size_t i = 0; i < max_size; ++i) {
        double a = (i < coefficients.size()) ? coefficients[i] : 0.0;
        double b = (i < other.coefficients.size()) ? other.coefficients[i] : 0.0;
        result.coefficients[i] = a - b;
    }
    
    return result;
}

// Multiplication operator
Polynomial Polynomial::operator*(const Polynomial &other) const {
    if (coefficients.empty() || other.coefficients.empty()) {
        return Polynomial();
    }
    
    size_t result_size = coefficients.size() + other.coefficients.size() - 1;
    Polynomial result;
    result.coefficients.resize(result_size, 0.0);
    
    for (size_t i = 0; i < coefficients.size(); ++i) {
        for (size_t j = 0; j < other.coefficients.size(); ++j) {
            result.coefficients[i + j] += coefficients[i] * other.coefficients[j];
        }
    }
    
    return result;
}

// Compound assignment operators
Polynomial& Polynomial::operator+=(const Polynomial &other) {
    *this = *this + other;
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial &other) {
    *this = *this - other;
    return *this;
}

// Comparison operators
bool Polynomial::operator==(const Polynomial &other) const {
    if (coefficients.size() != other.coefficients.size()) {
        return false;
    }
    
    for (size_t i = 0; i < coefficients.size(); ++i) {
        if (std::abs(coefficients[i] - other.coefficients[i]) > 1e-9) {
            return false;
        }
    }
    
    return true;
}

bool Polynomial::operator!=(const Polynomial &other) const {
    return !(*this == other);
}

// Access operators
double& Polynomial::operator[](int index) {
    if (index < 0) index = 0;
    if (index >= static_cast<int>(coefficients.size())) {
        coefficients.resize(index + 1, 0.0);
    }
    return coefficients[index];
}

const double& Polynomial::operator[](int index) const {
    static double zero = 0.0;
    if (index < 0 || index >= static_cast<int>(coefficients.size())) {
        return zero;
    }
    return coefficients[index];
}

// Utility methods
int Polynomial::getDegree() const {
    return static_cast<int>(coefficients.size()) - 1;
}

double Polynomial::evaluate(double x) const {
    if (coefficients.empty()) return 0.0;
    
    double result = coefficients.back();
    for (int i = coefficients.size() - 2; i >= 0; --i) {
        result = result * x + coefficients[i];
    }
    
    return result;
}

void Polynomial::setCoefficient(int power, double value) {
    if (power < 0) return;
    if (power >= static_cast<int>(coefficients.size())) {
        coefficients.resize(power + 1, 0.0);
    }
    coefficients[power] = value;
}

double Polynomial::getCoefficient(int power) const {
    if (power < 0 || power >= static_cast<int>(coefficients.size())) {
        return 0.0;
    }
    return coefficients[power];
}

// Stream operators
std::ostream& operator<<(std::ostream &out, const Polynomial &poly) {
    bool first = true;
    bool has_terms = false;
    
    for (int i = poly.coefficients.size() - 1; i >= 0; --i) {
        double coeff = poly.coefficients[i];
        if (std::abs(coeff) < 1e-9) continue;
        
        has_terms = true;
        if (!first && coeff > 0) out << " + ";
        if (!first && coeff < 0) out << " - ";
        if (first && coeff < 0) out << "-";
        
        double abs_coeff = std::abs(coeff);
        
        if (i == 0) {
            out << abs_coeff;
        } else if (i == 1) {
            if (abs_coeff == 1.0) {
                out << "x";
            } else {
                out << abs_coeff << "x";
            }
        } else {
            if (abs_coeff == 1.0) {
                out << "x^" << i;
            } else {
                out << abs_coeff << "x^" << i;
            }
        }
        
        first = false;
    }
    
    if (!has_terms) {
        out << "0";
    }
    
    return out;
}

std::istream& operator>>(std::istream &in, Polynomial &poly) {
    int degree;
    std::cout << "Enter polynomial degree: ";
    in >> degree;
    
    poly = Polynomial(degree);
    
    std::cout << "Enter coefficients from highest to lowest degree:\n";
    for (int i = degree; i >= 0; --i) {
        std::cout << "Coefficient of x^" << i << ": ";
        in >> poly.coefficients[i];
    }
    
    return in;
}