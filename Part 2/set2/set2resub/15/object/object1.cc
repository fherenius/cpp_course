#include "object.ih"

Object::Object()
:
    d_arr(new size_t[1])
{
    std::cout << "Constructor called\n";
}