#include "main.ih"

extern char **environ;

int main()
{
  //JB: That is not what sizeof() does. So you didn't test.
  size_t nVariables = sizeof(environ);  // Store amount of variables
  std::string variables[nVariables];    // Initialize string array

                                        // Assign each environ *char
                                        // to array of string
  for (size_t idx = 0; idx != nVariables; ++idx)
      variables[idx] = environ[idx]; //JB: Too low-level. Delegate to a function.

  quicksort(variables, 0, nVariables);  // pass array of string objects
                                        // to quick sort

                                        // print sorted array
  for (size_t idx = 0; idx != nVariables; ++idx)
    std::cout << variables[idx] << '\n';
}
