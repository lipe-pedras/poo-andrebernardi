#include <iomanip> 
#include "PhoneNumber.h" 
using namespace std; 

ostream &operator<<( ostream &output, const PhoneNumber &number ) 
{ 
    size_t len = number.number.size();
    
    if (len == 8) {
        // Format 4-4 for 8-digit numbers
        output << "(" << number.areaCode << ") " 
               << number.number.substr(0, 4) << "-" 
               << number.number.substr(4, 4); 
    } else if (len == 9) {
        // Format 5-4 for 9-digit numbers
        output << "(" << number.areaCode << ") " 
               << number.number.substr(0, 5) << "-" 
               << number.number.substr(5, 4); 
    } else {
        // Handle unexpected lengths (shouldn't happen with correct input)
        output << "(" << number.areaCode << ") " << number.number;
    }
    
    return output; 
} 

istream &operator>>( istream &input, PhoneNumber &number ) 
{ 
    input.ignore(); // skip ( 
    input >> setw(2) >> number.areaCode; // input area code 
    input.ignore(2); // skip ) and space 
    input >> setw(9) >> number.number; // input number (up to 9 digits) 
    return input; 
}
