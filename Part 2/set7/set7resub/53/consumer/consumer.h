#ifndef CONSUMERCLASS
#define CONSUMERCLASS

#include <fstream>
#include <iosfwd>  // String declaration

class Storage; // Declaration only

class Consumer
{
  size_t d_size = 0;
  Storage &d_storage;
  std::ofstream d_out;

  public:
    Consumer(Storage &storage, std::string filename); // constructor
    size_t size();  // Returning amount of lines processed
    void consume(); // Do the actual consumption work

  private:
    void read_write(); // Read line from storage, write to output
};

inline size_t Consumer::size()
{
  return d_size;
}

#endif // !CONSUMERCLASS