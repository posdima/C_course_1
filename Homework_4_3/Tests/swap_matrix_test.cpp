#include "gtest/gtest.h"

#include "../swap_matrix.h"

//void swapMatrix(int* M, int x, int y, int r, int c)

TEST(SwapMatrixTest, Test1)
{
    int M[3][3] = { {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9} };

    int M_1[3][3] = { {1, 4, 3},
                      {2, 5, 8},
                      {7, 6, 9} };

    swapMatrix(reinterpret_cast<int*>(M), 3, 3, 1, 1);

    EXPECT_EQ(memcmp(reinterpret_cast<int*>(M), reinterpret_cast<int*>(M_1), sizeof(int)*3*3), 0);
}

TEST(SwapMatrixTest, Test2)
{
    int M[3][3] = { {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9} };

    swapMatrix(reinterpret_cast<int*>(M), 3, 3, 1, 1);

    /* int M_swap[3][3] = { {1, 4, 3},
                            {2, 5, 8},
                            {7, 6, 9} }; */

    EXPECT_EQ(M[1][0], 2);
    EXPECT_EQ(M[1][1], 5);
    EXPECT_EQ(M[1][2], 8);
    EXPECT_EQ(M[0][1], 4);
    EXPECT_EQ(M[2][1], 6);
}

TEST(SwapMatrixTest, Test3)
{
    int M[4][4] = { {1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 8, 4, 1},
                    {7, 1, 5, 7} };

    swapMatrix(reinterpret_cast<int*>(M), 4, 4, 2, 2);

    /* int M_swap[4][4] = { {1, 2, 9, 4},
                            {5, 6, 8, 8},
                            {3, 7, 4, 5},
                            {7, 1, 1, 7} }; */

    EXPECT_EQ(M[2][0], 3);
    EXPECT_EQ(M[2][1], 7);
    EXPECT_EQ(M[2][2], 4);
    EXPECT_EQ(M[2][3], 5);
    EXPECT_EQ(M[0][2], 9);
    EXPECT_EQ(M[1][2], 8);
    EXPECT_EQ(M[3][2], 1);
}
