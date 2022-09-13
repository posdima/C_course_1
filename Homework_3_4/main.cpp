//Программа перевода числа из десятичной системы счисления в двоичную

#include "binary_number.h"
#include <stdio.h>

int main()
{
    printf("Enter decimal non-negative number: ");
    int decimal_number;
    scanf("%d", &decimal_number);

    if(decimal_number < 0)
    {
        printf("You have entered negative number!");
        return 0;
    }

    const int result = binaryNumber(decimal_number);

    printf("This number in binary system is: %d\n", result);

    return 0;
}
