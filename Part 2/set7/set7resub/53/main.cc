#include "main.ih"

int main(int argc, char **argv)
{
  Storage queue;    // Init queue object
  
  --argc; // Skip the program argument in argc/argv
  ++argv;

  std::vector<Consumer> consumerVec; // Vector holding consumer obj's.
  fillObjectVector(consumerVec, queue, argc, argv); // Fill with consumers

  std::vector<std::thread> consumerThreads; // Vector for threads
  startThreads(consumerThreads, consumerVec); // Start all threads

  std::string line; // String to hold line
                    // Keep getting lines from cin and push to queue
  while (std::getline(std::cin, line))
    queue.push(line);

  queue.finished(); // Set the 'queue' finished flag, indicating we're
                    // done adding lines!

  joinThreads(consumerThreads); // Join all consumer threads
  printSizes(consumerVec); // Print processed lines per worker thread
}