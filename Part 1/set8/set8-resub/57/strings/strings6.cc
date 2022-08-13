#include "strings.ih"

Strings::Strings(Strings &&tmp)
{
  swap(tmp);
}
