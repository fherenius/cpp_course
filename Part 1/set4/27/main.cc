#include "main.ih"

int main()
{
    size_t personsSize = 5;
    Person persons[personsSize];

    readPersons(persons, personsSize);
    writePersons(persons, personsSize);
}