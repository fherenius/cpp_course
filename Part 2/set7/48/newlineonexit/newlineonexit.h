#include <thread>
#include <iostream>

class NewlineOnExit
{
  std::jthread d_thread;

  public:
    NewlineOnExit(std::jthread &&threadObj);
    ~NewlineOnExit();
    void stop();
};

inline NewlineOnExit::NewlineOnExit(std::jthread &&threadObj)
:
  d_thread(std::move(threadObj))
{}

inline NewlineOnExit::~NewlineOnExit()
{
  if (d_thread.joinable())
  {
    d_thread.join();
    std::cout << '\n';
  }
}

inline void NewlineOnExit::stop()
{
  d_thread.request_stop();
}