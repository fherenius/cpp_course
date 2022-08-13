#include <iterator>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(int argc, char **argv)
{   
    sort(argv + 1, argv + argc, std::less<string>());
    
    copy(argv + 1, argv + argc, 
        std::ostream_iterator<const char*>(std::cout, " "));
    cout << '\n';

    sort(argv + 1, argv + argc, std::greater<string>());

    copy(argv + 1, argv + argc, 
        std::ostream_iterator<const char*>(std::cout, " "));
    cout << '\n';
}