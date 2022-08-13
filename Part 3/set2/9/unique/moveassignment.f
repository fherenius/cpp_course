#include "unique.ih"

template <typename Type>
Counter<Type> &Counter<Type>::operator=(Counter<Type> &&tmp)
{
  d_data = std::move(tmp.d_data);
  return *this;
}