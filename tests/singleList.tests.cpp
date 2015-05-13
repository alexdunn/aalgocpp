#include "singleList.hpp"
#include "gtest/gtest.h"

TEST(ListMerge, Test)
{
    auto inputVector1 = {1, 4, 5, 9};
    auto inputVector2 = {2, 6, 11, 100, 11234};
    auto expectedVector = {1, 2, 4, 5, 6, 9, 11, 100, 11234};
    auto inputList1 = aalgo::listFromVector(inputVector1);
    auto inputList2 = aalgo::listFromVector(inputVector2);
    auto expectedList = aalgo::listFromVector(expectedVector);
    std::vector<std::shared_ptr<aalgo::ListNode>> lists = {inputList1, inputList2};
    auto result = aalgo::mergeKLists(lists);
    EXPECT_TRUE(aalgo::listsEqual(result, expectedList)) << "Expected " << ::testing::PrintToString(expectedList) << "\nGot " << ::testing::PrintToString(result);

    lists = {inputList2, inputList1};
    result = aalgo::mergeKLists(lists);
    EXPECT_TRUE(aalgo::listsEqual(result, expectedList)) << "Expected " << ::testing::PrintToString(expectedList) << "\nGot " << ::testing::PrintToString(result);

    lists = {};
    ASSERT_THROW(aalgo::mergeKLists(lists), std::invalid_argument);

    lists = {inputList1};
    ASSERT_THROW(aalgo::mergeKLists(lists), std::invalid_argument);

    inputVector1 = {3, 3, 3, 3};
    inputVector2 = {4, 4, 4};
    expectedVector = {3, 3, 3, 3, 4, 4, 4};
    inputList1 = aalgo::listFromVector(inputVector1);
    inputList2 = aalgo::listFromVector(inputVector2);
    expectedList = aalgo::listFromVector(expectedVector);
    lists = {inputList1, inputList2};
    result = aalgo::mergeKLists(lists);
    EXPECT_TRUE(aalgo::listsEqual(result, expectedList)) << "Expected " << ::testing::PrintToString(expectedList) << "\nGot " << ::testing::PrintToString(result);

    lists = {inputList2, inputList1};
    result = aalgo::mergeKLists(lists);
    EXPECT_TRUE(aalgo::listsEqual(result, expectedList)) << "Expected " << ::testing::PrintToString(expectedList) << "\nGot " << ::testing::PrintToString(result);
}

TEST(ListCopy, Test)
{
    auto inputVector = {4, 1, 6, 3, 3, 1, 9};
    auto inputList = aalgo::listFromVector(inputVector);
    auto expected = {4, 1, 6, 3, 3, 1, 9};
    auto expectedList = aalgo::listFromVector(expected);
    auto result = aalgo::copyList(inputList);

    EXPECT_TRUE(aalgo::listsEqual(expectedList, result)) << "Expected the copy " << ::testing::PrintToString(result) << " to equal its original " << inputList;
}

TEST(ListEquality, Test)
{
    auto inputVector1 = {4, 1, 6, 3, 3, 1, 9};
    auto inputVector2 = {4, 1, 6, 3, 3, 1, 9};
    auto inputVector3 = {4, 1, 6, 3, 3, 1, 9, 10};
    auto inputVector4 = {4, 6, 3, 3, 1, 9};
    auto inputList1 = aalgo::listFromVector(inputVector1);
    auto inputList2 = aalgo::listFromVector(inputVector2);
    auto inputList3 = aalgo::listFromVector(inputVector3);
    auto inputList4 = aalgo::listFromVector(inputVector4);

    EXPECT_TRUE(aalgo::listsEqual(inputList1, inputList1)) << "Expected " << inputList1 << " to equal itself";
    EXPECT_TRUE(aalgo::listsEqual(inputList1, inputList2)) << "Expected " << inputList1 << " to equal " << inputList2;
    EXPECT_TRUE(aalgo::listsEqual(inputList2, inputList1)) << "Expected " << inputList2 << " to equal " << inputList1;
    EXPECT_FALSE(aalgo::listsEqual(inputList1, inputList3)) << "Expected " << inputList1 << " to NOT equal " << inputList3;
    EXPECT_FALSE(aalgo::listsEqual(inputList3, inputList1)) << "Expected " << inputList3 << " to NOT equal " << inputList1;
    EXPECT_FALSE(aalgo::listsEqual(inputList1, inputList4)) << "Expected " << inputList1 << " to NOT equal " << inputList4;
    EXPECT_FALSE(aalgo::listsEqual(inputList4, inputList1)) << "Expected " << inputList4 << " to NOT equal " << inputList1;
}

TEST(ListNode, StreamOperator)
{
    auto inputVector1 = {4, 1, 6, 3, 3, 1, 9};
    auto inputList1 = aalgo::listFromVector(inputVector1);

    std::stringstream buffer;
    buffer << inputList1;
    std::string expected = "ListNode(4, 1, 6, 3, 3, 1, 9)";
    std::string result = buffer.str();
    EXPECT_TRUE(result.compare(expected) == 0) << "Expected |" << expected << "|\nGot |" << result << "|";
}
