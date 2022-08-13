#include "copycat.ih"

char *CopyCat::duplicate(char *dest, char const *src)
{
    size_t str_len = strlen(src);
    dest = new char[str_len];   // allocate memory to copy src
    dest = strcpy(dest, src);
    return dest;
}