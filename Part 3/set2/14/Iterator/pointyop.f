#include "iterator.h"

template<typename Class, typename BaseIterator, typename Type>
Type* Iterator<Class, BaseIterator, Type>::operator->()
{
  return *d_current;  
}