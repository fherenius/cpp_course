#include "semaphore.ih"

void Semaphore::notify()
{
  std::lock_guard<std::mutex> lg(d_mutex); // Lock

  if (d_nAvailable++ == 0)
    d_condition.notify_one();              // Return a single wait member
}