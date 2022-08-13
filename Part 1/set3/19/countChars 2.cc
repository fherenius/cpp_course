#include "main.ih"

size_t countChars()
{
  std::string input = readLines();      // Read input
  size_t charCount = 0;                 // Int to contain char count

                                        // it over all chars
  for (std::string::iterator it = input.begin();
       it != input.end(); ++it)
    charCount += 1;                     // increase charCount

                                        // Output chr count
  return(charCount);
}
