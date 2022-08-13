#ifndef INCLUDED_VECTORSTRING_H
#define INCLUDED_VECTORSTRING_H

#include <vector>
#include <string>
#include <set>

class VectorString {

    std::vector<std::string> d_words;

    public:
        VectorString(std::multiset<std::string> words);
        
        void swap(VectorString &other);

};

inline VectorString::VectorString(std::multiset<std::string> words)
:
    d_words(words.begin(), words.end())
{}

inline void VectorString::swap(VectorString &other)
{
    std::vector<std::string>(d_words).swap(d_words);
}

#endif