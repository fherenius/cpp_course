#include "counter.ih"

template <typename Type>
Counter<Type>::Counter(Counter<Type> const &other)
:
  d_data(new Type(*other.d_data)) // Deep copy d_data from other 
{};
