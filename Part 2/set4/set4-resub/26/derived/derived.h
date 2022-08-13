#ifndef INCLUDED_DERIVED_H
#define INCLUDED_DERIVED_H

#include "../base/base.h"
#include <iostream>
#include <string>

class Derived: public Base
{
    std::string d_string;

    public:
        Derived();

    private:
        void vHello(std::ostream &out) override;

};

inline Derived::Derived()
:
    d_string("hello from Derived")
{}


Base **derivedFactory(size_t size);

#endif
