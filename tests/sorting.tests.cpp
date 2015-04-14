#include "sorting.h"
#include "gtest/gtest.h"

TEST(InsertionSort, Test)
{
    std::vector<int> testVector = {12345, 22, 0, 1, 100, 0};
    std::vector<int> correctResultVector = {0, 0, 1, 22, 100, 12345};
    std::vector<int> resultVector = aalgo::insertionSort(testVector);
    EXPECT_TRUE(resultVector == correctResultVector) << "Expected " << ::testing::PrintToString(correctResultVector) << "\nGot " << ::testing::PrintToString(resultVector);
}

