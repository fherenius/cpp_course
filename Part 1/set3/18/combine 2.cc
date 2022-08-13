#include "main.ih"
                                        // Member function definition
void ReturnValues::assignValues(int argc, char *argv[]) 
{
  nr = std::stoul(argv[1]);             // first arg after prog name is
                                        // requested arg

  ok = false;                           // default value = false
  
  if (size_t end = argc + 1, begin = 0; 
      nr > begin && nr < end)// check if requested arg exists
  {
    ok = true;                          // exists = OK
    value = argv[nr - 1];               // set value
  }
};                                      

                                        // function to combine and return struct
struct ReturnValues combine(int argc, char *argv[])
{
  ReturnValues retVal;                  // initialise struct

  retVal.assignValues(argc,argv);       // call member function to assing values

  return retVal;                        // return struct
}
