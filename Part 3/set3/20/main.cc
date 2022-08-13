#include <iostream>
#include "merge.h" //JB: include first, for errorchecking.

using namespace std;


int main()
{
    cout << 
        Merge<
            Chars<'1', '2', '3'>, 
            Merge<Chars<'4', '5'>, OneChar<'6'>>::CP
        >::CP{} << '\n';
}

