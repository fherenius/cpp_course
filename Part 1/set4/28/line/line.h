#ifndef INCLUDED_LINE_                    
#define INCLUDED_LINE_

#include "line.ih"

class Line
{
    string d_line;
    size_t d_startStr;
    string static const wsChars;

    public:                // member functions
        bool getLine();
        string next();
};

#endif