#include "main.ih"

int main()
{
  Storage queue;    // Init queue object
  std::string line; // String to hold line

  std::ofstream out("scratch");

                    // Start consumer thread, pass queue as reference
  std::thread consumerThread{ consumer, std::ref(queue), std::ref(out) };

                    // Keep getting lines from cin and push to queue
  while (std::getline(std::cin, line))
    queue.push(line);

  queue.finished(); // Set the 'queue' finished flag, indicating we're
                    // done adding lines!
  consumerThread.join(); // Join with consumer thread
}