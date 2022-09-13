/*Программа, меняющая местами цифры старшего и младшего разрядов данного натурального числа
(например, из числа 3879 получится 9873)*/

#include "change_digits.h"
#include <stdio.h>

int main()
{
    printf("Enter natural two-digit number more than 11: ");
    int number;
    scanf("%d", &number);

    if(number < 12)
    {
        printf("You have entered wrong number!");
        return 0;
    }

    const int result = changeDigits(number);

    printf("Converted number is: %d\n", result);

    return 0;
}
