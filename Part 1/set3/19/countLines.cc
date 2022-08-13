#include "main.ih"

size_t countLines()
{
    size_t lineCount = 0;
    string line;

    while (getline(cin, line))
        ++lineCount;

    return lineCount;
}