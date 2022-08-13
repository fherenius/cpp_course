#ifndef INCLUDED_NUMBERS_
#define INCLUDED_NUMBERS_

#include <iosfwd>

class Numbers
{
    size_t d_len;
    int *d_int;

    public:
        Numbers();                                  // 1
        Numbers(size_t count);                      // 2
        Numbers(size_t count, int value);           // 3
        Numbers(Numbers const &other);              // 4
        Numbers(Numbers &&tmp);                     // 5

        Numbers &operator=(Numbers const &other);
        Numbers &operator=(Numbers  &&other);       // move
        ~Numbers();

        int &at(size_t idx);
        void write(std::ostream &out);
        size_t lenght();

        void swap(Numbers &other);
    
    private:
        /* data */
};

#endif
