#include <vector>
#include <numeric>
#include <iostream>
#include "unsignedIota.h"

using namespace std;

int main()
{
    vector<unsigned> numbers(10);

    iota(numbers.begin(), numbers.end(), unsigned_iota(2, 0));

    for (auto number: numbers)
        cout << number << '\n';
}