#include "gtest/gtest.h"

#include "../change_digits.h"

//int digits_number(int number);
//void changeDigits(int* M, int number, int size);

TEST(ChangeDigitsTest, Test1)
{
    int number = 12;
    const int size = digits_number(number);
    int* M = new int [size];
    changeDigits(reinterpret_cast<int*>(M), number, size);

    EXPECT_EQ(M[0], 2);
    EXPECT_EQ(M[1], 1);
}

TEST(ChangeDigitsTest, Test2)
{
    int number = 1259;
    const int size = digits_number(number);
    int* M = new int [size];
    changeDigits(reinterpret_cast<int*>(M), number, size);

    EXPECT_EQ(M[0], 9);
    EXPECT_EQ(M[1], 2);
    EXPECT_EQ(M[2], 5);
    EXPECT_EQ(M[3], 1);
}

TEST(ChangeDigitsTest, Test3)
{
    int number = 52394;
    const int size = digits_number(number);
    int* M = new int [size];
    changeDigits(reinterpret_cast<int*>(M), number, size);

    EXPECT_EQ(M[0], 4);
    EXPECT_EQ(M[1], 2);
    EXPECT_EQ(M[2], 3);
    EXPECT_EQ(M[3], 9);
    EXPECT_EQ(M[4], 5);
}

TEST(ChangeDigitsTest, Test4)
{
    int number = 10000;
    const int size = digits_number(number);
    int* M = new int [size];
    changeDigits(reinterpret_cast<int*>(M), number, size);

    EXPECT_EQ(M[0], 0);
    EXPECT_EQ(M[1], 0);
    EXPECT_EQ(M[2], 0);
    EXPECT_EQ(M[3], 0);
    EXPECT_EQ(M[4], 1);
}

TEST(ChangeDigitsTest, Test5)
{
    int number = 50000000;
    const int size = digits_number(number);
    int* M = new int [size];
    changeDigits(reinterpret_cast<int*>(M), number, size);

    EXPECT_EQ(M[0], 0);
    EXPECT_EQ(M[1], 0);
    EXPECT_EQ(M[2], 0);
    EXPECT_EQ(M[3], 0);
    EXPECT_EQ(M[4], 0);
    EXPECT_EQ(M[5], 0);
    EXPECT_EQ(M[6], 0);
    EXPECT_EQ(M[7], 5);
}
