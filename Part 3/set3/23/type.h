#ifndef __TYPE_H__
#define __TYPE_H__

#include "typeidx.h"

// General template when initially called
template <typename Needle, typename... Haystack> 
class Type
{
  public:
    enum
    { // Set located value based on if the type is found in the
      // haystack or not. TypeIdx will only be called twice from
      // this template.
      located = TypeIdx<Needle, Haystack...>::found
                    ? TypeIdx<Needle, Haystack...>::value
                    : 0
    };
  private:
    template <typename InnerNeedle, typename ...InnerHaystack>
    struct TypeIdx;
};

#endif // __TYPE_H__