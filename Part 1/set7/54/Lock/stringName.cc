#include "Lock.ih"

std::string Lock::stringName(char *(*name)(char *path), std::string const &path) const
{
  char *filePath = new char[path.length() + 1]; // Init empty chr array
  path.copy(filePath, path.length() + 1);       // + 1 since its an NTBS

  char *basePath = name(filePath);

  delete[] filePath; // Delete filePath but still there's a small leak
  return std::string{ basePath };  
}

