#include "iterator.h"

template <typename Class, typename BaseIterator, typename Type>
bool Iterator<Class, BaseIterator, Type>::operator==(
    Iterator const &other) const
{
  return d_current == other.d_current;
}