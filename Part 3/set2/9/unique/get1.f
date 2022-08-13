#include "unique.ih"

template <typename Type>
Type &Counter<Type>::get()
{
  return *d_data.get(); // Return reference to object
};