#include "storage.ih"

std::string Storage::dequeue()
{
  std::lock_guard<std::mutex> lg(d_mutex); // Request lock
  std::string retStr{ d_queue.front() };   // Copy front into new string
  d_queue.pop();                           // Remove front of queue

  return retStr;                           // Return string previously at front
}