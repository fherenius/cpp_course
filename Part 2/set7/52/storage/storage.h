#ifndef STORAGECLASS
#define STORAGECLASS

#include <queue>
#include <string>
#include <mutex>

class Storage 
{
  std::queue<std::string> d_queue; // Queue holding strings
  bool d_finished = false;         // Flag indicating work is finished
  mutable std::mutex d_mutex;      // Mutex for locking

  public:
    Storage() = default;
    ~Storage() = default;

    void push(std::string &str); // Insert to back of queue
    void pop();                  // Pop front element of queue
    std::string &front();        // Retrieve front element

    void finished();             // set d_finished to true
    bool empty();                // return true if d_queue is empty
    bool done();                 // check if queue is empty and writing is done
                                 // meaning all work by all threads is done!
};

inline void Storage::push(std::string &str)
{
  std::lock_guard<std::mutex> lg(d_mutex);
  d_queue.push(str);
}

inline void Storage::pop()
{
  std::lock_guard<std::mutex> lg(d_mutex);
  d_queue.pop();
}

inline std::string &Storage::front()
{
  std::lock_guard<std::mutex> lg(d_mutex);
  return d_queue.front();
}

inline void Storage::finished()
{
  d_finished = true;
}

inline bool Storage::empty()
{
  return d_queue.empty();
}

inline bool Storage::done()
{
  return d_finished && empty(); // True if finished and empty
}

#endif // STORAGECLASS
