#include "number_counter.h"
#include <stdio.h>

int numberCounter(int N)
{
    int counter = 0;

    if(N <= 0)
    {
        printf("It's not a natural number!");
        return 0;
    }

    else
    {
        while(N > 0)
        {
            N/=10;
            ++counter;
        }
        printf("N consists of %d numbers\n", counter);
        return counter;
    }
}
