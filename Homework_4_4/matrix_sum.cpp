#include "matrix_sum.h"

int matrixSum(int* M, int x, int y)
{
    if (!M)
    {
        return 0;
    }

    int sum = 0;

    for(int i = 0; i < x; ++i)
    {
        for(int j = 0; j < y - i - 1; ++j)
        {
            sum += *((M + i * y) + j);
        }
    }
    return sum;
}
