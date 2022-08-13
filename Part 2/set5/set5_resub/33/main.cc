#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    map<string, size_t> histogram;
    string str;                     

    cout << "Enter words: ";        // Prompt user to input

    while (cin >> str)   
    {
        pair<map<string, size_t>::iterator, bool> ret;
        ret = histogram.insert(pair<string, size_t>(str, 1));
        if (!ret.second)           // already in map
            ++ret.first->second;   // increase number
    }           
                  

    cout << '\n';                   // Newline after input
    map<string, size_t>::iterator iter;
    for (iter = histogram.begin(); iter != histogram.cend(); ++iter)
        cout    << setw(15) << "word: " << iter->first 
                << setw(15) << "count: " << iter->second 
                << '\n';
}
