#include "dnadata.ih"

char DNAData::findCharacter(Encoding encoding)
{
	for (size_t idx = 0; idx < Sizes::NCHARS; ++idx)
	{
		if (encodingMatch(encoding, s_letters[idx].encoding))
			return s_letters[idx].ch;
	}
	return 0;
}

