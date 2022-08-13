#include "randbuffer.ih"

int RandBuffer::underflow()
{
    refillBuffer();

    setg(&d_buffer[0], &d_buffer[0], &d_buffer[d_buffer.length()]);
    
    return static_cast<unsigned char>(*gptr());
}
