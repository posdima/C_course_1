#include "gtest/gtest.h"

#include "../binary_number.h"

//int binaryNumber(int decimal_number);

TEST(BinaryNumberTest, NumbersTest)
{
    EXPECT_EQ(binaryNumber(1), 1);
    EXPECT_EQ(binaryNumber(2), 10);
    EXPECT_EQ(binaryNumber(3), 11);
    EXPECT_EQ(binaryNumber(4), 100);
    EXPECT_EQ(binaryNumber(5), 101);
    EXPECT_EQ(binaryNumber(6), 110);
    EXPECT_EQ(binaryNumber(7), 111);
    EXPECT_EQ(binaryNumber(8), 1000);
    EXPECT_EQ(binaryNumber(9), 1001);
    EXPECT_EQ(binaryNumber(127), 1111111);
    EXPECT_EQ(binaryNumber(128), 10000000);
}
