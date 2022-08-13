#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    size_t totRandom = stoul(argv[1]);
    size_t endRandom = stoul(argv[2]) + 1;
    size_t lookup = stoul(argv[3]);

    vector<size_t> randomNums(totRandom);

    // Generate random numbers using lambda function
    generate_n(randomNums.begin(), totRandom, 
        [endRandom]{ return rand() % endRandom; });
    
    // copy random numbers to stdout
    copy(randomNums.begin(), randomNums.end(), 
        ostream_iterator<size_t>{ cout, ", " });    

    // Get index of first value exceeding lookup

    size_t index = find_if  (randomNums.begin(), randomNums.end(), 
                                [lookup] (size_t item)  
                                    {
                                        return item > lookup;   
                                    }   // lambda function as unary predicate
                            )           // ensures find if bigger is implemented
        - randomNums.begin();           
    // subtracting with begin as the idx is distance between iterators 
    index < totRandom           
        ? cout << "\nThe first value exceeding:  " << lookup << " is at index: "
            << index << '\n'
        : cout << "\nNo value exceeds " << lookup << '\n';
}