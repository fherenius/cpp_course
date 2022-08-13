#include "main.ih"

using namespace std;

int main()
{
    CharCount charCount;
    charCount.count(cin);        // count chars from stdin

    CharCount::CharInfo const info = charCount.info();
    for (size_t idx = 0; idx != info.nCharObj; ++idx)
        showChar(info.charPtr[idx]);
}