#include "gtest/gtest.h"

#include "../row_sum.h"

//double rowSum(double x);

TEST(RowSumTest, Test1)
{
    const double epsilon = 1e-5;

    EXPECT_NEAR(rowSum (0.051), 0.051022, epsilon);
    EXPECT_NEAR(rowSum (0.8), 0.926327, epsilon);
    EXPECT_NEAR(rowSum (0.076), 0.076073, epsilon);
    EXPECT_NEAR(rowSum (0.99), 1.312190, epsilon);
}
