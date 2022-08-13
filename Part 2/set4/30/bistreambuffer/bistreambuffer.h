#ifndef BISTREAMBUFFER_H
#define BISTREAMBUFFER_H

#include <streambuf>
#include <ostream>

// Inherit streambuf as public since BiStreamBuffer should act as streambuf
class BiStreamBuffer: public std::streambuf
{
  std::ostream &d_firstPtr;  // Init pointers to original ostreams to write to
  std::ostream &d_secondPtr;

  public:
    BiStreamBuffer(std::ostream &first, std::ostream &second); // Constructor

  private:
    int overflow(int c) override;   // Override overflow to write to ostreams
};

inline BiStreamBuffer::BiStreamBuffer(std::ostream &first, std::ostream &second)
  :
  d_firstPtr(first),  // Set pointers to ostream
  d_secondPtr(second)
{}
#endif //BISTREAMBUFFER_H
