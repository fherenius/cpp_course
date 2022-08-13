#include "digit.ih"

Digit::~Digit()
{
    if (d_handle)
        d_handle.destroy();
}
