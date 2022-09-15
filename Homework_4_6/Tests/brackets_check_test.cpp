#include "gtest/gtest.h"

#include "../brackets_check.h"

//int bracketsCheck(char *str);

TEST(BracketsCheckTest, BracketTest1)
{
    char str[] = {'(', ')', '(', ')'};
    EXPECT_EQ(bracketsCheck((char*) str), 0);
}

TEST(BracketsCheckTest, BracketTest2)
{
    char str[] = {'(', '(', ')'};
    EXPECT_EQ(bracketsCheck((char*) str), 1);
}

TEST(BracketsCheckTest, BracketTest3)
{
    char str[] = {'(', '(',};
    EXPECT_EQ(bracketsCheck((char*) str), 2);
}

TEST(BracketsCheckTest, BracketTest4)
{
    char str[] = {')', '(',};
    EXPECT_EQ(bracketsCheck((char*) str), -1);
}

TEST(BracketsCheckTest, LetterTest)
{
    char str[] = {'2'};
    EXPECT_EQ(bracketsCheck((char*) str), -1);
}
