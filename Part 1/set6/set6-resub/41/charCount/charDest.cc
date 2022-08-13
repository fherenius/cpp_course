#include "charCount.ih"

CharCount::~CharCount()
{
    delete[] d_charInfo.charPtr;
}