#include "person.ih"

void Person::extract(istream &in)
{

    string name, address, phone, mass;  // temporary values to write input to

    getline(in, name, ',');             // get input from stdin
    getline(in, address, ',');
    getline(in, phone, ',');
    getline(in, mass);

    setName(name);                      // set class data members with input
    setAddress(address);
    setPhone(phone);
    setMass(stoul(mass));
}