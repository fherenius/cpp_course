#include "derived.ih"

void Derived::vHello(std::ostream &out)
{
    out << d_string;
}