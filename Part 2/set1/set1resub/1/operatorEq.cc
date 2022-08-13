#include "numbers.ih"

bool operator==(Numbers const &lhs, Numbers const &rhs)
{
    if (lhs.size() != rhs.size())       
        return false;                  // size of lhs is not equal to rhs
    
    for (size_t idx = 0; idx < lhs.size(); ++idx)
    {
        if (lhs[idx] != rhs[idx])
            return false;              // an element of lhs is not equal to rhs
    }

    return true;                        // all elements are equal
}