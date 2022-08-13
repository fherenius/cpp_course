#include "counter.ih"

template <typename Type>
size_t &Counter<Type>::count() const
{
  return s_count; // Return total objects created
}