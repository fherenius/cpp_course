#ifndef INCLUDED_MULTI_H
#define INCLUDED_MULTI_H

#include "deriv1.h"
#include "deriv2.h"
#include <iostream>

class Multi: public Deriv1, public Deriv2
{
    public:
        Multi();
};

inline Multi::Multi()
:
    Basic()
{
    std::cout << static_cast<Basic*>(static_cast<Deriv1 *>(this)) << '\n';
}

#endif // !INCLUDED_MULTI_H