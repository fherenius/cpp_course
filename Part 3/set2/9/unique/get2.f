#include "unique.ih"

template <typename Type>
Type &Counter<Type>::get() const
{
  return *d_data.get(); 
};