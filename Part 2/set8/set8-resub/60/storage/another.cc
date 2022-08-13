#include "storage.ih"

bool Storage::another(std::string &line)
{
  // Lock access to queue
  std::lock_guard<std::mutex> lg(d_mutex);

  // If notified and queue empty -> work done
  if ( d_queue.empty() )
    return false;

  // Retrieve front of queue
  line = d_queue.front();
  d_queue.pop();

  return true;
}