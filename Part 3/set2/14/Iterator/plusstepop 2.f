#include "iterator.h"

template<typename Class, typename BaseIterator, typename Type>
Iterator<Class, BaseIterator, Type> 
Iterator<Class, BaseIterator, Type>::operator+(int step) const
{
  return Iterator(d_current + step);
}