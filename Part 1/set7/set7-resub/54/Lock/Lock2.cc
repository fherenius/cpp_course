#include "Lock.ih"

// JB: PBV?
// FPJ: Fixed -> const PBR
Lock::Lock(std::string const &path, std::string const &lockDir)
{
  std::string lockFile = lockPath(path, lockDir); // Get path to lock file
  d_fileAccess = access(lockFile.c_str(), F_OK);  // Check if lock file exists

  d_fileDescriptor = open( lockFile.c_str() );         // Open lock file
  d_lockSuccess    = flock(d_fileDescriptor, LOCK_EX); // Lock file
}
