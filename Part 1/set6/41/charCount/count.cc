#include "charCount.ih"

void CharCount::count(istream &cin)
{
    void (CharCount::*fp[])(char ch) = 
    {
        &CharCount::append,
        &CharCount::increment,
        &CharCount::insert
    };

    char ch;
    while(cin.get(ch))               // get character from stdin
    {
        (this->*fp[locate(ch)])(ch); // choose Action according to locate
    }
}