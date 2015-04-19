#include "cycle.hpp"
#include "gtest/gtest.h"

TEST(Cycle, Length)
{
    // Do we get the right cycle length?
    EXPECT_TRUE(aalgo::cycle_length(22) == 16) << "Expected " << ::testing::PrintToString(16) << "\nGot " << ::testing::PrintToString(aalgo::cycle_length(22));
}

TEST(Cycle, Maximum)
{
    clock_t t = clock();
    int expected = 20;
    int result = aalgo::max_cycle_length(1, 10);
    EXPECT_TRUE(result == expected)  << "Expected " << ::testing::PrintToString(expected) << "\nGot " << ::testing::PrintToString(result);

    expected = 125;
    result = aalgo::max_cycle_length(100, 200);
    EXPECT_TRUE(result == expected)  << "Expected " << ::testing::PrintToString(expected) << "\nGot " << ::testing::PrintToString(result);

    expected = 89;
    result = aalgo::max_cycle_length(201, 210);
    EXPECT_TRUE(result == expected)  << "Expected " << ::testing::PrintToString(expected) << "\nGot " << ::testing::PrintToString(result);

    expected = 174;
    result = aalgo::max_cycle_length(900, 1000);
    EXPECT_TRUE(result == expected)  << "Expected " << ::testing::PrintToString(expected) << "\nGot " << ::testing::PrintToString(result);

    const double work_time = (clock() - t) / double(CLOCKS_PER_SEC);
    ASSERT_TRUE(work_time <= 0.02) << "Expected performance in less than 0.001 but took " << ::testing::PrintToString(work_time);
}
