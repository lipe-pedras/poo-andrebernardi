#include "LongInteger.h"
using namespace std;

int main()
{
    LongInteger num1, num2;

    cout << "Enter the first number.\n";
    cin >> num1;

    cout << "Enter the second number.\n";
    cin >> num2;

    cout << endl
         << endl
         << "num1 = " << num1 << endl
         << "num2 = " << num2 << endl
         << "Sum: " << num1 + num2 << endl
         << "Subtraction: " << num1 - num2 << endl
         << "Greater: " << ((num1 > num2) ? num1 : num2) << endl
         << "Lesser: " << ((num1 < num2) ? num1 : num2) << endl
         << "num1 >= num2 " << (num1 >= num2) << endl
         << "num1 <= num2 " << (num1 <= num2) << endl
         << "num1 != num2 " << (num1 != num2) << endl
         << ((num1 == num2) ? "are equal" : "are different") << endl;

    return 0;
}