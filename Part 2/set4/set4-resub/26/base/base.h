#ifndef INCLUDED_BASE_H
#define INCLUDED_BASE_H

#include <iostream>

class Base
{
    public:
        void hello(std::ostream &out);
        virtual ~Base();        // empty destructor

    private:
        virtual void vHello(std::ostream &out);
};

inline void Base::hello(std::ostream &out)
{
    vHello(out);
}

#endif
