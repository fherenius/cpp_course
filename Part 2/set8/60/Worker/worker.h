#ifndef WORKERCLASS
#define WORKERCLASS

#include <queue>
#include <string>
#include <iosfwd>
#include <mutex>

class Semaphore; // Declaration only

class Worker
{
  // All reference fields to keep track of semaphores and queues
  Semaphore &d_boss;
  Semaphore &d_job; 
  Semaphore &d_admin;
  Semaphore &d_result;
  std::mutex &d_workMutex;
  std::queue<std::string> &d_workQ;
  std::queue<std::string> &d_resultQ;

  public:
    Worker(Semaphore &boss, Semaphore &job, 
           Semaphore &admin, Semaphore &result,
           std::mutex &workMutex,
           std::queue<std::string> &workQ,
           std::queue<std::string> &resultQ);
    // Wrapper function calling task to do the actual work
    static void doWork(Worker &obj);

  private:
    void task();                     // Function doing actual work
    bool another(std::string &line); // Retrieve another line from queue
};

inline void Worker::doWork(Worker &obj)
{
  obj.task();
}

#endif // !WORKERCLASS
