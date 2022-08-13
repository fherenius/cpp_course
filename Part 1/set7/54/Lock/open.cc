#include "Lock.ih"

int Lock::open(char *lockFile, int accessRet) const
{
  int fileDesc;

  if (accessRet == 0)        // If it exists, open file, otherwise create file
    fileDesc = ::open(lockFile, O_RDWR); 
  else                       // S_IRUSR | S_IWUSR comes down to permission mode 0600 
    fileDesc = ::open(lockFile, O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR); 

  return fileDesc;
}
