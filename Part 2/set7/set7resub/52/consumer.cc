#include "main.ih"

void consumer(Storage &storage, std::ofstream &out)
{
  while(!storage.done()) // Keep doing this aslong as there's work to do
  {
    read_write(storage, out); // Read string and write to output
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Sleep for a second
  }
}