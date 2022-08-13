#include "dnadata.ih"

DNAData::DNAData(int argc, char **argv)
:
	d_inFile(argv[1], ios::binary | ios::in),
	d_outFile(argv[2], ios::binary | ios::in),
	d_binaryMode(argc > 3 && string(argv[3]) == "-b"),
	d_translatePtr(s_translate[d_binaryMode])
{
	// initiates object based on args containing, in file, out file and mode
	
}
