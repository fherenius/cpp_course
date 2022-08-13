#include <iostream>
#include <set>

using namespace std;

int main()
{
  set<size_t> const universe = { 1, 2, 3, 4};
  set<set<size_t>> const subsets =
  {
    { 1, 2,      },
    {       3, 4 },
  };

  cout << "Universe: " << universe << '\n'
       << "subsets: "  << subsets << '\n';  // WC: no operator<<
                      // desired output: Universe: {1, 2, 3, 4}
                      //                 subsets: {{1, 2}, {3, 4}}
}