#include "administrator.ih"

void Administrator::administrate()
{
  while (true)
  {
    std::string line;
    d_result.wait();

    if (not another(line))
    {
      d_admin.notify_all();
      break;
    }

    d_admin.notify_all();

    d_output << line << '\n';
  }
}