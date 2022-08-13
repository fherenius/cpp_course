#ifndef INCLUDED_DNADATA_
#define INCLUDED_DNADATA_

#include <fstream>



class DNAData
{
    std::ifstream d_inFile;
    std::ofstream d_outFile;
    bool d_binaryMode;

    void (DNAData::*d_translatePtr)();          // ptr to function set based on
                                                // translation mode
    

    // Nucleo base characters
    enum Chars: unsigned char  
    {                          // fix: was outside DNAData, 
        A = 'A',               // now inside
        C = 'C',               
        T = 'T',               
        G = 'G'
    };
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
    
    struct Letter
    {
        Chars ch;
        Encoding encoding;
    };
                                                // 'dictionary' of chars-enc
    DNAData::Letter const s_letters[4] = 
    {
        Letter{Chars::A, Encoding{Bit{0}, Bit{0}}},						// A
        Letter{Chars::C, Encoding{Bit{1}, Bit{0}}},						// C
        Letter{Chars::T, Encoding{Bit{0}, Bit{1}}},						// T
        Letter{Chars::G, Encoding{Bit{1}, Bit{1}}}						// G
    };

    void (DNAData::*const s_translate[2])() =   // hold the 2 translation modes
    { 
        &DNAData::binaryToNucleoBase,
        &DNAData::nucleoBaseToBinary
    };
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
        
        int getArgIdx(int argc, char **argv);   // if arg -b is given this 
                                                // function returns it index
                                                // otherwise it returns -1
};
        
#endif
