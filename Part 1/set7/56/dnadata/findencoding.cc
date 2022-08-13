#include "dnadata.ih"

Encoding DNAData::findEncoding(char ch)
{
	for (size_t idx = 0; idx < Sizes::NCHARS; ++idx)
	{
		if (ch == s_letters[idx].ch)
			return s_letters[idx].encoding;		
	}
	return s_letters[Sizes::NCHARS - 1].encoding;
}
