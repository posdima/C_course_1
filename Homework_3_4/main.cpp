#include <math.h>
#include <stdio.h>
//Программа перевода числа из десятичной системы счисления в двоичную.

int main()
{
    printf("Enter decimal number: ");
    int decimal_number;
    scanf("%d", &decimal_number);
    int binary_number = 0;

    for(int i=0; decimal_number>0; ++i)
    {
        binary_number += (decimal_number%2) * pow(10, i);
        decimal_number/=2;
    }

    printf("This number in binary system is: %d\n", binary_number);

    return 0;
}
