#ifndef INCLUDED_DERIV2_H
#define INCLUDED_DERIV2_H

#include "basic.h"
#include <iostream>

class Deriv2: public virtual Basic
{
    public:
        void cast();
};

inline void Deriv2::cast()
{
    std::cout << static_cast<Basic *>(this);
}

#endif
