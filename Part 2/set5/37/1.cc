#include "privilegedone.h"
#include <fstream>
#include <iostream>

PrivilegedOne::PrivilegedOne(std::string const &fname)
{
    std::ifstream in{ fname };

    while (true)
    {
        NoEntry next = nextEntry(in); 

        if (next.name().empty())
            break;
        

        d_noEntry.push_back(std::unique_ptr<NoEntry>(new NoEntry(next)));

    }
}