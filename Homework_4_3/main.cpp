//Дана матрица размером 7х7. Поменять местами k-й столбец с k-ой строкой

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Two-dimensional array:\n\n");

    constexpr int row_size = 7;
    constexpr int col_size = 7;

    int M[row_size][col_size];

    srand(time(nullptr));

    for(int i = 0; i < row_size; ++i)
    {
        for(int j = 0; j < col_size; ++j)
        {
            M[i][j] = rand() % 21 - 10;
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter number of row and column, which you want to change with each other: ");
    int k;
    scanf("%d", &k);
    printf("\n");

    int k_row = k - 1;
    int k_col = k - 1;

    for(int i = 0, j = 0; i < row_size && j < col_size; ++i, ++j)
    {
        int change = M[k_row][j];
        M[k_row][j] = M[i][k_col];
        M[i][k_col] = change;
    }

    printf("\nChanged array:\n\n");

    for(int i = 0; i < row_size ; ++i)
    {
        for(int j = 0; j < col_size; ++j)
        {
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}
