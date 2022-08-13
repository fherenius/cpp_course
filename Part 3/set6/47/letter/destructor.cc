#include "letter.ih"

Letter::~Letter()
{
    if (d_handle)
        d_handle.destroy();
}
