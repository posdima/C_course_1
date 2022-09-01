#include <math.h>
#include <stdio.h>
//Программа перевода числа из десятичной системы счисления в двоичную.

int main()
{
    printf("Enter decimal number: ");
    int decimal_number;
    scanf("%d", &decimal_number);
    int binary_number = 0;

    int counter;
    counter = 0;

    while(decimal_number>0)
    {
        binary_number += (decimal_number%2) * pow(10, counter);
        decimal_number/=2;
        ++counter;
    }

    printf("This number in binary system is: %d\n", binary_number);

    return 0;
}
