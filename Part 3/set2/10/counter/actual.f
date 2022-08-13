#include "counter.ih"

template <typename Type>
size_t &Counter<Type>::actual() const
{
  return s_actual; // Return current available objects
}