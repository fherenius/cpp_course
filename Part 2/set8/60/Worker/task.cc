#include "worker.ih"

void Worker::task()
{
  while (true)
  {
    // Wait until job becomes available
    d_job.wait();

    // Try to retrieve next line
    std::string line;
    if (not another(line))
    {
      // Notify boss and results - this allows other threads
      // to also end their work using similar checks.
      d_result.notify();
      d_boss.notify();
      break; // Break from loop and exit
    }

    // Notify boss that a worker is available again
    d_boss.notify();

    // Do work
    std::reverse(line.begin(), line.end());
    d_admin.wait(); // Wait for admin to push work

    d_resultQ.push(line); // Push to result queue

    d_result.notify(); // Notify result is available
  }
}