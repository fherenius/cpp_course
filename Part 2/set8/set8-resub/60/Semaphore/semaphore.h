#ifndef INCLUDED_SEMAPHORE
#define INCLUDED_SEMAPHORE

#include <mutex>
#include <condition_variable>

class Semaphore
{
  mutable std::mutex d_mutex;
  std::condition_variable d_condition;
  size_t d_nAvailable;

  public:
    Semaphore(size_t nAvailable); 

    void notify();
    void notify_all();
    void wait();

    size_t size() const;
};

inline Semaphore::Semaphore(size_t nAvailable)
:
  d_nAvailable(nAvailable)
{};

#endif // !INCLUDED_SEMAPHORE

