#include "row_sum.h"
#include <math.h>

double rowSum(double x)
{
    double sum = x;
    double row = 1;

    int fact1;
    int fact2;

    for(int i = 1; row > 1e-5; ++i)
    {
        fact1 = 1;
        fact1 *= (2 * i -1);

        fact2 = 1;
        fact2 *= 2 * i;

        row *= (fact1 * pow(x, (2 * i + 1))) / (fact2 * (2 * i + 1));

        sum += row;
    }

    return sum;
}
