#include "array_compare.h"
#include <stdio.h>

void arrayCompare(int* A, int* B, int x, int y)
{
    for(int i = 0; i < x; ++i)
    {
        bool compare = false;

        for(int j = 0; j < y; ++j)
        {
            if(A[i] == B[j])
            {
                compare = true;
                break;
            }
        }

        if(!compare)
            printf("%d\n", i);
    }
}
