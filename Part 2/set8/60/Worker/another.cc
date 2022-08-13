#include "worker.ih"

bool Worker::another(std::string &line)
{
  // Lock access due to multiple worker threads
  std::lock_guard<std::mutex> lg(d_workMutex);

  // If notified and queue empty -> work done
  if ( d_workQ.empty() )
    return false;

  // Retrieve front of queue
  line = d_workQ.front();
  d_workQ.pop();

  return true;
}