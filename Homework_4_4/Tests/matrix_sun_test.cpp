#include "gtest/gtest.h"

#include "../matrix_sum.h"

//int matrixSum(int* M, int x, int y)

TEST(MatrixSumTest, ZeroTest)
{
    EXPECT_EQ(matrixSum(nullptr, 0, 0), 0);
    EXPECT_EQ(matrixSum(nullptr, 23, 13), 0);
}

TEST(MatrixSumTest, OneValue)
{
    int M[1] = {1};
    EXPECT_EQ(matrixSum(M, 1, 0), 0);
}

TEST(MatrixSumTest, Test)
{
    int M[3][3] = { {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9} };

    EXPECT_EQ(matrixSum((int*)M, 3, 3), 7);
}
