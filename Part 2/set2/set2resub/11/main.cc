#include <iostream>
#include "object.h"

using namespace std;

int main() 
try
{
    Object obj("object");
    obj.throwException();
    
    //obj.rethrow();
}
catch(Object obj)
{
    cerr << "Exception throws obj: " << obj.name() << '\n';
}
