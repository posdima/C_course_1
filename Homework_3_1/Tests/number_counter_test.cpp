#include "gtest/gtest.h"

#include "../number_counter.h"

//int numberCounter(int N);

TEST(NumberCounterTest, ZeroTest)
{
    EXPECT_EQ(numberCounter(0), 0);
}

TEST(NumberCounterTest, NegativeTest)
{
    EXPECT_EQ(numberCounter(-1), 0);
}

TEST(NumberCounterTest, OneDigitTest)
{
    EXPECT_EQ(numberCounter(5), 1);
}

TEST(NumberCounterTest, TenTest)
{
    EXPECT_EQ(numberCounter(10), 2);
}

TEST(NumberCounterTest, TwoDigitTest)
{
    EXPECT_EQ(numberCounter(25), 2);
}

TEST(NumberCounterTest, FiveDigitTest)
{
    EXPECT_EQ(numberCounter(12345), 5);
}
