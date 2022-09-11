//Дано натуральное число N. Составить программу для определения количества цифр в этом числе

#include "number_counter.h"
#include <stdio.h>

int main()
{
    printf("Enter natural number N: ");
    int N;
    scanf("%d", &N);

    numberCounter(N);

    return 0;
}
