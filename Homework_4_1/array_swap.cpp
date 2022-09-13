#include "array_swap.h"

void swap(int* M, int x)
{
    int max = 0;
    int last_negative;

    for(int i = 0; i < x; ++i)
    {
        if(M[max] < M[i])
        {
            max = i;
        }
    }

    int i = x - 1;
    while(M[i] >= 0)
    {
        --i;
    }

    last_negative = i;

    int change = M[max];
    M[max] = M[last_negative];
    M[last_negative] = change;
}
