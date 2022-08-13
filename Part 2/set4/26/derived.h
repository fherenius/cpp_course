#include <iostream>
#include <string>
#include "base.h"

class Derived: public Base
{
    std::string d_string;

    public:
        Derived();
        Derived(std::string str);
        void vHello(std::ostream &out) override;
};

inline Derived::Derived()
:
    d_string("hello from Derived")
{}

inline Derived::Derived(std::string str)
:
    d_string(str)
{}

inline void Derived::vHello(std::ostream &out)
{
    out << d_string;
}

Base **derivedFactory(size_t size);
