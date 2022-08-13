#include "strings.ih"

Strings::Strings(char **environLike)
{
  while (*environLike)
    d_str.push_back(std::make_unique<std::string>(*environLike++));
}
