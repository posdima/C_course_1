// Определить местоположение элементов массива А (30), не встречающихся в массиве В (15)

#include "array_compare.h"
#include "array_manager.h"
#include <stdio.h>

int main()
{
    constexpr int size = 30;
    int A[size];

    printf("\nA array:\n");

    fillArray(reinterpret_cast<int*>(A), size);
    printArray(reinterpret_cast<int*>(A), size);

    constexpr int size_1 = 15;
    int B[size_1];

    printf("\n\nB array:\n");

    fillArray(reinterpret_cast<int*>(B), size_1);
    printArray(reinterpret_cast<int*>(B), size_1);

    printf("\n\nElements of A array which don't use in B array located in serial numbers:\n");

    arrayCompare(reinterpret_cast<int*>(A), reinterpret_cast<int*>(B), size, size_1);

    return 0;
}
