#include "administrator.ih"

Administrator::Administrator(Semaphore &admin, Semaphore &result,
                             std::queue<std::string> &resultQ,
                             std::fstream &output)
:
  d_admin(admin),
  d_result(result),
  d_resultQ(resultQ),
  d_output(output)
{
  d_admin.notify_all(); // Notify all waiting worker threads
                        // that an administrator is online
}
