#include "storage.ih"

std::string &Storage::front()
{
  std::lock_guard<std::mutex> lg(d_mutex);
  return d_queue.front();
}