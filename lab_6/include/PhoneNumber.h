#ifndef PHONE_NUMBER_H 
#define PHONE_NUMBER_H 
#include <iostream> 
#include <string> 
using namespace std; 

/**
 * @brief PhoneNumber class for Brazilian phone number validation and formatting
 * 
 * This class handles Brazilian phone numbers with 2-digit area codes
 * and 8 or 9-digit numbers. It provides input validation and formatted output.
 * 
 * Supported formats:
 * - (XX) XXXX-XXXX (8-digit numbers)
 * - (XX) XXXXX-XXXX (9-digit numbers)
 */
class PhoneNumber 
{ 
    friend ostream &operator<<(ostream &output, const PhoneNumber &phone); 
    friend istream &operator>>(istream &input, PhoneNumber &phone); 

private: 
    string areaCode; // 2-digit area code (e.g., "11" for São Paulo)
    string number;   // 8 or 9-digit phone number
    
public:
    // Constructors
    PhoneNumber() = default;
    PhoneNumber(const string &area, const string &num);
    
    // Validation methods
    bool isValidAreaCode(const string &area) const;
    bool isValidNumber(const string &num) const;
    
    // Accessor methods
    string getAreaCode() const { return areaCode; }
    string getNumber() const { return number; }
    string getFormattedNumber() const;
}; // end class PhoneNumber 

#endif