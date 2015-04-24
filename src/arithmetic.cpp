#include <stdexcept>
#include <sstream>
#include <cmath>
#include "arithmetic.hpp"

namespace aalgo
{

unsigned numberOfDigits(unsigned a)
{
    int digitsCount = 0;
    while (a)
    {
        a /= 10;
        ++digitsCount;
    }
    return digitsCount ? digitsCount : 1;
}

unsigned digitAt(unsigned a, unsigned i)
{
    unsigned size = numberOfDigits(a);
    if (size < i)
    {
        std::stringstream message;
        message << "You can't ask for a digit that doesn't exist.  " << a << " has only " << size << " digits, but you asked for the digit at position " << i << ".";
        throw std::invalid_argument(message.str());
    }

    return static_cast<int>(a / pow(10, i - 1)) % 10;
}

unsigned carryOpertions(unsigned a, unsigned b)
{
    int carriesCount = 0;
    bool currentCarry = false;

    int aSize = numberOfDigits(a);
    int bSize = numberOfDigits(b);
    int smallerSize = aSize > bSize ? bSize : aSize;

    for (int i = 1; i <= smallerSize; ++i)
    {
        unsigned aDigit = digitAt(a, i);
        unsigned bDigit = digitAt(b, i);
        unsigned sum = aDigit + bDigit;
        if (currentCarry)
        {
            ++sum;
            currentCarry = false;
        }
        if (sum >= 10)
        {
            currentCarry = true;
            ++carriesCount;
        }
    }
    return carriesCount;
}

} // namespace aalgo
