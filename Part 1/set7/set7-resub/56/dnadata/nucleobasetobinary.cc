#include "dnadata.ih"

void DNAData::nucleoBaseToBinary()
{
	cout << "to binary \n";
	if (!nucleoBaseFileIsValid())
	{
		cerr << "invalid input\n";
        // fix: use cerr instead of cout.
		return;
	}
	d_inFile.clear();
	d_inFile.seekg(0);
	
	while (true)
	{
		char ch;
		if (!(d_inFile >> ch) || !charIsValid(ch)) 
			break;
		Encoding enc = findEncoding(ch);
		// showEncoding(enc, ch);
		d_outFile << enc.a.bit << enc.b.bit;
		// d_outFile.write(reinterpret_cast<char const *>(&enc), sizeof(Encoding));
	}
	d_outFile.close();
}
