#include "handler.ih"

void callShift(std::ostream &out, std::string const &text)
{
    Handler().shift(out, text);
}