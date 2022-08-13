#ifndef ADMINCLASS
#define ADMINCLASS

#include <queue>
#include <string>
#include <fstream>

#include "../semaphoreholder.h"
#include "../storage/storage.h"

class Administrator
{
  Semaphores &d_semaphores;
  Storage &d_resultQ;
  std::fstream &d_output;

  public:
    // Constructor initialising all reference fields
    Administrator(Semaphores &semaphoreHolder,
                  Storage &resultQ,
                  std::fstream &output);
    
    // Static wrapper function calling administrate()
    static void doWork(Administrator &obj);

  private:
    void administrate();             // Function doing the work
};

inline void Administrator::doWork(Administrator &obj)
{
  obj.administrate();
}

#endif // !ADMINCLASS

/* JB:
   It looks like Administrator objects have access to a queue, but never lock
   it. That may cause race conditions if other threads are also concurrently
   accessing the queue.
 */
