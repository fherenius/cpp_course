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
    std::string dequeue();       // Front & pop with one mutex

    void finished();             // set d_finished to true
    bool empty();                // return true if d_queue is empty
    bool done();                 // check if queue is empty and writing is done
                                 // meaning all work by all threads is done!
};

#endif // STORAGECLASS
