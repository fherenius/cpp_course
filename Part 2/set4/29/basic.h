#ifndef INCLUDED_BASIC_H
#define INCLUDED_BASIC_H

#include <iostream>

class Basic
{
    public:
        Basic();
        Basic(int num);
};

inline Basic::Basic()
{
    std::cout << "Basic default constructor\n";
}

inline Basic::Basic(int num)
{
    std::cout << "Basic int constructor: " << num << '\n';
}

#endif