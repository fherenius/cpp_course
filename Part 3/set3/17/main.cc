#include <iostream>

#include "nrtrait.h"

using namespace std;


int main()
{
    using trait = NrTrait<1971962>;             // Predefine specific object
                                                // type (could be used
                                                // without).
    cout
        << "Value: " << trait::value << '\n'    // Objects static members can
        << "Even: "  << trait::even  << '\n'    // be accessed through trait.
        << "By 3: "  << trait::by3   << '\n'
        << "Width: " << trait::width << '\n';

}
