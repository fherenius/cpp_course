#include "quicksort.ih"

string tolower(string str)
{
    string lower;
    for (size_t idx = 0; idx < str.length(); idx++)
        lower.push_back(tolower(str[idx]));
    return lower;
}