
#include "TXLib.h"

int Compare = 0;
int Change = 0;

#include "DFSort.h"

//#include "BubbleSort.h"

int main()
    {
    const int Size = 10;

    int Mass [Size] = {};

    Randomizer (Mass, Size);

    DFSort (Mass, Size);

    Checker (Mass, Size);

    return 0;
    }

