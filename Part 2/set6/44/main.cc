#include <memory>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    // std::unique_ptr<char> kaas(new char[10]);
    
    std::unique_ptr<string*[]> melk(new string *[10]);

    // cout << melk[0] << '\n';
    // string **joe = new string*[10];
    // delete[] joe;
}