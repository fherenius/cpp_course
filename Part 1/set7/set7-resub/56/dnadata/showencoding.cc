#include "dnadata.ih"

void DNAData::showEncoding(Encoding const &enc, char ch) const
{
	cout 	<< ch 	<< ' ' << enc.a.bit 
					<< ' ' << enc.b.bit 
					<< '\n';
}
