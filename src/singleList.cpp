#include <stdexcept>
#include <vector>
#include <iostream>
#include <sstream>
#include "singleList.hpp"

namespace aalgo
{

std::ostream& operator<<(std::ostream &os, std::shared_ptr<ListNode> const &list)
{
    auto currentNode = list;
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

bool listsEqual(std::shared_ptr<ListNode> list1, std::shared_ptr<ListNode> list2)
{
    auto currentNode1 = list1;
    auto currentNode2 = list2;
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

std::shared_ptr<ListNode> listFromVector(std::vector<int> vector)
{
    std::shared_ptr<ListNode> result = nullptr;
    std::shared_ptr<ListNode> currentNode = nullptr;
    for (auto i : vector)
    {
        std::shared_ptr<ListNode> newNode;
        if (!result)
        {
            newNode = std::make_shared<ListNode>(i);
            result = newNode;
            currentNode = result;
        }
        else
        {
            newNode = std::make_shared<ListNode>(i);
            currentNode->next = newNode;
            currentNode = newNode;
        }
    }
    return result;
}

std::shared_ptr<ListNode> copyList(std::shared_ptr<ListNode> list)
{
    auto result = std::make_shared<ListNode>(list->val);
    auto currentNode = result;
    auto currentNodeToCopy = list->next;
    while (currentNodeToCopy)
    {
        currentNode->next = std::make_shared<ListNode>(currentNodeToCopy->val);
        currentNode = currentNode->next;
        currentNodeToCopy = currentNodeToCopy->next;
    }
    return result;
}

// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
std::shared_ptr<ListNode> mergeKLists(std::vector<std::shared_ptr<ListNode>>& lists)
{
    if (lists.size() < 2)
    {
        std::stringstream message;
        message << "Not enough ListNodes were provided for merging.";
        throw std::invalid_argument(message.str());
    }
    auto result = copyList(lists[0]);
    std::shared_ptr<ListNode> currentNodeToCopy;
    std::shared_ptr<ListNode> currentSearchNode;
    std::shared_ptr<ListNode> previousSearchNode;
    for (size_t i = 1; i < lists.size(); i++)
    {
        previousSearchNode = nullptr;
        currentSearchNode = result;
        currentNodeToCopy = lists[i];
        while (currentNodeToCopy)
        {
            if (!currentSearchNode)   // At the end of the results lists, add it to the end
            {
                auto newNode = std::make_shared<ListNode>(currentNodeToCopy->val);
                currentNodeToCopy = currentNodeToCopy->next;
                previousSearchNode->next = newNode;
                previousSearchNode = newNode;
            }
            else if (currentNodeToCopy->val <= currentSearchNode->val)
            {
                auto newNode = std::make_shared<ListNode>(currentNodeToCopy->val);
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
