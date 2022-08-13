#ifndef INCLUDED_HANDLER_H
#define INCLUDED_HANDLER_H

#include <iostream>
#include <algorithm>

class Handler
{
    public:
        void shift(std::ostream &out, std::string const &text);
};

void callShift(std::ostream &out, std::string const &text);

       
#endif // !INCLUDED_HANDLER_H