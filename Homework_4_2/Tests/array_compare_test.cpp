#include "gtest/gtest.h"

#include "../array_compare.h"

//void arrayCompare(int* A, int* B, int x, int y);

TEST(ArrayCompare, Test)
{
    int A[5] = {1, 2, 3, 4, 5};
    int B[5] = {1, 3, 5, 7, 9};

    EXPECT_EQ(arrayCompare((int*)A, (int*)B, 5, 5), (1,3));
}
