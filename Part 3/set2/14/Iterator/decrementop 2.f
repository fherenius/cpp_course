#include "iterator.h"

template <typename Class, typename BaseIterator, typename Type>
Iterator<Class, BaseIterator, Type> 
&Iterator<Class, BaseIterator, Type>::operator--()
{
  --d_current;  // Decrement
  return *this; // Return curr obj
}