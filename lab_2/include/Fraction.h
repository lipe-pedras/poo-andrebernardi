// Fraction.h - Interface for the Fraction class
#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
    // Reduces the fraction to its simplest form
    Fraction Reduced(void);

public:
    // Default constructor
    Fraction(void)
    {
        m_numerator = 1;
        m_denominator = 1;
    }
    
    // Parameterized constructor
    Fraction(int numerator, int denominator) : m_numerator(numerator),
                                               m_denominator(denominator) {};
    
    // Copy constructor
    Fraction(const Fraction &f)
    {
        m_numerator = f.m_numerator;
        m_denominator = f.m_denominator;
    }
    
    // Destructor
    ~Fraction(void) {};
    
    // Access methods
    int getNumerator(void) { return m_numerator; }
    int getDenominator(void) { return m_denominator; }
    
    // Arithmetic methods
    // Returns a new fraction that is the sum of the receiver with other
    Fraction Add(Fraction other);
    // Returns a new fraction that is the subtraction of the receiver with other
    Fraction Subtract(Fraction other);
    // Returns a new fraction that is the product of the receiver and other
    Fraction Multiply(Fraction other);
    // Returns a new fraction that is the quotient of the receiver and other
    Fraction Divide(Fraction other);
    
    // Comparison methods
    // Returns true if receiver is less than other
    int LessThan(Fraction other);
    // Returns true if receiver is greater than other
    int GreaterThan(Fraction other);
    // Returns true if receiver is equal to other
    int Equal(Fraction other);
    
    // Conversion methods
    // Returns the fraction value as float
    float AsFloat(void);
    
    // Print methods
    // Show the receiver in format "numerator/denominator"
    void Print(void);
};

#endif // FRACTION_H