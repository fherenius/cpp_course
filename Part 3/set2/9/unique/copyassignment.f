#include "unique.ih"

template <typename Type>
Counter<Type> &Counter<Type>::operator=(Counter<Type> const &other)
{
  Counter<Type> tmp(other); // Copy construct tmp obj
  tmp.d_data.swap(d_data); // Use unique ptr swap to swap ownership
  return *this; // Return this obj
};