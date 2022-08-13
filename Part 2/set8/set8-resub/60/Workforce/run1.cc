#include "workforce.ih"

//JB: By value?
//FPJ: Silly of me, should be by reference of course
void Workforce::run(std::string &input, std::string &output)
{
  // Convert filenames to input and output file streams
  std::fstream instream(input, std::ios::in);
  std::fstream outstream(output, std::ios::out | std::ios::trunc);

  //JB: Yes, delegate :-)
  run(instream, outstream); // Call run function doing actual work with streams

  instream.close();         // Close streams once work is done!
  outstream.close();
}
