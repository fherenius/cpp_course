#include "Lock.ih"

// JB: PBV?
// FPJ: Fixed -> const PBR
std::string Lock::lockPath(std::string const &path,
                           std::string const &lockDir) const
{
  std::string lockFile = lockDir + '/' + path + ".lck"; // Concatenate strings
  return lockFile; // Return object
}
