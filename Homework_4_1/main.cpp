//Поменять местами максимальный и последний отрицательный элементы массива M(40)

#include "array_manager.h"
#include "array_swap.h"
#include <stdio.h>

int main()
{
    constexpr int size = 40;
    int M[size];

    printf("\nInitial array:\n");

    fillArray(reinterpret_cast<int*>(M), size);
    printArray(reinterpret_cast<int*>(M), size);

    printf("\n");

    swap(reinterpret_cast<int*>(M), size);

    printf("Changed array:\n");

    printArray(reinterpret_cast<int*>(M), size);

    return 0;
}
