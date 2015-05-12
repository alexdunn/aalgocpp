#include <vector>

namespace aalgo
{

// singly linked list
// This problem is from LeetCode OJ (https://leetcode.com/problems/merge-k-sorted-lists/)
struct ListNode
{
    int val;
    std::shared_ptr<ListNode> next;
    ListNode(int x) : val(x), next(NULL) {}
};

// This is a convenience method for testing.  That creates a singly linked list with the values of the given vector.
std::shared_ptr<ListNode> listFromVector(std::vector<int> vector);

// Check that the values of the two given linked list are the same.
bool listsEqual(std::shared_ptr<ListNode> list1, std::shared_ptr<ListNode> list2);

// Make ListNode std::cout compatible
std::ostream& operator<<(std::ostream &os, std::shared_ptr<ListNode> const &list);

// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
std::shared_ptr<ListNode> mergeKLists(std::vector<std::shared_ptr<ListNode>>& lists);

// Create a copy of the given list
std::shared_ptr<ListNode> copyList(std::shared_ptr<ListNode> list);

} // namespace aalgo
