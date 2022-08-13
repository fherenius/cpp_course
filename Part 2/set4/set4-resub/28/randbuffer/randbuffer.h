#ifndef INCLUDED_RANDBUFFER_H
#define INCLUDED_RANDBUFFER_H

#include <streambuf>

class RandBuffer: public std::streambuf
{
    int d_min;
    int d_range;
    int d_end;
    std::string d_buffer; // A string is chosen as buffer as it allows for
                          // easier memory management and manipulation than 
                          // a char *
    
    public:
        RandBuffer(int min, int max, size_t seed);

    private:
        int underflow() override;
        void refillBuffer(); 
};

#endif
