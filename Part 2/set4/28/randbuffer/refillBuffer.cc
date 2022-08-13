#include "randbuffer.ih"

void RandBuffer::refillBuffer()
{                             // generate random number, convert to string
    string randNum = to_string(
        static_cast<size_t>(d_range * random() / (RAND_MAX + 0.1)));

    d_buffer = randNum + ' '; // add space to signify end of stream;
}