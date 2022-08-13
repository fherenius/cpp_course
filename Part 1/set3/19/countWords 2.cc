#include "main.ih"

size_t countWords()
{
  std::string input = readLines();      // Read input
  size_t wordCount = 0;                 // int to hold word count

  bool isSpace = true;                  // bool holding info if last checked
                                        // char is a space or not

                                        // it over all chars
  for (std::string::iterator it = input.begin();
       it != input.end(); ++it)
  {
    if (isspace(*it))                   // check if chr is space/newline 
      isSpace = true;                   // chr = space
    else if (isSpace)
    {
      wordCount++;                      // increase word count if chr is
      isSpace = false;                  // space and set isSpace to false
    }
  }

                                        // return wordcount to std output
  return(wordCount);
}
