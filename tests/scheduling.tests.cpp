#include "scheduling.hpp"
#include "gtest/gtest.h"

TEST(JobOverlap, Test)
{
    aalgo::Job a = aalgo::Job(3, 6);
    aalgo::Job b = aalgo::Job(1, 4);
    aalgo::Job c = aalgo::Job(4, 10);
    aalgo::Job d = aalgo::Job(1, 3);
    aalgo::Job e = aalgo::Job(4, 5);
    aalgo::Job f = aalgo::Job(0, 1);
    aalgo::Job g = aalgo::Job(20, 123456);
    EXPECT_TRUE(a.Overlap(b));
    EXPECT_TRUE(b.Overlap(a));
    EXPECT_TRUE(a.Overlap(c));
    EXPECT_TRUE(c.Overlap(a));
    EXPECT_TRUE(a.Overlap(a));
    EXPECT_FALSE(a.Overlap(d));
    EXPECT_FALSE(d.Overlap(a));
    EXPECT_TRUE(a.Overlap(e));
    EXPECT_TRUE(e.Overlap(a));
    EXPECT_FALSE(a.Overlap(f));
    EXPECT_FALSE(f.Overlap(a));
    EXPECT_FALSE(a.Overlap(g));
    EXPECT_FALSE(g.Overlap(a));
}

TEST(OptimalScheduling, Test)
{
    std::vector<aalgo::Job> jobs1 = {aalgo::Job(0, 20), aalgo::Job(1, 3), aalgo::Job(5, 7), aalgo::Job(8, 10), aalgo::Job(11, 13)};
    std::vector<aalgo::Job> correctBestSchedule1 = {aalgo::Job(1, 3), aalgo::Job(5, 7), aalgo::Job(8, 10), aalgo::Job(11, 13)};
    std::vector<aalgo::Job> bestSchedule1 = aalgo::optimalScheduling(jobs1);
    EXPECT_TRUE(bestSchedule1 == correctBestSchedule1) << "Expected " << ::testing::PrintToString(correctBestSchedule1) << "\nGot " << ::testing::PrintToString(bestSchedule1);

    std::vector<aalgo::Job> jobs2 = {aalgo::Job(8, 10), aalgo::Job(1, 3), aalgo::Job(5, 7), aalgo::Job(0, 20), aalgo::Job(11, 13)};
    std::vector<aalgo::Job> correctBestSchedule2 = {aalgo::Job(1, 3), aalgo::Job(5, 7), aalgo::Job(8, 10), aalgo::Job(11, 13)};
    std::vector<aalgo::Job> bestSchedule2 = aalgo::optimalScheduling(jobs2);
    EXPECT_TRUE(bestSchedule2 == correctBestSchedule2) << "Expected " << ::testing::PrintToString(correctBestSchedule2) << "\nGot " << ::testing::PrintToString(bestSchedule2);

    std::vector<aalgo::Job> jobs3 = {aalgo::Job(4, 8), aalgo::Job(7, 13), aalgo::Job(1, 5)};
    std::vector<aalgo::Job> correctBestSchedule3 = {aalgo::Job(1, 5), aalgo::Job(7, 13)};
    std::vector<aalgo::Job> bestSchedule3 = aalgo::optimalScheduling(jobs3);
    EXPECT_TRUE(bestSchedule3 == correctBestSchedule3) << "Expected " << ::testing::PrintToString(correctBestSchedule3) << "\nGot " << ::testing::PrintToString(bestSchedule3);
}

