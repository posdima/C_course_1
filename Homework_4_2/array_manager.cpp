#include "array_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int* M, int x)
{
    for(int i = 0; i < x; ++i)
    {
        printf("%d  ", *(M + i));
    }
}

void fillArray(int* M, int x)
{
    srand(time(nullptr));

    for(int i = 0; i < x; ++i)
    {
        *(M + i) = rand() % 21 - 10;
    }
}
