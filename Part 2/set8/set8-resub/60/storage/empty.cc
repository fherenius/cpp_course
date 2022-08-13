#include "storage.ih"

bool Storage::empty()
{
  std::lock_guard<std::mutex> lg(d_mutex);
  return d_queue.empty();
}