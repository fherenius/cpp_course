#include "main.ih"

size_t countChars()         // including whitespace/escape ch?
{
    size_t charCount = 0;
    char ch;
    
    while (cin >> ch)
        ++charCount;

    return charCount;
}