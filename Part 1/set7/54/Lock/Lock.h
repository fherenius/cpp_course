#ifndef INCLUDED_LOCK_
#define INCLUDED_LOCK_

#include <iosfwd>

class Lock
{
  int fileDescriptor; // Holds filedescriptor of lock file
  int success;

  public:
    Lock(std::string const &path); // 1 - Lock file in same directory                     
    Lock(std::string const &path, std::string lockDir); // 2 - Separate directory
    ~Lock(); // Destructor
    bool valid() const; // Return if locking was succesfull

  private:
    int open(char *lockFile, int accessRet) const; // Open lock file, return descriptor
                                                   // Convert path to base/dir name
    std::string stringName(char *(*name)(char *path), std::string const &path) const; 
                                                   // Path of lock file
    char *lockPath(std::string const &path, std::string lockDir) const;
};
#endif
