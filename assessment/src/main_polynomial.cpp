#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    cout << "=== Polynomial Demonstration ===" << endl;
    
    // Create some polynomials
    Polynomial p1(2);  // degree 2 polynomial
    p1[0] = 1;  // constant term
    p1[1] = -3; // x term
    p1[2] = 2;  // x^2 term
    // p1 = 1 - 3x + 2x^2
    
    Polynomial p2(1);  // degree 1 polynomial
    p2[0] = 4;  // constant term
    p2[1] = 1;  // x term
    // p2 = 4 + x
    
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    
    // Test evaluation
    cout << "\nEvaluation:" << endl;
    double x = 2.0;
    cout << "p1(" << x << ") = " << p1.evaluate(x) << endl;
    cout << "p2(" << x << ") = " << p2.evaluate(x) << endl;
    
    // Test arithmetic
    cout << "\nArithmetic operations:" << endl;
    Polynomial sum = p1 + p2;
    cout << "p1 + p2 = " << sum << endl;
    
    Polynomial diff = p1 - p2;
    cout << "p1 - p2 = " << diff << endl;
    
    Polynomial product = p1 * p2;
    cout << "p1 * p2 = " << product << endl;
    
    // Test degree
    cout << "\nDegrees:" << endl;
    cout << "Degree of p1: " << p1.getDegree() << endl;
    cout << "Degree of p2: " << p2.getDegree() << endl;
    cout << "Degree of product: " << product.getDegree() << endl;
    
    // Test coefficient access
    cout << "\nCoefficient access:" << endl;
    cout << "Coefficient of x^2 in p1: " << p1.getCoefficient(2) << endl;
    cout << "Coefficient of x^1 in p2: " << p2.getCoefficient(1) << endl;
    
    // User input polynomial
    cout << "\nCreate your own polynomial:" << endl;
    Polynomial user_poly;
    cin >> user_poly;
    cout << "Your polynomial: " << user_poly << endl;
    
    cout << "Enter x value to evaluate: ";
    double eval_x;
    cin >> eval_x;
    cout << "f(" << eval_x << ") = " << user_poly.evaluate(eval_x) << endl;
    
    return 0;
}