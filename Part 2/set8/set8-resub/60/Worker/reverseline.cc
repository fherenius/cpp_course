#include "worker.ih"

void Worker::reverseLine(std::string &line)
{
  std::reverse(line.begin(), line.end()); // Reverse the line
  d_semaphores.admin.wait(); // Wait for admin to push work
  d_resultQ.push(line); // Push to result queue
  d_semaphores.result.notify(); // Notify result is available
}