/*Найти наименьший общий делитель трех натуральных чисел
(1 будет считаться наименьшим общим делителем только в том случае,
когда других общих делителей у заданных чисел нет)*/

#include "least_divisor.h"
#include <stdio.h>

int main()
{
    printf("Enter three natural numbers: ");
    int a;
    int b;
    int c;
    scanf("%d%d%d", &a, &b, &c);

    if(a <= 0 || b <= 0 || c <= 0)
    {
        printf("All numbers must be more than 0!");
        return 0;
    }

    least_divisor(a, b, c);

    return 0;
}
