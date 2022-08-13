#include "dnadata.ih"

bool DNAData::encodingMatch(Encoding const &enc1, Encoding const &enc2)
{
	return enc1.a.bit == enc2.a.bit 
		&& enc1.b.bit == enc2.b.bit;
}
