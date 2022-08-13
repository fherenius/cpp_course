#ifndef INCLUDED_LINE_                    
#define INCLUDED_LINE_

#include <string>
#include <iostream>

using namespace std;

class Line
{
    string d_line;
    size_t d_startStr;
    string static wsChars;

    public:                // member functions
        bool getLine();
        string next();

        string const &line() const; // returns d_line
};

#endif
