#include "consumer.ih"

void Consumer::consume()
{
  while(!d_storage.done()) // Keep doing this aslong as there's work to do
  {
    read_write(); // Read string and write to output
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Sleep for a second
  }
}