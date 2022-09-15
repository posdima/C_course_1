#include "gtest/gtest.h"

#include "../array_swap.h"

//void swap(int* M, int x)

TEST(CheckSwapPositions, NumbersTest)
{
    int M[] = {1, 3, 8, 5, -3, 2};

    swap (M, 6);

    EXPECT_EQ(M[2], -3);
    EXPECT_EQ(M[4], 8);
}
