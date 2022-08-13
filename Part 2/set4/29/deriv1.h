#ifndef INCLUDED_DERIV1_H
#define INCLUDED_DERIV1_H

#include "basic.h"

class Deriv1: public virtual Basic
{
    public:
        Deriv1();
};

inline Deriv1::Deriv1()
:
    Basic(10)      // call int constructor
{}
#endif
