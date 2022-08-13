#include "main.ih"

size_t countLines()
{
  size_t lineCount = 0;                     // Int to store line count 
  std::string input = readLines();          // Read input

  for (std::string::iterator it = input.begin();
       it != input.end(); ++it)
  {
    if (*it == '\n')
      lineCount += 1;
  }

  return(lineCount);                        // Return count
} 
