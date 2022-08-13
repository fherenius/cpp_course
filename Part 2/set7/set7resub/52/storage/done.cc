#include "storage.ih"

bool Storage::done()
{
  return d_finished && empty(); // True if finished and empty
}