#include "administrator.ih"

void Administrator::administrate()
{
  while (true)
  {
    std::string line;
    d_semaphores.result.wait(); // Wait for result to be available

    if (not d_resultQ.another(line))
    {
      d_semaphores.admin.notify_all();
      break;
    }

    d_semaphores.admin.notify_all(); // Notify admin is available

    d_output << line << '\n';
  }
}