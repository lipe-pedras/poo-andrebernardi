#include "longerinter.cpp"

using namespace std;

int main()
{
    LongInteger num1, num2;

    cout << "entre com o numero\n";
    cin >> num1;
    cout << "entre com o outro numero\n";
    cin >> num2;

    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    cout << num1 + num2 << endl;
    cout << num1 - num2 << endl;
    cout << "o maior eh " << ((num1 > num2) ? num1 : num2) << endl;
    cout << "o menor eh " << ((num1 < num2) ? num1 : num2) << endl;
    cout << ((num1 == num2) ? "sao iguais" : "nao sao iguais") << endl;
}