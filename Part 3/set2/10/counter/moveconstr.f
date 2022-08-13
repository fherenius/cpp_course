#include "counter.ih"

template <typename Type>
inline Counter<Type>::Counter(Counter<Type> &&tmp)
:
  d_data(std::move(tmp.d_data))
{}
