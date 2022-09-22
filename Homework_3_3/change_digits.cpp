#include "change_digits.h"
#include <stdio.h>

void changeDigits(int number)
{
    int counter = 0;
    int digits_number = number;

    while(digits_number > 0)
    {
        digits_number /= 10;
        ++counter;
    }

    int* M = new int [counter];

    for(int i = counter - 1; i >= 0; --i)
    {
        M[i] = number % 10;
        number /= 10;
    }

    int change = M[0];
    M[0] = M[(counter - 1)];
    M[(counter - 1)] = change;

    for(int i = 0; i < counter; ++i)
    {
        printf("%d", M[i]);
    }

    delete [] M;
}
