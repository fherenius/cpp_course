#include "dnadata.ih"

bool DNAData::charIsValid(char ch)
{
	return 	ch == Chars::A || 
			ch == Chars::C ||
			ch == Chars::T ||
			ch == Chars::G;
}
