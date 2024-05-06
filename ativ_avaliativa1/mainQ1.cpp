#include "longerinter.h"
#include <iostream>

using namespace std;

int main()
{
    LongInteger *vet[5];

    for (int i = 0; i < 5; i++)
    {
        string num;
        cout << "Digite o valor do " << i + 1 << " numero.\n";
        cin >> num;
        vet[i] = new LongInteger(num);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "O valor " << i + 1 << " do vetor " << ((*vet[i]).is_palindromo() ? "eh" : "nao eh") << " um palindromo.\n";
    }

    LongInteger n1 = *vet[0], n2 = *vet[1];

    cout << "n1: " << n1 << endl;
    ++n1;
    cout << "after ++n1: " << n1 << endl;
    cout << "++n1: " << ++n1 << endl;
    cout << "n1++: " << n1++ << endl;
    cout << "n1 afeter n1++: " << n1 << endl;

    cout << "n1: " << n1 << endl;
    --n1;
    cout << "after --n1: " << n1 << endl;
    cout << "--n1: " << --n1 << endl;
    cout << "n1--: " << n1-- << endl;
    cout << "n1 afeter n1--: " << n1 << endl;

    cout << "n1 += n2: " << (n1 += n2) << endl;
    cout << "n1 -= n2: " << (n1 -= n2) << endl;
}