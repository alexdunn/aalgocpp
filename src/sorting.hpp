#include <vector>
#include "gtest/gtest.h"

namespace aalgo
{

// Take an array of ints and return that array sorted from least to greatest. Provably correct algorithm that's reasonably efficient, although there are more efficient sorting algorithms. This is from chapter 1 of the Algorithm Design Manual.  Insertion sort is O(n^2).
std::vector<int> insertionSort(std::vector<int> values);

} // aalgo

