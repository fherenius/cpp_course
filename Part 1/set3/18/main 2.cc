#include "main.ih"

int main(int argc, char *argv[])
{
  if (argc == 1)                        // print usage if no args given by usr
  {
    usage();
    return(0);
  }	  

  bool status = structCall(argc, argv); // get status if requested arg exists
  if (status) boundCall(argc, argv);    // call boundCall if requested arg exist
}
