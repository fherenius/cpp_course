#include "storage.ih"

bool Storage::empty()
{
  // Lock here is required, otherwise a thread might see that the queue is not
  // empty while another thread is in the process of removing the last element.
  // Then, the moment it attempts to read from the queue, it's suddenly empty.
  std::lock_guard<std::mutex> lg(d_mutex);
  return d_queue.empty();
}