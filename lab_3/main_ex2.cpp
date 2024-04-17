#include "longerinter.h"

int main()
{
    LongInteger i1;
    i1.readFromKeyboard();

    LongInteger i2;
    i2.readFromKeyboard();

    LongInteger i3 = i2 - (i1);

    i3.print();
}