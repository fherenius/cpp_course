#include "Lock.ih"

Lock::Lock(std::string const &path)
:
  Lock(stringName(basename, path), stringName(dirname, path)) // Call second constructor
{
}
