#ifndef INCLUDED_DATA_
#define INCLUDED_DATA_

#include <string>

enum Type
{
    DOUBLE_ARRAY = 0,
    STRING = 1,
    SIZE_T = 2
};

union Data
{
    double (*u_double)[10];                     // ptr to double array of 10
    std::string u_word;
    size_t u_value;
                                                // arrays holding functions 
                                                // which are accessed based
                                                // on the type of the field
    static void (Data::*s_destroy[])();
    static void (Data::*s_copy[])(Data const &other);
    static void (Data::*s_swap[][3])(Data &other);
    

    public:
        Data(double (*arr)[10]);                // 1
        Data(std::string const &word);          // 2
        Data(size_t value);                     // 3
        Data(Data const &other, Type type);     // 4
        Data(Data &&tmp, Type type);            // 5

        ~Data();                                // empty

                                                // 4 basic (public) utilities
                                                // each of which picks the 
                                                // right version based on the 
                                                // types involved (except for
        void destroy(Type active);              // copy())
        void copy(Data const &other, Type current, Type next);
        void move(Data &&tmp, Type current, Type next);
        void swap(Data &other, Type current, Type next);

        double const (*doubleArrayPtr())[10];   // accessors
        std::string const &word() const;
        size_t value() const;

    private:
        void destroyDoubleArray();              // all the type specific 
        void destroyWord();                     // functions per utility
        void destroyValue();

        void copyDoubleArray(Data const &other);
        void copyWord(Data const &other);
        void copyValue(Data const &other); 

        void swapDoubleArrayDoubleArray(Data &other);
        void swapDoubleArrayWord(Data &other);
        void swapDoubleArrayValue(Data &other);

        void swapWordDoubleArray(Data &other);
        void swapWordWord(Data &other);
        void swapWordValue(Data &other);

        void swapValueDoubleArray(Data &other);
        void swapValueWord(Data &other);
        void swapValueValue(Data &other);

};

// initialization of the arrays of functions
inline void (Data::*Data::s_destroy[])() =
{
    &Data::destroyDoubleArray,
    &Data::destroyWord,
    &Data::destroyValue
};

inline void (Data::*Data::s_copy[])(Data const &other) =
{
    &Data::copyDoubleArray,
    &Data::copyWord,
    &Data::copyValue
};

// swap[from][to] / [this][other]
inline void (Data::*Data::s_swap[][3]) (Data &other) =
{
    {
        &Data::swapDoubleArrayDoubleArray,
        &Data::swapDoubleArrayWord,
        &Data::swapDoubleArrayValue
         
    },
    {
        &Data::swapWordDoubleArray,
        &Data::swapWordWord,
        &Data::swapWordValue
    },
    {   
        &Data::swapValueDoubleArray,
        &Data::swapValueWord,
        &Data::swapValueValue
    }
};

inline double const (*Data::doubleArrayPtr())[10]
{
    return u_double;
}

inline std::string const &Data::word() const
{
    return u_word;
}

inline size_t Data::value() const
{
    return u_value;
}
        
#endif
