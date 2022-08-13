#include "iterator.h"

template<typename Class, typename BaseIterator, typename Type>
bool Iterator<Class, BaseIterator, Type>::operator<(Iterator const &rhs) const
{
  return **d_current < **rhs.d_current;  
}
