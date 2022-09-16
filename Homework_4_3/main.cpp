//Дана матрица размером 7х7. Поменять местами k-й столбец с k-ой строкой


#include "matrix_manager.h"
#include "swap_matrix.h"
#include <stdio.h>

int main()
{
    printf("Two-dimensional array:\n\n");

    constexpr int row_size = 7;
    constexpr int col_size = 7;

    int M[row_size][col_size];

    fillMatrix(reinterpret_cast<int*>(M), row_size, col_size);
    printMatrix(reinterpret_cast<int*>(M), row_size, col_size);

    printf("\nEnter number of row and column, which you want to change with each other: ");
    int k;
    scanf("%d", &k);
    printf("\n");

    int k_row = k - 1;
    int k_col = k - 1;

    swapMatrix(reinterpret_cast<int*>(M), row_size, col_size, k_row, k_col);

    printf("\nChanged array:\n\n");

    printMatrix(reinterpret_cast<int*>(M), row_size, col_size);

    return 0;
}
