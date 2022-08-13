#include "semaphore.ih"

void Semaphore::notify_all()
{
  std::lock_guard<std::mutex> lg(d_mutex); // Lock

  if (d_nAvailable++ == 0)
    d_condition.notify_all();              // Return all wait members
}