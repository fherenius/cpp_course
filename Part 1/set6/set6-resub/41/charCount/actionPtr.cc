#include "charCount.ih"

void(CharCount::*CharCount::s_actionPtr[])(char ch) =
{
    &CharCount::append,
    &CharCount::increment,
    &CharCount::insert
};