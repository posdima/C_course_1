// Определить местоположение элементов массива А (30), не встречающихся в массиве В (15)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    constexpr int size = 30;
    int A[size];

    srand(time(nullptr));

    printf("\nA array:\n");

    for(int i = 0; i < size; ++i)
    {
        A[i] = rand() % 21 - 10;
        printf("%d  ", A[i]);
    }

    constexpr int size_1 = 15;
    int B[size_1];

    printf("\n\nB array:\n");

    for(int j = 0; j < size_1; ++j)
    {
        B[j] = rand() % 21 - 10;
        printf("%d  ", B[j]);
    }

    printf("\n\nElements of A array which don't use in B array located in serial numbers:\n");

    for(int i = 0; i < size; ++i)
    {
        bool compare = false;

        for(int j = 0; j < size_1; ++j)
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

    return 0;
}
