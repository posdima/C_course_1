#include "gtest/gtest.h"

#include "../change_digits.h"

//int changeDigits(int number);

TEST(ChangeDigitsTest, NumbersTest)
{
    ASSERT_EQ(changeDigits(12), 21);
    ASSERT_EQ(changeDigits(1259), 9251);
    ASSERT_EQ(changeDigits(52394), 42395);
    ASSERT_EQ(changeDigits(725393), 325397);
}
