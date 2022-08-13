#ifndef WORKERCLASS
#define WORKERCLASS

#include <queue>
#include <string>
#include <iosfwd>
#include <mutex>

#include "../semaphoreholder.h"
#include "../storage/storage.h"

class Semaphore; // Declaration only

class Worker
{
  Semaphores &d_semaphores; // Holds a reference to a struct with all semaphore
  Storage &d_workQ;         // Lockable queue work queue
  Storage &d_resultQ;       // Lockable result queue

  public:
    Worker(Semaphores &semaphoreHolder,
           Storage &workQ,
           Storage &resultQ); 
    // Wrapper function calling task to do the actual work
    static void doWork(Worker &obj);

  private:
    void task();                         // Function doing actual work
    void reverseLine(std::string &line); // Perform work on retrieved line
};

inline void Worker::doWork(Worker &obj)
{
  obj.task();
}

#endif // !WORKERCLASS
