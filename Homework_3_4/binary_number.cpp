#include "binary_number.h"
#include <math.h>

int binaryNumber(int decimal_number)
{
    int binary_number = 0;
    int counter = 0;

    while(decimal_number)
    {
        binary_number += (decimal_number%2) * pow(10, counter);
        decimal_number/=2;
        ++counter;
    }

    return binary_number;
}
