#include "storage.ih"

void Storage::push(std::string &str)
{
  std::lock_guard<std::mutex> lg(d_mutex);
  d_queue.push(str);
}