#include "main.ih"

int main(int argc, char **argv)
{
  // Print usage information if incorrect number of args used
  if (argc != 2)
  {
    usage(argv[0]);  
    return(1);
  }

  std::string filePath = argv[1];    // Get path passed as argument
  Lock        lockFile { filePath }; // Create lock object

  // Open output stream and seek end of stream
  // to append
  std::ofstream out(filePath.c_str(), std::ios_base::out | std::ios_base::app);

  std::string   line;           // Line to append to stream
  std::cout << "? ";            // Prompt for input
  std::getline(std::cin, line); // Store cin into line

  out << line << '\n'; // Write line to file
  
  lockFile.valid();
}
