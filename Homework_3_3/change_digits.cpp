#include "change_digits.h"
#include <stdio.h>

int digits_number(int number)
{
    int counter = 0;
    int digits_number = number;

    while(digits_number > 0)
    {
        digits_number /= 10;
        ++counter;
    }

    return counter;
}

void changeDigits(int* M, int number, int size)
{
    for(int i = size - 1; i >= 0; --i)
    {
        M[i] = number % 10;
        number /= 10;
    }

    int change = M[0];
    M[0] = M[(size - 1)];
    M[(size - 1)] = change;
}
