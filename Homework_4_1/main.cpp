//Поменять местами максимальный и последний отрицательный элементы массива M(40)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    constexpr int size = 40;
    int M[size];

    srand(time(nullptr));

    printf("\nInitial array:\n");

    for(int i = 0; i < size; ++i)
    {
        M[i] = rand() % 21 - 10;
        printf("%d  ", M[i]);
    }

    printf("\n");

    int max = 0;
    int last_negative;

    for(int i = 0; i < size; ++i)
    {
        if(M[max] < M[i])
        {
            max = i;
        }
    }

    int i = 39;
    while(M[i] >= 0)
    {
        --i;
    }
    last_negative = i;

    int change = M[max];
    M[max] = M[last_negative];
    M[last_negative] = change;

    printf("Changed array:\n");

    for(int i = 0; i < size; ++i)
    {
        printf("%d  ", M[i]);
    }

    return 0;
}
