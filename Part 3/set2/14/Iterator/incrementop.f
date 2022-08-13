#include "iterator.h"

template<typename Class, typename BaseIterator, typename Type>
Iterator<Class, BaseIterator, Type> 
&Iterator<Class, BaseIterator, Type>::operator++()
{
  ++d_current;  // Increment iterator
  return *this; // Return current obj
}