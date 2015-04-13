#include <iostream>
#include <gtest/gtest.h>

std::vector<int> insertionSort(std::vector<int> values)
{
    for (int i = 1; i < values.size(); ++i)
    {
        int j = i;
        while (j > 0 && values[j] < values[j - 1])
        {
            int higher = values[j - 1];
            values[j - 1] = values[j];
            values[j] = higher;
            j--;
        }
    }
    return values;
}

TEST(InsertionSort, Test)
{
    std::vector<int> testVector = {12345, 22, 0, 1, 100, 0};
    std::vector<int> correctResultVector = {0, 0, 1, 22, 100, 12345};
    std::vector<int> resultVector = insertionSort(testVector);
    EXPECT_TRUE(resultVector == correctResultVector) << "Expcted " << ::testing::PrintToString(correctResultVector) << "\nGot " << ::testing::PrintToString(resultVector);
}

