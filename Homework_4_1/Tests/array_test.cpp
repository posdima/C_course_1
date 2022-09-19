#include "gtest/gtest.h"

#include "../array_swap.h"

//void swap(int* M, int x)

TEST(CheckSwapPositions, NumbersTest1)
{
    int M[] = {1, 3, 8, 5, -3, 2};

    swap (M, 6);

    EXPECT_EQ(M[2], -3);
    EXPECT_EQ(M[4], 8);
}

TEST(CheckSwapPositions, NumbersTest2)
{
    int M[] = {2, 9, 6, 7, 5, 3, 4, -3};

    swap (M, 8);

    EXPECT_EQ(M[1], -3);
    EXPECT_EQ(M[7], 9);
}

TEST(CheckSwapPositions, NumbersTest3)
{
    int M[] = {2, 9, 6, 7, 5, 3, 4, 2};

    swap (M, 8);

    EXPECT_EQ(M[1], 9);
    EXPECT_EQ(M[7], 2);
}

TEST(CheckSwapPositions, NumbersTest4)
{
    int M[] = {0, 0, 0, 0, 0, 0, 0, -1};

    swap (M, 8);

    EXPECT_EQ(M[0], -1);
    EXPECT_EQ(M[7], 0);
}

TEST(CheckSwapPositions, NumbersTest5)
{
    int M[] = {-2, -3, -5, -7, -1, -4, -9, -6};

    swap (M, 8);

    EXPECT_EQ(M[4], -6);
    EXPECT_EQ(M[7], -1);
}
