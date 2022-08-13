#include "main.ih"

void writePersons(Person persons[], size_t size)
{
    for (size_t idx = 0; idx < size; ++idx)
        persons[idx].insert(cout);
}