/**
 * @file PhoneNumber.cpp
 * @brief Implementation of the PhoneNumber class
 */

#include "PhoneNumber.h"
#include <iomanip> 
#include <stdexcept>

using namespace std; 

/**
 * @brief Constructor with area code and number
 * @param area The 2-digit area code
 * @param num The 8 or 9-digit phone number
 */
PhoneNumber::PhoneNumber(const string &area, const string &num) 
    : areaCode(area), number(num) 
{
    if (!isValidAreaCode(area) || !isValidNumber(num)) {
        throw invalid_argument("Invalid phone number format");
    }
}

/**
 * @brief Validate area code format
 * @param area The area code to validate
 * @return true if valid, false otherwise
 */
bool PhoneNumber::isValidAreaCode(const string &area) const 
{
    return area.length() == 2 && 
           area.find_first_not_of("0123456789") == string::npos;
}

/**
 * @brief Validate phone number format
 * @param num The phone number to validate
 * @return true if valid, false otherwise
 */
bool PhoneNumber::isValidNumber(const string &num) const 
{
    return (num.length() == 8 || num.length() == 9) && 
           num.find_first_not_of("0123456789") == string::npos;
}

/**
 * @brief Get formatted phone number string
 * @return Formatted phone number as string
 */
string PhoneNumber::getFormattedNumber() const 
{
    size_t len = number.size();
    
    if (len == 8) {
        // Format XXXX-XXXX for 8-digit numbers
        return "(" + areaCode + ") " + number.substr(0, 4) + "-" + number.substr(4, 4);
    } else if (len == 9) {
        // Format XXXXX-XXXX for 9-digit numbers  
        return "(" + areaCode + ") " + number.substr(0, 5) + "-" + number.substr(5, 4);
    } else {
        // Handle unexpected lengths
        return "(" + areaCode + ") " + number;
    }
}

/**
 * @brief Output stream operator
 * @param output The output stream
 * @param phone The phone number to output
 * @return Reference to the output stream
 */
ostream &operator<<( ostream &output, const PhoneNumber &phone ) 
{ 
    output << phone.getFormattedNumber();
    return output; 
} 

/**
 * @brief Input stream operator with validation
 * @param input The input stream
 * @param phone The phone number to input to
 * @return Reference to the input stream
 */
istream &operator>>( istream &input, PhoneNumber &phone ) 
{ 
    cout << "Enter phone number in format (XX) XXXXXXXX or (XX) XXXXXXXXX:" << endl;
    
    input.ignore(); // skip any remaining newline
    input >> setw(2) >> phone.areaCode; // input area code 
    input.ignore(2); // skip ) and space 
    input >> setw(9) >> phone.number; // input number (up to 9 digits) 
    
    // Validate input
    if (!phone.isValidAreaCode(phone.areaCode)) {
        cout << "Warning: Invalid area code format!" << endl;
    }
    if (!phone.isValidNumber(phone.number)) {
        cout << "Warning: Invalid phone number format!" << endl;
    }
    
    return input; 
}