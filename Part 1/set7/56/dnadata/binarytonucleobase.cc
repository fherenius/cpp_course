#include "dnadata.ih"

void DNAData::binaryToNucleoBase()
{

	cout << "to nb \n";
															// ensure good start
	d_inFile.clear();										// when reading file
	d_inFile.seekg(0);
	Bit bitA, bitB;

	while (true)
	{
		if (!d_inFile) 										// read 2 bits
			break;
		d_inFile.read(reinterpret_cast<char *>(&bitA), 1);
		if (!d_inFile) 
			break;
		d_inFile.read(reinterpret_cast<char *>(&bitB), 1);
		
		char ch = findCharacter(Encoding{bitA, bitB});		// match encoding 
		d_outFile << ch;									// with the char
	}
	d_outFile.close();
}
