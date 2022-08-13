#include "object.ih"

Object::~Object()
{
    std::cout << "Destructor called\n";
    delete[] d_arr;
}