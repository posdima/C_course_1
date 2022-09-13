#include "least_divisor.h"
#include <stdio.h>

int least_divisor(int a, int b, int c)
{
    int max;
    max = a > b ? a : b;
    max = max > c ? max : c;

    for(int i=2; i < max; ++i)
    {
        if((a % i == 0) && (b % i == 0) && (c % i == 0))
        {
            printf("The least common divisor is: %d\n", i);
            return i;
        }
    }

    printf("The least common divisor is 1");
    return 1;
}
