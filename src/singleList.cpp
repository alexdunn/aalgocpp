#include <stdexcept>
#include <vector>
#include <iostream>
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
    while (currentNode1 && currentNode2)
    {
        if (currentNode1->val != currentNode2->val)
        {
            return false;
        }
        currentNode1 = currentNode1->next;
        currentNode2 = currentNode2->next;
    }
    if (currentNode1 || currentNode2) // They should both be exhausted if they are the same length
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
            auto    newNode = new aalgo::ListNode(i);
            result = newNode;
            currentNode = result;
        }
        else
        {
            auto    newNode = new aalgo::ListNode(i);
            currentNode->next = newNode;
            currentNode = newNode;
        }
    }
    return result;
}

ListNode* copyList(ListNode* list)
{
    auto    result = new ListNode(list->val);
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
    ListNode* currentNodeToCopy;
    ListNode* currentSearchNode;
    ListNode* previousSearchNode;
    for (size_t i = 1; i < lists.size(); i++)
    {
        previousSearchNode = nullptr;
        currentSearchNode = result;
        currentNodeToCopy = lists[i];
        while (currentNodeToCopy)
        {
            if (!currentSearchNode)   // At the end of the results lists, add it to the end
            {
                auto  newNode = new ListNode(currentNodeToCopy->val);
                currentNodeToCopy = currentNodeToCopy->next;
                previousSearchNode->next = newNode;
                previousSearchNode = newNode;
            }
            else if (currentNodeToCopy->val <= currentSearchNode->val)
            {
                auto  newNode = new ListNode(currentNodeToCopy->val);
                currentNodeToCopy = currentNodeToCopy->next;
                newNode->next = currentSearchNode;
                if (previousSearchNode)
                {
                    previousSearchNode->next = newNode;
                }
                else
                {
                    // This becomes the first item in the list
                    result = newNode;
                }
                previousSearchNode = newNode;
            }
            else
            {
                previousSearchNode = currentSearchNode;
                currentSearchNode = currentSearchNode->next;
            }
        }
    }
    return result;
}

} // namespace aalgo
