#include "sorting.h"

namespace aalgo
{

std::vector<int> insertionSort(std::vector<int> values)
{
    for (size_t i = 1; i < values.size(); ++i)
    {
        int j = i;
        while (j > 0 && values[j] < values[j - 1])
        {
            int higher = values[j - 1];
            values[j - 1] = values[j];
            values[j] = higher;
            j--;
        }
    }
    return values;
}

} // namespace aalgo
