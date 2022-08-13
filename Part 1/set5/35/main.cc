#include "main.ih"

using namespace std;

int main()
{
    CharCount charCount;
    charCount.count(cin);        // count chars from stdin
    showChar(charCount.info());  // output char count
}