#include "counter.ih"

template <typename Type>
Counter<Type>::Counter(Type *data)
:
  d_data(data) // Assign ptr to unique ptr
{
  ++s_count; // Increment counter and actual
  ++s_actual;
};
