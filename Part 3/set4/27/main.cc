#include <iostream>
#include <string>
#include "data.h"
#include <vector>

using namespace std;

int main()
{
    
    Data data;
    data.push_back("hello world");
    data.push_back("some string"s);
    data.push_back("1.324234");

    cout << data.get<string>(0) << '\n';
    cout << data.get<int>(1) << '\n';
    cout << data.get<double>(2) << '\n';
    
}
