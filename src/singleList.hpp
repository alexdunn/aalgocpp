#include <vector>

namespace aalgo
{

// singly linked list
// This problem is from LeetCode OJ (https://leetcode.com/problems/merge-k-sorted-lists/)
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// This is a convenience method for testing.  That creates a singly linked list with the values of the given vector.
ListNode* listFromVector(std::vector<int> vector);

// Check that the values of the two given linked list are the same.
bool listsEqual(ListNode* list1, ListNode* list2);

// Make ListNode std::cout compatible
std::ostream& operator<<(std::ostream &os, ListNode* const &list);

// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
ListNode* mergeKLists(std::vector<ListNode*>& lists);

// Create a copy of the given list
ListNode* copyList(ListNode* list);

// TODO: Find the majority element in an array in O(n*log(n))

} // aalgo
