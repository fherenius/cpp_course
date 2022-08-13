#include "line.ih"
                                    // return next substring containing non-ws
string Line::next()                 // characters from d_line
{                                   
    if (d_startStr == string::npos) // all substrings are processed
        return "";

    string substr;
                                    // get end of substring
    size_t endStr = d_line.find_first_of(wsChars, d_startStr);

    if (endStr == string::npos)     // substring is last string
    {                               // get substring until end of line
        substr = d_line.substr(d_startStr, string::npos);
        d_startStr = endStr;        // start of next substr is npos
    }
    else                            // there are substrings left
    {                               // substring is start to first ws char
        substr = d_line.substr(d_startStr, endStr - d_startStr);
                                    // next substring starts at first 
                                    // non-ws char from endStr
        d_startStr = d_line.find_first_not_of(wsChars, endStr);
    }
        
    return substr;
}