#ifndef INCLUDED_RANDBUFFER_H
#define INCLUDED_RANDBUFFER_H

#include <streambuf>

class RandBuffer: public std::streambuf
{
    int d_min;
    int d_range;
    int d_end;
    std::string d_buffer;
    
    public:
        RandBuffer(int min, int max, size_t seed);

    private:
        int underflow();
        void refillBuffer();
};

#endif