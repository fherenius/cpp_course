#include "storage.h"
#include "../RndIterator/rnditerator.ch"

#include <concepts>

inline bool operator==(RndIterator auto const &lhs, RndIterator auto const &rhs)
{
  return lhs.d_current == rhs.d_current;
}

inline auto operator<=>(RndIterator auto const &lhs, RndIterator auto const &rhs)
{
  return lhs.d_current <=> rhs.d_current;
}

inline int operator-(RndIterator auto const &lhs, RndIterator auto const &rhs)
{
  return lhs.d_current - rhs.d_current;
}

inline auto operator+(RndIterator auto const &lhs, int step)
{
  // lhs.d_current += step; // avoids ambiguity
  return lhs;
}

inline auto operator-(RndIterator auto const &lhs, int step)
{
  lhs.d_current -= step; // avoids ambiguity
  return lhs;
}