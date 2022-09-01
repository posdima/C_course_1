#include <math.h>
#include <stdio.h>
/*Найти наименьший общий делитель трех натуральных чисел (1 будет считаться наименьшим
общим делителем только в том случае, когда других общих делителей у заданных чисел нет)*/

int main()
{
    printf("Enter three numbers: ");
    int a;
    int b;
    int c;
    scanf("%d%d%d", &a, &b, &c);

    int max;
    max = a > b ? a : b;
    max = max > c ? max : c;

    for(int i=2; i < max; ++i)
    {
        if((a%i==0)&&(b%i==0)&&(c%i==0))
        {
            printf("The least common divisor is: %d\n", i);
            return 0;
        }
    }

    printf("The least common divisor is 1");

    return 0;
}
