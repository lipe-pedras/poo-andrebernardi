#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> primos;
    vector<int> divisores;
    int num = 2;

    do
    {
        for (int element : primos)
        {
            if (num % element == 0) {divisores.push_back(num);}
        }

        if (size(divisores) == 0) {primos.push_back(num);}
        num++;
        divisores.clear();
    } while (size(primos) < 21);
    
    for (int element : primos)
    {
        cout << element << " ";
    }
}