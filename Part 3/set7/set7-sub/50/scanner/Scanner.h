// Generated by Flexc++ V2.11.00 on Thu, 24 Mar 2022 21:42:21 +0000

#ifndef Scanner_H_INCLUDED_
#define Scanner_H_INCLUDED_

// $insert baseclass_h
#include "Scannerbase.h"


// $insert classHead
class Scanner: public ScannerBase
{
    public:
        enum Tokens // Enum containing tokens
        {
          CHAR = 1, // Make sure to not start at 0
          IDENTIFIER,
          INT,
          REAL,
          OPERATOR,
          STRING
        };
        explicit Scanner(std::istream &in = std::cin, std::ostream &out = std::cout, bool keepCwd = true);

        Scanner(std::string const &infile, std::string const &outfile, bool keepCwd = true);
        
        // $insert lexFunctionDecl
        int lex();

    private:
        int lex_();
        int executeAction_(size_t ruleNr);

        void print();
        void preCode();     // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts

        void postCode(PostEnum_ type);    
                            // re-implement this function for code that must 
                            // be exec'ed after the rules's actions.
};

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

