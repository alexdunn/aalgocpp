#include "strings.hpp"
#include "gtest/gtest.h"

TEST(StartsWithCapitalLetter, Test)
{
    std::string testString = "Xander";
    EXPECT_TRUE(aalgo::startsWithCapitalLetter(testString)) << "Expected " << testString << " starts with a capital letter, but returned false.";

    testString = "xander";
    EXPECT_FALSE(aalgo::startsWithCapitalLetter(testString)) << "Expected " << testString << " does not start with a capital letter, but returned true.";
}

