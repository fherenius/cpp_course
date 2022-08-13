#include "Lock.ih"

Lock::~Lock()
{
  if (success == 0)
    close(fileDescriptor);
}
