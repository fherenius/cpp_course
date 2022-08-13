#ifndef BISTREAM_H
#define BISTREAM_H

#include <ostream>
#include "../bistreambuffer/bistreambuffer.h"

// Privately inherit biStreamBuffer (Since BiStream is not a buffer)
// Publicly inherit ostream since BiStream should act as an ostream
class BiStream: private BiStreamBuffer, public std::ostream
{
  public:
    BiStream(std::ostream &first, std::ostream &second); // Bistream constructor
};

inline BiStream::BiStream(std::ostream &first, std::ostream &second)
:
  BiStreamBuffer(first, second), // Pass inputs to buffer class
  std::ostream(this)         // Receives &BiStreamBuffer
{}

#endif //BISTREAM_H
