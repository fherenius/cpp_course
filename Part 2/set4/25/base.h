#ifndef INCLUDED_BASE_H
#define INCLUDED_BASE_H

#include <iostream>

class Base
{
    public:
        void hello(std::ostream &out);
        virtual void vHello(std::ostream &out);
};

inline void Base::hello(std::ostream &out)
{
    vHello(out);            
}

inline void Base::vHello(std::ostream &out)
{
    out << "Hello from base\n";
}

#endif