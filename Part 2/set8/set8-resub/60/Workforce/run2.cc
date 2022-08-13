//JB: 0
#include "workforce.ih"


void Workforce::run(std::fstream &input, std::fstream &output)
{
  Semaphores semaphoreHolder; // Nice struct to hold all semaphores

  Storage workQ;   // Lockable queue holding lines to be processed
  Storage resultQ; // Locakable queue holding results
  //JB: No lock needed?
  //FPJ: Changed queue to a lockable queue class.

  // Create administrator object and run in detached thread
  Administrator administrator{ semaphoreHolder, resultQ, output };
  std::thread adminThrd = std::thread{&Administrator::doWork, 
                                      std::ref(administrator)};

  Worker worker { semaphoreHolder, workQ, resultQ};    // Create worker object

  std::thread workerThrd1 = std::thread{&Worker::doWork,    // Start worker1
                                    std::ref(worker)}; 
  std::thread workerThrd2 = std::thread{&Worker::doWork,    // Start worker2
                                    std::ref(worker)};     

  // Get lines from input, until no new line can be found
  std::string line;
  while ( getline(input, line) )
  {
    // Wait for a worker to become available
    semaphoreHolder.workers.wait();
    workQ.push(line); // Push line to queue
                      // Storage handles mutex!

    semaphoreHolder.jobs.notify_all(); // Notify all workers that a job 
                                       //is available
  }
  // Give two notifications to jobs, allowing both jobs to exit.
  semaphoreHolder.jobs.notify_all();
  semaphoreHolder.jobs.notify_all();

  adminThrd.join();   // Join all threads
  workerThrd1.join(); // This is chosen over detached threads, otherwise
  workerThrd2.join(); // the objects in this function might be deleted 
                      // before the threads are done.
}
