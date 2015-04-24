#include "arithmetic.hpp"
#include "gtest/gtest.h"

TEST(NumberOfDigits, Test)
{
    std::vector<unsigned> expectations = {1, 2, 3, 1, 1, 8};
    std::vector<unsigned> inputs = {0, 11, 123, 00, 1, 87615289};
    int j = 0;
    for (auto i : inputs)
    {
        int expected = expectations[j];
        int result = aalgo::numberOfDigits(i);
        EXPECT_TRUE(result == expected) << "Expected " << ::testing::PrintToString(expected) << "\nGot " << ::testing::PrintToString(result);
        ++j;
    }
}

TEST(DigitAt, Test)
{
    std::vector<unsigned> expectations = {4, 1, 6, 3, 3, 1, 9};
    std::vector<unsigned> inputs = {64, 1, 61, 33, 12345, 998171610, 998171610};
    std::vector<unsigned> inputPositions = {1, 1, 2, 2, 3, 6, 9};
    int j = 0;
    for (auto i : inputs)
    {
        int expected = expectations[j];
        int position = inputPositions[j];
        int result = aalgo::digitAt(i, position);
        EXPECT_TRUE(result == expected) << "Expected " << ::testing::PrintToString(expected) << " at position " << position << " of integer " << i << "\nGot " << ::testing::PrintToString(result);
        ++j;
    }

    ASSERT_THROW(aalgo::digitAt(0, 2), std::invalid_argument);
    ASSERT_THROW(aalgo::digitAt(123, 4), std::invalid_argument);
    ASSERT_NO_THROW(aalgo::digitAt(123, 3));
}

TEST(CarryCount, Test)
{
    std::vector<unsigned> expectations = {0, 3, 1, 1, 0, 0};
    std::vector<unsigned> inputs1 = {123, 555, 123, 999, 0, 0};
    std::vector<unsigned> inputs2 = {456, 555, 594, 1, 0, 999};
    int j = 0;
    for (size_t i = 0; i < inputs1.size(); ++i)
    {
        int expected = expectations[j];
        int a = inputs1[j];
        int b = inputs2[j];
        int result = aalgo::carryOpertions(a, b);
        EXPECT_TRUE(result == expected) << "Expected " << ::testing::PrintToString(expected) << " carry options for integers " << a << " and " << b << "\nGot " << ::testing::PrintToString(result);
        ++j;
    }
}

