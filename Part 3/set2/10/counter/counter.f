#include "counter.ih"

template <typename Type>
Counter<Type>::Counter(Type data)
:
  d_data(std::make_unique<Type>(data)) // Create unique ptr from data
{
  ++s_count; // Increment count and actual
  ++s_actual;
};
