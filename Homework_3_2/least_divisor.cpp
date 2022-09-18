#include "least_divisor.h"
#include <stdio.h>

int least_divisor(int a, int b, int c)
{
    int result = 1;
    int min;
    min = a < b ? a : b;
    min = min < c ? min : c;

    for(int i = min; i > 1; --i)
    {
        if((a % i == 0) && (b % i == 0) && (c % i == 0))
        {
            result = i;
        }
    }

    return result;
}
