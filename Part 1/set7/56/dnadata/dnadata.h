#ifndef INCLUDED_DNADATA_
#define INCLUDED_DNADATA_

#include <fstream>
// Nucleo base characters
enum Chars: unsigned char
{
    A = 'A',
    C = 'C',
    T = 'T',
    G = 'G'
};
// constant for # chars
enum Sizes
{
    NCHARS = 4
};
// bitfield of size one
struct Bit 
{
    unsigned bit: 1;
};
// pair of bits representing a letter
struct Encoding
{
    Bit a;
    Bit b;
};
// Letter hold the char-encoding pairs
struct Letter
{
    Chars ch;
    Encoding encoding;
};


class DNAData
{
    std::ifstream d_inFile;
    std::ofstream d_outFile;
    bool d_binaryMode;

    void (DNAData::*d_translatePtr)();          // ptr to function set based on
                                                // translation mode
    static void (DNAData::*s_translate[])();    // array of functions
    static Letter s_letters[];                  // the 4 Letters (char-enc) 

    public:

        DNAData(int argc, char **argv);
        void translate();

    private:
        void binaryToNucleoBase();              // two translation modes
	    void nucleoBaseToBinary();              

        Encoding findEncoding(char ch);         // ways of translating both 
        char findCharacter(Encoding encoding);  // elemental items 

        bool encodingMatch(Encoding const &enc1, Encoding const &enc2);
        void showEncoding(Encoding const &enc, char ch = 0) const;
        bool nucleoBaseFileIsValid();
        bool charIsValid(char ch);
};
        
#endif
