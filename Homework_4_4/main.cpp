//Вычислить сумму элементов матрицы, лежащих слева от побочной диагонали

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Enter the size of square matrix: ");
    int size;
    scanf("%d", &size);
    printf("\n");

    int row_size = size;
    int col_size = size;

    int M[row_size][col_size];

    srand(time(nullptr));

    for(int i = 0; i < row_size; ++i)
    {
        for(int j = 0; j < col_size; ++j)
        {
            M[i][j] = rand() % 10;
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }

    int sum = 0;
    int cut = col_size - 1;

    for(int i = 0; i < row_size - 1; ++i)
    {
        for(int j = 0; j < cut; ++j)
        {
            sum += M[i][j];
        }
        --cut;
    }

    printf("\nSum of elements from the left side of matrix diagonal is: %d", sum);

    return 0;
}
