/*Программа, меняющая местами цифры старшего и младшего разрядов данного натурального числа
(например, из числа 3879 получится 9873)*/

#include "change_digits.h"
#include <stdio.h>

int main()
{
    printf("Enter natural two-digit number: ");
    int number;
    scanf("%d", &number);

    if(number < 10)
    {
        printf("You have entered wrong number!");
        return 1;
    }

    changeDigits(number);

    return 0;
}
