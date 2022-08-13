// JB: 0
#ifndef INCLUDED_LOCK_
#define INCLUDED_LOCK_

#include <iosfwd>

class Lock
{
    // JB: Use prefixes 'd_' for member data.
    // FPJ: Added 'd_' prefix
    int d_fileDescriptor; // Holds filedescriptor of lock file
    int d_lockSuccess;
    int d_fileAccess;

  public:
    Lock(std::string const &path); // 1 - Lock file in same directory
    Lock(std::string const &path,
         std::string const &lockDir); // 2 - Separate directory
    ~Lock();                          // Destructor
    bool valid() const;               // Return if locking was succesfull

  private:
    int open(char const *lockFile) const; // Open lock file, return descriptor
                                          // Convert path to base/dir name
    std::string stringName(char *(*funName)(char *filePath),
                           std::string const &path) const;
                                          // Path of lock file
    std::string lockPath(std::string const &path,
                         std::string const &lockDir) const;
};
#endif

/* JB:
   IMO, there's too much juggling with char*s going on.
   That makes it too unclear where memory might be leaked.

   If you do it because C functions might modify data, then you could consider
   using std::string objects' owned data insofar as the functions you call on
   them don't try to lengthen the string.

   Work with std::strings wherever you can.
 */

/* FPJ:
   I read the string documentation again and am now using the c_str() member
   function where previously I was juggling. A const_cast is also used where
   necessary.
*/
