#include "gtest/gtest.h"

#include "../array_compare.h"

//void arrayCompare(int* A, int* B, int x, int y);

TEST(ArrayCompare, Test1)
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int B[] = {1, 3, 5, 7, 9};

    arrayCompare(A, B, 8, 5);

    EXPECT_EQ(A[1], 2);
    EXPECT_EQ(A[3], 4);
    EXPECT_EQ(A[5], 6);
    EXPECT_EQ(A[7], 8);
}

TEST(ArrayCompare, Test2)
{
    int A[] = {-1, -2, -3, -4, -5, -6};
    int B[] = {1, 3, 5, 7, 9};

    arrayCompare(A, B, 6, 5);

    EXPECT_EQ(A[0], -1);
    EXPECT_EQ(A[1], -2);
    EXPECT_EQ(A[2], -3);
    EXPECT_EQ(A[3], -4);
    EXPECT_EQ(A[4], -5);
    EXPECT_EQ(A[5], -6);
}

TEST(ArrayCompare, Test3)
{
    int A[5] = {};
    int B[] = {1, 3, 5, 7, 9};

    arrayCompare(A, B, 5, 5);

    EXPECT_EQ(A[0], 0);
    EXPECT_EQ(A[1], 0);
    EXPECT_EQ(A[2], 0);
    EXPECT_EQ(A[3], 0);
    EXPECT_EQ(A[4], 0);
}

TEST(ArrayCompare, Test4)
{
    int A[] = {1, 3, 5, 7, 9};
    int B[5] = {};

    arrayCompare(A, B, 5, 5);

    EXPECT_EQ(A[0], 1);
    EXPECT_EQ(A[1], 3);
    EXPECT_EQ(A[2], 5);
    EXPECT_EQ(A[3], 7);
    EXPECT_EQ(A[4], 9);
}



