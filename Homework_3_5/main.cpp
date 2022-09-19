//Сумма рядка с точностью 10^-5, где 0.05<x<1

#include "row_sum.h"
#include <stdio.h>

int main()
{
    printf("Enter number x, which is more than 0.05 and less than 1: ");
    double x;
    scanf("%lf", &x);

    if(x <= 0.05 || x >= 1)
    {
        printf("You have entered wrong number!");
        return 1;
    }

    const double result = rowSum(x);

    printf("Sum is: %lf\n", result);

    return 0;
}
