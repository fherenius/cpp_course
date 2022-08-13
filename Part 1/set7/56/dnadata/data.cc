#include "dnadata.ih"

void (DNAData::*DNAData::s_translate[])() = 
{
	&DNAData::binaryToNucleoBase,
	&DNAData::nucleoBaseToBinary
};

Letter DNAData::s_letters[] = 
{
	Letter{Chars::A, Encoding{Bit{0}, Bit{0}}},						// A
	Letter{Chars::C, Encoding{Bit{1}, Bit{0}}},						// C
	Letter{Chars::T, Encoding{Bit{0}, Bit{1}}},						// T
	Letter{Chars::G, Encoding{Bit{1}, Bit{1}}}						// G
};
