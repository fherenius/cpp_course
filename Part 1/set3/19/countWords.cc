#include "main.ih"

size_t countWords()
{
    size_t wordCount = 0;
    string word;
    
    while (cin >> word)
        ++wordCount;

    return wordCount;
}