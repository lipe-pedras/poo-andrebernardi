/**
 * @file main_polynomial.cpp
 * @brief Demonstration program for the Polynomial class
 * 
 * This program demonstrates the Polynomial class functionality including
 * derivative calculation, evaluation at specific points, and root finding
 * using Newton's method.
 */

#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    cout << "=== Polynomial Operations Demo ===" << endl;
    
    // Create and input polynomial
    Polynomial p;
    cout << "\nEnter polynomial details:" << endl;
    cin >> p;

    cout << "\nPolynomial entered: " << p << endl;

    // Calculate and display the derivative
    Polynomial derivative = p.derivative();
    cout << "\nDerivative of the polynomial: " << derivative << endl;

    // Calculate and display the polynomial value at a specific point
    double x;
    cout << "\nEnter a value to evaluate the polynomial at: ";
    cin >> x;
    double value = p.evaluate(x);
    cout << "Value of the polynomial at x = " << x << " is: " << value << endl;

    // Find a root using Newton's method
    double x0;
    int maxIter;
    double epsilon;
    cout << "\n=== Newton's Method Root Finding ===" << endl;
    cout << "Enter initial guess for Newton's method: ";
    cin >> x0;
    cout << "Enter maximum number of iterations: ";
    cin >> maxIter;
    cout << "Enter epsilon (tolerance): ";
    cin >> epsilon;

    double root = p.newtonMethod(x0, maxIter, epsilon);
    cout << "Root found using Newton's method: " << root << endl;
    
    // Verify the root
    double verification = p.evaluate(root);
    cout << "Verification - f(" << root << ") = " << verification << endl;

    return 0;
}