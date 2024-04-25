#include "longerinter.h"
using namespace std;

int main()
{
    LongInteger num1, num2;

    cout << "Digite o primeiro numero.\n";
    cin >> num1;

    cout << "Digite o segundo numero.\n";
    cin >> num2;

    cout << endl
         << endl
         << "num1 = " << num1 << endl
         << "num2 = " << num2 << endl
         << "Soma: " << num1 + num2 << endl
         << "Sub: " << num1 - num2 << endl
         << "Maior: " << ((num1 > num2) ? num1 : num2) << endl
         << "Menor: " << ((num1 < num2) ? num1 : num2) << endl
         << "num1 >= num2 " << (num1 >= num2) << endl
         << "num1 <= num2 " << (num1 <= num2) << endl
         << "num1 != num2 " << (num1 != num2) << endl
         << ((num1 == num2) ? "sao iguais" : "sao diferentes") << endl;
}