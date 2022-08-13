#include "main.ih"

using namespace std;


int main()
{
    int var = 5;
    int *pvar = &var;
    int &rvar = var;
    int &&rrvar = 5;
    cout << TraitCounter< decltype(var) >::value << ", "
         << TraitCounter< decltype(pvar) >::value << ", "
         << TraitCounter< decltype(rvar) >::value << ", "
         << TraitCounter< decltype(rrvar) >::value << '\n';

    auto ptr1 = locate(var);
    auto ptr2 = locate(pvar);
    auto ptr3 = locate(rvar);
    auto ptr4 = locate(rrvar);

    cout << *ptr1 << ", " << *ptr2 << ", "
         << *ptr3 << ", " << *ptr4 << '\n';

}
