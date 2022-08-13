#include "Lock.ih"

bool Lock::valid() const
{
  //JB: Already bool.
  //FPJ: Fixed with single statement
  return d_lockSuccess == 0;
}
