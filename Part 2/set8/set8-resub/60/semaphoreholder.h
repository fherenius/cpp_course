#ifndef __SEMAPHOREHOLDER_H__
#define __SEMAPHOREHOLDER_H__

#include "Semaphore/semaphore.h"

struct Semaphores
{
  //JB: If all this data is really conceptually one object, and all belongs
  //JB: together, then I'd create in this TU (so in an anonymous namespace) a
  //JB: compound data type for it, just to keep it together. But it's probably
  //JB: a good idea to make it a class to protect data integrity.
  //FPJ: I like that, that really fixed what I was struggling with
  //FPJ: conceptually. It bothered me I had to keep track of so many things.
  //FPJ: I choose to keep it in a separate struct.
  Semaphore jobs{0};    // Queue size
  Semaphore workers{0}; // Available workers
  Semaphore admin{0};   // Available administrators
  Semaphore result{0};  // Results available
};

#endif // __SEMAPHOREHOLDER_H__