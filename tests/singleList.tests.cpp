#include "singleList.hpp"
#include "gtest/gtest.h"

TEST(ListMerge, Test)
{
    std::vector<int> inputVector1 = {1, 4, 5, 9};
    std::vector<int> inputVector2 = {2, 6, 11, 100, 11234};
    std::vector<int> expectedVector = {1, 2, 4, 5, 6, 9, 11, 100, 11234};

    aalgo::ListNode* inputList1 = aalgo::listFromVector(inputVector1);
    aalgo::ListNode* inputList2 = aalgo::listFromVector(inputVector2);
    aalgo::ListNode* expectedList = aalgo::listFromVector(expectedVector);

    std::vector<aalgo::ListNode*> lists = {inputList1, inputList2};

    aalgo::ListNode* result = aalgo::mergeKLists(lists);
    EXPECT_TRUE(aalgo::listsEqual(result, expectedList)) << "Expected " << ::testing::PrintToString(expectedList) << "\nGot " << ::testing::PrintToString(result);

    lists = {inputList2, inputList1};
    result = aalgo::mergeKLists(lists);
    EXPECT_TRUE(aalgo::listsEqual(result, expectedList)) << "Expected " << ::testing::PrintToString(expectedList) << "\nGot " << ::testing::PrintToString(result);

    lists = {};
    ASSERT_THROW(aalgo::mergeKLists(lists), std::invalid_argument);

    lists = {inputList1};
    ASSERT_THROW(aalgo::mergeKLists(lists), std::invalid_argument);
}

TEST(ListCopy, Test)
{
    std::vector<int> inputVector = {4, 1, 6, 3, 3, 1, 9};
    aalgo::ListNode* inputList = aalgo::listFromVector(inputVector);
    std::vector<int> expected = {4, 1, 6, 3, 3, 1, 9};
    aalgo::ListNode* expectedList = aalgo::listFromVector(expected);
    aalgo::ListNode* result = aalgo::copyList(inputList);

    EXPECT_TRUE(aalgo::listsEqual(expectedList, result)) << "Expected the copy " << ::testing::PrintToString(result) << " to equal its original " << inputList;
}

TEST(ListEquality, Test)
{
    std::vector<int> inputVector1 = {4, 1, 6, 3, 3, 1, 9};
    std::vector<int> inputVector2 = {4, 1, 6, 3, 3, 1, 9};
    std::vector<int> inputVector3 = {4, 1, 6, 3, 3, 1, 9, 10};
    std::vector<int> inputVector4 = {4, 6, 3, 3, 1, 9};
    aalgo::ListNode* inputList1 = aalgo::listFromVector(inputVector1);
    aalgo::ListNode* inputList2 = aalgo::listFromVector(inputVector2);
    aalgo::ListNode* inputList3 = aalgo::listFromVector(inputVector3);
    aalgo::ListNode* inputList4 = aalgo::listFromVector(inputVector4);

    EXPECT_TRUE(aalgo::listsEqual(inputList1, inputList1)) << "Expected " << inputList1 << " to equal itself";
    EXPECT_TRUE(aalgo::listsEqual(inputList1, inputList2)) << "Expected " << inputList1 << " to equal " << inputList2;
    EXPECT_TRUE(aalgo::listsEqual(inputList2, inputList1)) << "Expected " << inputList2 << " to equal " << inputList1;
    EXPECT_FALSE(aalgo::listsEqual(inputList1, inputList3)) << "Expected " << inputList1 << " to NOT equal " << inputList3;
    EXPECT_FALSE(aalgo::listsEqual(inputList3, inputList1)) << "Expected " << inputList3 << " to NOT equal " << inputList1;
    EXPECT_FALSE(aalgo::listsEqual(inputList1, inputList4)) << "Expected " << inputList1 << " to NOT equal " << inputList4;
    EXPECT_FALSE(aalgo::listsEqual(inputList4, inputList1)) << "Expected " << inputList4 << " to NOT equal " << inputList1;
}

