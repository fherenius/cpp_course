#include <iostream>

class Object
{
    size_t *d_arr;
    
    public:        
        Object();
        ~Object();
        
        void throwException();
        void hardExit();
};