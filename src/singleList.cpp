#include <vector>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include "singleList.hpp"

namespace aalgo
{

std::ostream& operator<<(std::ostream &os, ListNode* const &list)
{
    ListNode* currentNode = list;
    std::string outputString = "";
    while (currentNode)
    {
        outputString += std::to_string(currentNode->val);
        currentNode = currentNode->next;
        if (currentNode)
        {
            outputString += ", ";
        }
    }
    return os << "ListNode(" << outputString << ")";
}

bool listsEqual(ListNode* list1, ListNode* list2)
{
    ListNode* currentNode1 = list1;
    ListNode* currentNode2 = list2;
    while (currentNode1)
    {
        if (currentNode1->val != currentNode2->val)
        {
            return false;
        }
        currentNode1 = currentNode1->next;
        currentNode2 = currentNode2->next;
    }
    if (currentNode2)
    {
        return false;
    }
    return true;
}

ListNode* listFromVector(std::vector<int> vector)
{
    ListNode* result = nullptr;
    ListNode* currentNode = nullptr;
    for (auto i : vector)
    {
        if (!result)
        {
            ListNode* newNode = new aalgo::ListNode(i);
            result = newNode;
            currentNode = result;
        }
        else
        {
            ListNode* newNode = new aalgo::ListNode(i);
            currentNode->next = newNode;
            currentNode = newNode;
        }
    }
    return result;
}

ListNode* copyList(ListNode* list)
{
    ListNode* result = new ListNode(list->val);
    ListNode* currentNode = result;
    ListNode* currentNodeToCopy = list->next;
    while (currentNodeToCopy)
    {
        currentNode->next = new ListNode(currentNodeToCopy->val);
        currentNode = currentNode->next;
        currentNodeToCopy = currentNodeToCopy->next;
    }
    return result;
}

// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
    if (lists.size() < 2)
    {
        std::stringstream message;
        message << "Not enough ListNodes were provided for merging.";
        throw std::invalid_argument(message.str());
    }
    ListNode* result = copyList(lists[0]);
    ListNode* currentNodeToCopy = lists[0];
    ListNode* currentSearchNode = result;
    for (size_t i = 1; i < lists.size(); ++i)
    {
        currentSearchNode = result;
        currentNodeToCopy = lists[i];
        while (currentNodeToCopy)
        {
            if ((currentNodeToCopy->val > currentSearchNode->val && currentNodeToCopy->val < currentSearchNode->next->val) || !currentSearchNode->next)
            {
                ListNode* newNode = new ListNode(currentNodeToCopy->val);
                newNode->next = currentSearchNode->next;
                currentSearchNode->next = newNode;
                currentNodeToCopy = currentNodeToCopy->next;
            }
            else
            {
                currentSearchNode = currentSearchNode->next;
            }
        }
    }
    return result;
}

// TODO: Find the majority element in an array in O(n*log(n))

} // aalgo
