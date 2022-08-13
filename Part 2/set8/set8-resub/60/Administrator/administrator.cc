#include "administrator.ih"

Administrator::Administrator(Semaphores &semaphoreHolder,
                             Storage &resultQ,
                             std::fstream &output)
:
  d_semaphores(semaphoreHolder),
  d_resultQ(resultQ),
  d_output(output)
{
  d_semaphores.admin.notify_all(); // Notify all waiting worker threads
                                   // that an administrator is online
}
