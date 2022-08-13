#include "dnadata.ih"

// check if all chars are A,T,C or G
bool DNAData::nucleoBaseFileIsValid()
{
	while (true)
	{
		char ch;
		if (!(d_inFile >> ch))
			break;
		if (!charIsValid(ch))
			return false;
	}
	return true;
}
