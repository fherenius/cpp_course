#include <chrono>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    auto hours = chrono::hours{ stoul(argv[1]) };
    
    // Integer scale conversion without precision loss: no cast needed
    chrono::minutes minutes = hours; 
    chrono::seconds seconds = hours;

    cout << hours.count() << " hours is " << minutes.count() << 
        " minutes or " << seconds.count() << " seconds\n";

    seconds = chrono::seconds{ stoul(argv[2]) };

    // Integer scale conversion with precision loss: cast needed
    minutes = chrono::duration_cast<chrono::minutes>(seconds); 
    hours = chrono::duration_cast<chrono::hours>(seconds); 

    cout << seconds.count() << " seconds is " << minutes.count() << 
        " minutes or " << hours.count() << " hours\n";
}
