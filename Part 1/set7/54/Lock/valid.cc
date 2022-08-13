#include "Lock.ih"

bool Lock::valid() const
{
  if (success == 0) // Check if locking was succesful
    return true;
  else 
    return false;
}
