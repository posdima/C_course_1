#include "gtest/gtest.h"

#include "../row_sum.h"

//double rowSum(double x);

TEST(RowSumTest, NumbersTest)
{
    const double EPSILON = 1e-5;
    EXPECT_NEAR(rowSum (0.051), 0.051022, EPSILON);
    EXPECT_NEAR(rowSum (0.6), 0.636421, EPSILON);
    EXPECT_NEAR(rowSum (0.7), 0.758622, EPSILON);
    EXPECT_NEAR(rowSum (0.8), 0.889634, EPSILON);
    EXPECT_NEAR(rowSum (0.99), 1.177590, EPSILON);
}
