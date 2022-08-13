#include "person.ih"

void Person::setPhone(string const &phone)
{                                   // check if phone only consists of digits
    if (phone.find_first_not_of("0123456789") == string::npos)
        d_phone = phone;
    else 
        cout << "Phone number must only contain digits!\n";
}