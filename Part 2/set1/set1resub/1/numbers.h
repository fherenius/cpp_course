#ifndef INCLUDED_NUMBERS_H_
#define INCLUDED_NUMBERS_H_

#include <iosfwd>
#include <initializer_list>

class Numbers
{
    size_t d_size = 0;
    int *d_nums = 0;

    friend std::ostream &operator<<(std::ostream &out, Numbers const &num);
    friend bool operator==(Numbers const &lhs, Numbers const &rhs);  
    friend bool operator!=(Numbers const &lhs, Numbers const &rhs);   
    public:
        explicit Numbers(size_t size); 
        Numbers(size_t size, int value);
        Numbers(size_t size, int *values);
        Numbers(std::initializer_list<int> iniList);
        Numbers(Numbers const &other);
        Numbers(Numbers &&tmp);
        ~Numbers();

        void swap(Numbers &other);
        
        Numbers &operator=(Numbers const &other);
        Numbers &operator=(Numbers &&tmp);

        int &operator[](size_t idx);
        int &operator[](size_t idx) const;
        
        size_t size() const;                
    
    private:
        int &element(size_t idx) const;     // for [] operators
};

// free functions
bool operator==(Numbers const &lhs, Numbers const &rhs);   // equals operator
bool operator!=(Numbers const &lhs, Numbers const &rhs);   // not equals

#endif 