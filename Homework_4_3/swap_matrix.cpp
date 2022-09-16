#include "swap_matrix.h"

void swapMatrix(int* M, int x, int y, int r, int c)
{

    for(int i = 0, j = 0; i < x && j < y; ++i, ++j)
    {
        int change = *((M + r * y) + j);
        *((M + r * y) + j) = *((M + i * y) + c);
        *((M + i * y) + c) = change;
    }
}
