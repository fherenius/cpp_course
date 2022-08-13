#include "worker.ih"

void Worker::task()
{
  while (true)
  {
    // Wait until job becomes available
    d_semaphores.jobs.wait();

    // Try to retrieve next line
    std::string line;
    if (not d_workQ.another(line))
    {
      // Notify boss and results - this allows other threads
      // to also end their work using similar checks.
      d_semaphores.result.notify();
      d_semaphores.workers.notify();
      break; // Break from loop and exit
    }

    // Notify boss that a worker is available again
    d_semaphores.workers.notify();

    // Do work
    reverseLine(line);
  }
} //JB: LONG

/* JB:
   There's a lot of variables that are available in a lot of functions,
   mostly through references. There's little encapsulation. That makes it hard
   to see which resource you're manipulating wrong where.
*/

// FPJ: Encapsulated more, to make it easier to keep track of what's what!
