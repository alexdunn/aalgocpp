#include "strings.hpp"

namespace aalgo
{

bool startsWithCapitalLetter(std::string str)
{
    if (str.at(0) > 'A' && str.at(0) < 'Z')
    {
        return true;
    }
    else
    {
        return false;
    }
}

} // namespace aalgo
