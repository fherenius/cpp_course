#include "line.ih"

bool Line::getLine()
{
    getline(cin, d_line);                           // get line from input

    size_t pos = d_line.find_first_of(wsChars);     // check for ws chars
    
    d_startStr = d_line.find_first_not_of(wsChars); // first non-ws char to
                                                    // get substring
                                                    
                                                    // return if whitespace
    return pos == string::npos;                     // chars are found
}