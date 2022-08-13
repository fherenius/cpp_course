#ifndef INCLUDED_STRINGS_
#define INCLUDED_STRINGS_

#include <iosfwd>

class Strings
{
    size_t d_size;
    size_t d_capacity;
    std::string **d_str;

    public:
        struct POD
        {
            size_t      size;
            std::string **str;
        };

        Strings();                                  // 1
        Strings(int argc, char *argv[]);            // 2
        Strings(char *environLike[]);               // 3
        Strings(std::istream &in);                  // 4
        ~Strings();
        
        // new for exercise 57
        Strings(Strings const &other);              // 5
        Strings(Strings &&tmp);                     // 6
        Strings &operator=(Strings const &other);   // assign
        Strings &operator=(Strings &&tmp);          // assign move


        void swap(Strings &other);              

        size_t size() const;
        std::string **data() const;
        POD release();

        std::string const &at(size_t idx) const;
        std::string &at(size_t idx);

        void add(std::string const &next);          // add another element

        size_t capacity();                          // return capacity of str
                                                    // reserve capacity for n
        void reserve(size_t n);                     // Strings
        void resize(size_t n);                      // resize to n Strings

    private:
        void fill(char *ntbs[]);                    // fill prepared d_str

        std::string &safeAt(size_t idx) const;      // private backdoor

        static size_t count(char *environLike[]);   // # elements in env.like
        
        std::string **rawPointers(size_t n);
};

inline size_t Strings::size() const         // potentially dangerous practice:
{                                           // inline accessors
    return d_size;
}

inline std::string **Strings::data() const
{
    return d_str;
}

inline std::string const &Strings::at(size_t idx) const
{
    return safeAt(idx);
}

inline std::string &Strings::at(size_t idx)
{
    return safeAt(idx);
}

        
#endif

