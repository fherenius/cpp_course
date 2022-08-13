#include "worker.ih"

Worker::Worker(Semaphores &semaphoreHolder,
               Storage &workQ,
               Storage &resultQ)
: // Initialise all reference data fields
  d_semaphores(semaphoreHolder),
  d_workQ(workQ),
  d_resultQ(resultQ)
{
  d_semaphores.workers.notify(); // Notify that a worker is online
}

/* JB:
   Too many parameters for a constructor of one object, because too many related
   data items that must be handled in the proper order in each member function.
 */
// FPJ: Fixed by encapsulating things a bit more.
