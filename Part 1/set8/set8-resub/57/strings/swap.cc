#include "strings.ih"

void Strings::swap(Strings &other)
{
  char buffer[sizeof(Strings)]; // Initialise buffer
  memcpy(buffer, &other, sizeof(Strings)); // Copy other into buffer
                                // cpy cur object into other
  memcpy(static_cast<void *>(&other), this, sizeof(Strings)); 
                                // cpy buffer into curr object
  memcpy(static_cast<void *>(this), buffer, sizeof(Strings));
}
