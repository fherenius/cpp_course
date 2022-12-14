// Generated by Flexc++ V2.11.00 on Sun, 27 Mar 2022 22:25:32 +0000

#ifndef Scanner_H_INCLUDED_
#define Scanner_H_INCLUDED_

// $insert baseclass_h
#include "Scannerbase.h"


// $insert classHead
class Scanner: public ScannerBase
{
    public:
        explicit Scanner(std::istream &in = std::cin, std::ostream &out = std::cout, bool keepCwd = true);

        Scanner(std::string const &infile, std::string const &outfile, bool keepCwd = true);
        
        // $insert lexFunctionDecl
        int lex();

        size_t chars() const;  // Return amount of matched chars
        size_t idents() const; // Return amount of idents
        size_t ints() const;   // Return amount of ints
        size_t reals() const;  // Return amount of reals

    private:
        size_t d_chars = 0;   // Tracks amount of chars
        size_t d_idents = 0;  // Tracks identifiers
        size_t d_ints = 0;    // Tracks ints
        size_t d_reals = 0;   // Tracks real numbers
        size_t d_offset = 0;  // Line offset after finding #>
        int lex_();
        int executeAction_(size_t ruleNr);

        void print();
        void preCode();     // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts

        void postCode(PostEnum_ type);    
                            // re-implement this function for code that must 
                            // be exec'ed after the rules's actions.
};

inline size_t Scanner::chars() const // Returns amount of chars
{
  return d_chars;
}

inline size_t Scanner::idents() const // Returns amount of idents
{
  return d_idents;
}

inline size_t Scanner::ints() const // Returns ints
{
  return d_ints;
}

inline size_t Scanner::reals() const // Returns real numbers
{
  return d_reals;
}

// $insert scannerConstructors
inline Scanner::Scanner(std::istream &in, std::ostream &out, bool keepCwd)
:
    ScannerBase(in, out, keepCwd)
{}

inline Scanner::Scanner(std::string const &infile, std::string const &outfile, bool keepCwd)
:
    ScannerBase(infile, outfile, keepCwd)
{}

// $insert inlineLexFunction
inline int Scanner::lex()
{
    return lex_();
}

inline void Scanner::preCode() 
{
    // optionally replace by your own code
}

inline void Scanner::postCode([[maybe_unused]] PostEnum_ type) 
{
    // optionally replace by your own code
}

inline void Scanner::print() 
{
    print_();
}


#endif // Scanner_H_INCLUDED_

