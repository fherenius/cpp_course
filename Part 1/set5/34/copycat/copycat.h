#ifndef INCLUDED_COPYCAT_
#define INCLUDED_COPYCAT_

#include <cstddef>

extern char **environ;



class CopyCat
{
  size_t d_size;
  char **d_data;

  public:
    CopyCat();                          // Copies environ
    CopyCat(int argc, char **argv);     // 1 - Copies argc/argv
    CopyCat(char **data);               // 2 - cp. any environ-like var
    void print() const;                 // print to stdout
  
  private:
    static size_t nElements(char const* const* input);     // count arr elements
                                        // copy a single ntbs
    static char **ntbsCopy(char const* const* input, size_t nElements);
    static char *duplicate(char *dest, char const *src); // deep copy array
};

inline CopyCat::CopyCat()               // default constructor
:
  CopyCat(environ)                      // calls third constructor with environ
{}

#endif
