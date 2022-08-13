#include "charCount.ih"

void CharCount::count(istream &cin)
{
    char ch;
    while(cin.get(ch))               // get character from stdin
    {                                // choose Action according to locate
        (this->*s_actionPtr[locate(ch)])(ch); 
    }
}