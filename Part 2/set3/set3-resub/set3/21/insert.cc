#include "string.ih"

String &String::insert(std::string const &text)
{
    string::insert(0, text);
    return *this;
}