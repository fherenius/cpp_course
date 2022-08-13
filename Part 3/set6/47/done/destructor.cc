#include "done.ih"

Done::~Done()
{
    if (d_handle)
        d_handle.destroy();
}
