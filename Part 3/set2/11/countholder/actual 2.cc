#include "countholder.h"

size_t &Countholder::actual() const
{
  return s_actual; // Return current available objects
}