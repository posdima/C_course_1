#include "change_digits.h"
#include <math.h>

int changeDigits(int number)
{
    int last = number % 10;
    int first = number;
    int counter = 0;

    while(first > 10)
    {
        first /= 10;
        ++counter;
    }

    number += (first - last) + (last - first) * pow(10, counter);

    return number;
}
