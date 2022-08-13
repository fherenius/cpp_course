#include "dnadata.ih"

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
