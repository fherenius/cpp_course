#include "main.ih"

void readPersons(Person persons[], size_t size)
{
    for (size_t idx = 0; idx < size; ++idx)
    {
        cout << "? ";
        persons[idx].extract(cin);
    }
}
