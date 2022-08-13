#include "Lock.ih"

//JB: Q: why does 'open' needs a parameter 'accessret'?
//JB: That's too C: it requires the user to do bookkeeping that the object
//JB: itself should take care of.

//FPJ: Removed accessret and made it a data member of the class.
//FPJ: I choose for a data member instead of doing it all within open()
//FPJ: this is to make error handling easier if we want to do so in the future
int Lock::open(char const *lockFile) const
{
  int fileDesc;

  if (d_fileAccess == 0)        // If it exists, open file, otherwise create file
    fileDesc = ::open(lockFile, O_RDWR); 
  else                       // S_IRUSR | S_IWUSR comes down to permission mode 0600 
    fileDesc = ::open(lockFile, O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR); 

  return fileDesc;
}
