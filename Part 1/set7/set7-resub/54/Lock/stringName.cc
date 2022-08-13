#include "Lock.ih"

// JB: Confusing double mention of 'path' in parameter list.
// FPJ: Made all variable names more clear
std::string Lock::stringName(char *(*funName)(char *filePath),
                             std::string const &path) const
{
  char *filePath = const_cast<char *>(path.c_str()); // Cast to non-const c_str
  char *basePath = funName(filePath);                // Retrieve name

  return std::string { basePath };
}
