#include "iterator.h"

template<typename Class, typename BaseIterator, typename Type>
Iterator<Class, BaseIterator, Type>::Iterator(BaseIterator const &current)
:
  d_current(current)
{}