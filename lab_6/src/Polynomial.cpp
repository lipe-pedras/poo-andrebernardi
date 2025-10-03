/**
 * @file Polynomial.cpp
 * @brief Implementation of the Polynomial class
 */

#include "Polynomial.h"
#include <cmath>
#include <cstring>

using namespace std;

/**
 * @brief Default constructor - creates zero polynomial
 */
Polynomial::Polynomial()
{
    degree = 0;
    coefficients = new double[1];
    coefficients[0] = 0;
}

/**
 * @brief Constructor with specified degree
 * @param deg The degree of the polynomial
 */
Polynomial::Polynomial(int deg) : degree(deg)
{
    coefficients = new double[degree + 1];
}

/**
 * @brief Copy constructor
 * @param other The polynomial to copy
 */
Polynomial::Polynomial(const Polynomial &other)
{
    degree = other.degree;
    coefficients = new double[degree + 1];
    memcpy(coefficients, other.coefficients, (degree + 1) * sizeof(double));
}

/**
 * @brief Destructor - frees dynamically allocated memory
 */
Polynomial::~Polynomial()
{
    delete[] coefficients;
}

/**
 * @brief Greater than operator
 * @param p The polynomial to compare with
 * @return 1 if this polynomial is greater, 0 otherwise
 */
int Polynomial::operator>(const Polynomial &p) const
{
    if (degree > p.degree)
        return 1;
    else if (p.degree > degree)
        return 0;
    else
    {
        int result = 0;
        for (int i = 0; i <= degree; i++)
        {
            if (coefficients[i] > p.coefficients[i])
            {
                result = 1;
                break;
            }
            if (p.coefficients[i] > coefficients[i])
            {
                result = 0;
                break;
            }
        }
        return result;
    }
}

/**
 * @brief Less than operator
 * @param p The polynomial to compare with
 * @return 1 if this polynomial is less than p, 0 otherwise
 */
int Polynomial::operator<(const Polynomial &p) const
{
    if (degree < p.degree)
        return 1;
    else if (p.degree < degree)
        return 0;
    else
    {
        int result = 0;
        for (int i = 0; i <= degree; i++)
        {
            if (coefficients[i] < p.coefficients[i])
            {
                result = 1;
                break;
            }
            if (p.coefficients[i] < coefficients[i])
            {
                result = 0;
                break;
            }
        }
        return result;
    }
}

/**
 * @brief Equality operator
 * @param p The polynomial to compare with
 * @return 1 if polynomials are equal, 0 otherwise
 */
int Polynomial::operator==(const Polynomial &p) const
{
    return (!((*this > p) || (*this < p)));
}

/**
 * @brief Less than or equal operator
 * @param p The polynomial to compare with
 * @return 1 if this polynomial is less than or equal to p, 0 otherwise
 */
int Polynomial::operator<=(const Polynomial &p) const
{
    return ((*this < p) || (*this == p));
}

/**
 * @brief Greater than or equal operator
 * @param p The polynomial to compare with
 * @return 1 if this polynomial is greater than or equal to p, 0 otherwise
 */
int Polynomial::operator>=(const Polynomial &p) const
{
    return ((*this > p) || (*this == p));
}

/**
 * @brief Not equal operator
 * @param p The polynomial to compare with
 * @return 1 if polynomials are not equal, 0 otherwise
 */
int Polynomial::operator!=(const Polynomial &p) const
{
    return (*this == p) ? 0 : 1;
}

/**
 * @brief Assignment operator
 * @param other The polynomial to assign from
 * @return Reference to this polynomial
 */
Polynomial Polynomial::operator=(const Polynomial &other)
{
    if (this != &other) // Avoid self-assignment
    {
        delete[] coefficients;
        degree = other.degree;
        coefficients = new double[degree + 1];
        memcpy(coefficients, other.coefficients, (degree + 1) * sizeof(double));
    }
    return *this;
}

/**
 * @brief Addition operator
 * @param other The polynomial to add
 * @return Sum of the two polynomials
 */
Polynomial Polynomial::operator+(const Polynomial &other) const
{
    Polynomial sum;
    int lesserDegree = min(degree, other.degree);
    if (lesserDegree == degree)
    {
        sum = Polynomial(other);
        for (int i = 0; i <= lesserDegree; i++)
        {
            sum.coefficients[i] += coefficients[i];
        }
    }
    else
    {
        sum = Polynomial(*this);
        for (int i = 0; i <= lesserDegree; i++)
        {
            sum.coefficients[i] += other.coefficients[i];
        }
    }
    return sum;
}

/**
 * @brief Subtraction operator
 * @param other The polynomial to subtract
 * @return Difference of the two polynomials
 */
Polynomial Polynomial::operator-(const Polynomial &other) const
{
    Polynomial sub;
    int lesserDegree = min(degree, other.degree);
    if (lesserDegree == degree)
    {
        sub = Polynomial(other);
        for (int i = 0; i <= other.degree; i++)
        {
            sub.coefficients[i] *= -1;
        }
        for (int i = 0; i <= lesserDegree; i++)
        {
            sub.coefficients[i] += coefficients[i];
        }
    }
    else
    {
        sub = Polynomial(*this);
        for (int i = 0; i <= lesserDegree; i++)
        {
            sub.coefficients[i] -= other.coefficients[i];
        }
    }
    return sub;
}

/**
 * @brief Index operator for accessing coefficients
 * @param index The index of the coefficient to access
 * @return The coefficient at the given index, or 0.0 if index is out of bounds
 */
double Polynomial::operator[](int index) const
{
    return (index > degree || index < 0) ? 0.0 : coefficients[index];
}

/**
 * @brief Output stream operator
 * @param out The output stream
 * @param p The polynomial to output
 * @return Reference to the output stream
 */
ostream &operator<<(ostream &out, const Polynomial &p)
{
    for (int x = 0; x <= p.degree; x++)
    {
        out << p.coefficients[x] << "x^" << x << " ";
    }
    return out;
}

/**
 * @brief Input stream operator
 * @param in The input stream
 * @param p The polynomial to input to
 * @return Reference to the input stream
 */
istream &operator>>(istream &in, Polynomial &p)
{
    int inputDegree;
    cout << "Enter degree: ";
    cin >> inputDegree;
    p.degree = inputDegree;
    delete[] p.coefficients; // Clean up existing memory
    p.coefficients = new double[inputDegree + 1];

    for (int i = 0; i <= inputDegree; i++)
    {
        cout << "Enter coefficient for x^" << i << ": ";
        in >> p.coefficients[i];
    }
    return in;
}

/**
 * @brief Calculate the derivative of the polynomial
 * @return A new polynomial representing the derivative
 */
Polynomial Polynomial::derivative() const
{
    if (degree == 0)
    {
        Polynomial deriv(0);
        deriv.coefficients[0] = 0;
        return deriv;
    }

    Polynomial deriv(degree - 1);
    for (int i = 1; i <= degree; i++)
    {
        deriv.coefficients[i - 1] = i * coefficients[i];
    }
    return deriv;
}

/**
 * @brief Evaluate the polynomial at a given point
 * @param x The point at which to evaluate the polynomial
 * @return The value of the polynomial at x
 */
double Polynomial::evaluate(double x) const
{
    double result = 0;
    for (int i = 0; i <= degree; i++)
    {
        result += coefficients[i] * pow(x, i);
    }
    return result;
}

/**
 * @brief Find a root using Newton's method
 * @param x0 Initial guess for the root
 * @param maxIterations Maximum number of iterations
 * @param epsilon Tolerance for convergence
 * @return Approximation of the root
 */
double Polynomial::newtonMethod(double x0, int maxIterations, double epsilon) const
{
    Polynomial derivativePolynomial = derivative();
    double x = x0;

    for (int i = 0; i < maxIterations; i++)
    {
        double p_x = evaluate(x);
        double p_prime_x = derivativePolynomial.evaluate(x);

        if (fabs(p_prime_x) < epsilon)
        {
            cout << "Derivative too close to zero. Newton's method may fail.\n";
            break;
        }

        double x_next = x - p_x / p_prime_x;

        if (fabs(x_next - x) < epsilon)
        {
            return x_next;
        }

        x = x_next;
    }

    cout << "Newton's method did not converge in " << maxIterations << " iterations.\n";
    return x;
}