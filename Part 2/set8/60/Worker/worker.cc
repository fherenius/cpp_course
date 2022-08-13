#include "worker.ih"

Worker::Worker(Semaphore &boss, Semaphore &job, 
               Semaphore &admin, Semaphore &result,
               std::mutex &workMutex,
               std::queue<std::string> &workQ,
               std::queue<std::string> &resultQ)
: // Initialise all reference data fields
  d_boss(boss),
  d_job(job),
  d_admin(admin),
  d_result(result),
  d_workMutex(workMutex),
  d_workQ(workQ),
  d_resultQ(resultQ)
{
  d_boss.notify(); // Notify that a worker is online
}