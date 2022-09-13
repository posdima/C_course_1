#include "gtest/gtest.h"

#include "../least_divisor.h"

//int least_divisor(int a, int b, int c);

TEST(LeastDivisorTest, NumbersTest)
{
    ASSERT_EQ(least_divisor(1, 1, 1), 1);
    ASSERT_NE(least_divisor(1, 1, 1), 0);
    ASSERT_EQ(least_divisor(4, 6, 8), 2);
    ASSERT_EQ(least_divisor(10, 15, 20), 5);
    ASSERT_EQ(least_divisor(3, 5, 7), 1);
}
