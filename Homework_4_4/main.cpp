//Вычислить сумму элементов матрицы, лежащих слева от побочной диагонали

#include "matrix_manager.h"
#include "matrix_sum.h"
#include <stdio.h>

int main()
{
    printf("Enter the size of square matrix: ");
    int size;
    scanf("%d", &size);
    printf("\n");

    int row_size = size;
    int col_size = size;

    int M[row_size][col_size];

    fillMatrix(reinterpret_cast<int*>(M), row_size, col_size);
    printMatrix(reinterpret_cast<int*>(M), row_size, col_size);

    const int sum = matrixSum(reinterpret_cast<int*>(M), row_size, col_size);

    printf("\nSum of elements from the left side of matrix diagonal is: %d", sum);

    return 0;
}
