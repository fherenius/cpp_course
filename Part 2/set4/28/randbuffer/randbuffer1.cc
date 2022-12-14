#include "randbuffer.ih"

RandBuffer::RandBuffer(int min, int max, size_t seed)
:
    d_min(min),
    d_range(max - min + 1),
    d_end(RAND_MAX - RAND_MAX % d_range) // d_end is multiple of d_range
{
    if (max <= min)
        throw range_error{" min. value must be smaller than max. value"};

    srandom(seed);
    setg(0, 0, 0);              // initially no buffer
}