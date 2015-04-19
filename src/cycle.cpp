#include <iostream>

namespace aalgo
{

int cycle_length(int n)
{
    int length = 1;
    while (n != 1)
    {
        length++;
        if (n % 2)
        {
            n = 3 * n + 1;
        }
        else
        {
            n = n / 2;
        }
    }
    return length;
}

int max_cycle_length(int i, int j)
{
    int max_length = 0;
    for (; i < j; ++i)
    {
        std::cout << i << std::endl;
        int length = cycle_length(i);
        if (length > max_length)
        {
            max_length = length;
        }
    }
    return max_length;
}
} // namespace aalgo
