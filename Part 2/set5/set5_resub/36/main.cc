#include "vectorString.h"
#include <string>
#include <iostream>
#include <set>
#include <vector>


using namespace std;

int main() {

    string word;
    multiset<string> words;

    while (cin >> word) {
        words.insert(word);
    } 

    vector<string> vecWords{words.begin(), words.end()};

    cout << vecWords.size() << '\n';
    cout << vecWords.capacity() << '\n';

    vecWords.push_back("word");

    cout << vecWords.size() << '\n';
    cout << vecWords.capacity() << '\n';

    vector<string>(vecWords).swap(vecWords);

    cout << vecWords.size() << '\n';
    cout << vecWords.capacity() << '\n';

    VectorString vString{words};
    VectorString(vString).swap(vString);
}