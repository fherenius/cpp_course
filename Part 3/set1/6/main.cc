    #include <iostream>
    #include "exception/exception.h"

    using namespace std;

    int main(int argc, char **argv)
    try
    {
      throw Exception{} << "insert anything that's "
            "ostream-insertable: " << "strings"s << ", values " <<
            argc << " etc., etc.";
    }
    catch (exception const &ex)
    {
      cout << ex.what() << '\n';
    }
      
