#include "row_sum.h"
#include <math.h>

double rowSum(double x)
{
    double sum = x;
    double row = 1;

    int fact1 = 1;
    int fact2 = 1;
    int i = 1;
    const double epsilon = 1e-5;

    while(row > epsilon)
    {
        fact1 *= (2 * i - 1);
        fact2 *= 2 * i;

        row = (fact1 * pow(x, (2 * i + 1))) / (fact2 * (2 * i + 1));

        sum += row;

        ++i;
    }

    return sum;
}
