#include "number_counter.h"

int numberCounter(int N)
{
    int counter = 0;

    while(N > 0)
    {
        N/=10;
        ++counter;
    }

    return counter;
}
