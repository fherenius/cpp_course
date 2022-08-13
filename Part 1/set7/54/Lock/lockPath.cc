#include "Lock.ih"

char *Lock::lockPath(std::string const &path, std::string lockDir) const
{
  std::string lockFile = lockDir + '/' + path + ".lck";

  char *chrPath = new char[lockFile.length() + 1];
  lockFile.copy(chrPath, lockFile.length() + 1);  

  return chrPath;
}
