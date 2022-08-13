#include "start.ih"

//impl
Start::~Start()
{
    if (d_handle)
        d_handle.destroy();
}
//=
