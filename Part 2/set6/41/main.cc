#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{   
    sort(argv + 1, argv + argc, 
        [](auto l, auto r){ return std::stoi(l) < std::stoi(r); });
    
    copy(argv + 1, argv + argc, 
        std::ostream_iterator<const char*>(std::cout, " "));
    cout << '\n';

    sort(argv + 1, argv + argc, 
        [](auto l, auto r){ return std::stoi(l) > std::stoi(r); } );

    copy(argv + 1, argv + argc, 
        std::ostream_iterator<const char*>(std::cout, " "));
    cout << '\n';
}