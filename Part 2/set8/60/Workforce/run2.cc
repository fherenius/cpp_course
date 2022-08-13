#include "workforce.ih"

void Workforce::run(std::fstream &input, std::fstream &output)
{
  Semaphore jobs{0};    // Queue size
  Semaphore workers{0}; // Available workers
  Semaphore admin{0};   // Available administrators
  Semaphore result{0};  // Results available

  std::mutex workMutex;            // Work mutex
  std::queue<std::string> workQ;   // Queue holding lines to be processed

  std::queue<std::string> resultQ; // Queue holding results

  // Create administrator object and run in detached thread
  Administrator administrator{ admin, result, resultQ, output };
  std::thread{ Administrator::doWork, std::ref(administrator)}.detach();

  // Create two worker objects
  for ( size_t idx = 0; idx != 2; ++idx) 
  {
    // Create worker object and run in detached thread
    Worker worker{ workers, jobs, admin, result, workMutex, workQ, resultQ};
    std::thread{ &Worker::doWork, std::ref(worker)}.detach();
  }

  // Get lines from input, until no new line can be found
  std::string line;
  while ( getline(input, line) )
  {
    // Wait for a worker to become available
    workers.wait();
    {
      // Protect queue access with mutex since there are multiple workers
      std::lock_guard<std::mutex> lg(workMutex);
      workQ.push(line); // Push line to queue
    }

    jobs.notify_all(); // Notify all workers that a job is available
  }
}