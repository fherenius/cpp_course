#include "semaphore.ih"

void Semaphore::wait()
{
  std::unique_lock<std::mutex> lg(d_mutex); // Lock
  
  while (d_nAvailable == 0)
    d_condition.wait(lg);   // Block until d_nAvailable is not 0
                            // This releases the lock internally until
                            // a notify from another thread is given

  --d_nAvailable;           // Decrement Semaphore
}