//JB: ?
#ifndef INCLUDED_COPYCAT_
#define INCLUDED_COPYCAT_

#include <cstddef>
#include <iosfwd>

extern char **environ;



class CopyCat
{
  size_t d_size;
  char **d_data;

  public:
    CopyCat();                                      // Copies environ
    CopyCat(int argc, char const * const *argv);     // 1 - Copies argc/argv
    CopyCat(char **data);               // 2 - cp. any environ-like var
    void print(std::ostream &out) const;                 // print to stdout
    //JB: I'd rather have an output function that can output to any stream.
    //JB: But -0.
  
  private:
    //JB:                        :-)    :-)
    static size_t nElements(char const *const *input);     // count arr elements
    //JB: But I'd like a space after 'const'.
                                        // copy a single ntbs
    static char **ntbsCopy(char const* const* input, size_t nElements);
    static char *duplicate(char *dest, char const *src); // deep copy array
};

inline CopyCat::CopyCat()               // default constructor
: //JB: :-)
  CopyCat(environ)                      // calls third constructor with environ
{}

#endif
