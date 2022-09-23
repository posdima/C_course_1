/*Программа, меняющая местами цифры старшего и младшего разрядов данного натурального числа
(например, из числа 3879 получится 9873)*/

#include "change_digits.h"
#include <stdio.h>

int main()
{
    printf("Enter natural two-digit or more number: ");
    int number;
    scanf("%d", &number);

    if(number < 10)
    {
        printf("You have entered wrong number!");
        return 1;
    }

    const int size = digits_number(number);

    int* M = new int [size];

    changeDigits(reinterpret_cast<int*>(M), number, size);

    for(int i = 0; i < size; ++i)
    {
        printf("%d", M[i]);
    }

    delete [] M;

    return 0;
}
