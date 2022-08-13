#include "countholder.h"

size_t &Countholder::count() const
{
  return s_count; // Return total objects created
}