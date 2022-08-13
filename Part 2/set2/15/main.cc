#include <iostream>

using namespace std;

class Object
{
    size_t *d_arr;
    
    public:        
        Object()
        :
            d_arr(new size_t[1])
        {
            cout << "Constructor called\n";
        }

        ~Object()
        {
            cout << "Destructor called\n";
            delete[] d_arr;
        }

        void throwException()
        {
            throw string("Exception");
        }

        void hardExit()
        {
            exit(1);
        }
};


int main(int argc, char const *argv[])
{
    Object obj;

    try
    {
        obj.throwException();

        //obj.hardExit();
    }
    catch(string &e)
    {
        cerr << e << '\n';
    }
}
