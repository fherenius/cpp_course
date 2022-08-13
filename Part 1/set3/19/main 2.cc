#include "main.ih"

int main(int argc, char *argv[])
{
  char option = getOption(argc, argv);  // Init char to hold passed option
  size_t output;                   // Init int to hold count


  switch (option)                       // switch to decide case
  {
    case 'w':
      output = countWords();       // count words in input
      break;
    case 'c':
      output = countChars();      // count chrs in input
      break;
    case 'l':
      output = countLines();      // count lines in input
      break;
    default:
      usage();
      return(0);
  }
 
  std::cout << "Counted: " << output << '\n'; // Print counted
}
