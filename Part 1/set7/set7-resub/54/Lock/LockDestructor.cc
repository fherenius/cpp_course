#include "Lock.ih"

Lock::~Lock()
{
  if (d_lockSuccess == 0)
    close(d_fileDescriptor);
}
