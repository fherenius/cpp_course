#include "main.ih"
                                        // fun to call combine and hold return value
                                        // in locally defined struct
bool structCall(int argc, char *argv[])
{
  ReturnValues ret = combine(argc, argv);// retrieve combine return value
  
  if (ret.ok == true)                    // if status = OK, print values
    std::cout << "Requested argument number: " << ret.nr << '\n'
              << "Value of argument: " << ret.value << '\n';
  else                                  
    usage();                            // otherwise show usage info

  return ret.ok;
}
