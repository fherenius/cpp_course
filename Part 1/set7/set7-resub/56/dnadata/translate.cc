#include "dnadata.ih"

void DNAData::translate()
{
	(this->*d_translatePtr)();
}
