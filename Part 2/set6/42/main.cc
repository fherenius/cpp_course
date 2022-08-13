#include <vector>
#include <iostream>
#include <set>

using namespace std;

size_t multiples(vector<size_t> const &vs)
{
    // A set contains only unique values
    return vs.size() - set<size_t>(vs.begin(), vs.end()).size();
}

int main()
{
    vector<size_t> vs{ 1, 2, 3, 4, 4, 4, 5 };
    cout << multiples(vs) << " multiples were found\n";
}