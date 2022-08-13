#ifndef INCLUDED_DERIVED_H
#define INCLUDED_DERIVED_H

#include "../base/base.h"
#include <iostream>
#include <string>

class Derived: public Base
{
    std::string d_string;

    public:
        Derived(std::string const &str);
    
    private:
        void vHello(std::ostream &out) override;
};

inline Derived::Derived(std::string const &str)
:
    d_string(str)
{}

#endif 
