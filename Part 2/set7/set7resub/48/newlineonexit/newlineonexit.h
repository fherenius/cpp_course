#include <thread>
#include <iosfwd>

// Wrapper class for a thread to neatly print a newline 
// once the thread is joined
class NewlineOnExit 
{
  std::jthread d_thread; // Holds thread

  public:
    NewlineOnExit(std::jthread &&threadObj); // Use move to move thread
    ~NewlineOnExit();                        // Join and print newline
    void stop();                             // Request to stop thread
};

inline NewlineOnExit::NewlineOnExit(std::jthread &&threadObj)
:
  d_thread(std::move(threadObj)) // Move ownership of thread to object
{}

inline void NewlineOnExit::stop()
{
  d_thread.request_stop();       // Ask thread to stop doing work
}