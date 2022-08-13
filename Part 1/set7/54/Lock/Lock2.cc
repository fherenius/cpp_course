#include "Lock.ih"

Lock::Lock(std::string const &path, std::string lockDir)
{
  char *lockFile = lockPath(path, lockDir); // Get path to lock file

  int accessRet = access(lockFile, F_OK); // Check if lock file exists
  
  fileDescriptor = open(lockFile, accessRet); // Open lock file

  delete[] lockFile; // Clear dynamically allocated memory from lockPath;

  success = flock(fileDescriptor, LOCK_EX); // Lock file
}
