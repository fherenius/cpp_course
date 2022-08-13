#include "main.ih"
                                        // Function to call combine and print
                                        // result
void boundCall(int argc, char *argv[])
{
  auto [ok, nr, value] = combine(argc, argv);    // Call combine and get struct as 
                                                 // return

                                        // Print struct values to stdout
  std::cout << "Requested argument number: " << nr << '\n'
            << "Value of argument: " << value << '\n';
}
