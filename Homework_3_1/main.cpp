//Дано натуральное число N. Составить программу для определения количества цифр в этом числе

#include "number_counter.h"
#include <stdio.h>

int main()
{
    printf("Enter natural number N: ");
    int N;
    scanf("%d", &N);

    if(N <= 0)
    {
        printf("It's not a natural number!");
        return -1;
    }

    const int result = numberCounter(N);

    printf("N consists of %d numbers\n", result);

    return 0;
}
