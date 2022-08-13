#include "bistreambuffer.ih"

int BiStreamBuffer::overflow(int c)
{
  if (c != EOF) // Check if c is EOF
  {
    d_firstPtr  << static_cast<char>(c);  // Write char to ostream
    d_secondPtr << static_cast<char>(c);
  }

  return c;
}