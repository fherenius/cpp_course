#include "administrator.ih"

bool Administrator::another(std::string &line)
{
  // If notified + empty queue -> work done!
  if ( d_resultQ.empty() )
    return false;

  // Retrieve line from front of queue
  line = d_resultQ.front();
  d_resultQ.pop();

  return true;
}