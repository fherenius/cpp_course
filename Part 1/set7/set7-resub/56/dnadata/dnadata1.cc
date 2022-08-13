#include "dnadata.ih"

// Fix: This assumed that '-b' is always the third argument. 
// now it also takes "-b in out" instead of only "in out -b"
DNAData::DNAData(int argc, char **argv)   
{
	
	int idx = getArgIdx(argc, argv);
	d_binaryMode = idx > 0 && idx < 4;
    d_translatePtr = s_translate[d_binaryMode];
	size_t offset = idx == 3 || !d_binaryMode ? 1 : 2; 	// find where in/out
														// paths are in args
	string inPath{ argv[offset]}, outPath{ argv[offset + 1]};
	if (d_binaryMode)									// open in right mode
	{
		d_inFile.open(inPath, ios::in);
		d_outFile.open(outPath, ios::binary | ios::out);
	}
	else 
	{
		d_inFile.open(inPath, ios::binary | ios::in);
		d_outFile.open(outPath, ios::out);
	}
	

	if (!d_outFile)										// in case file the 													
	{													// does not exist
		d_outFile.clear();
		d_outFile.open(outPath, ios::binary | ios::out);
	}
	if (!d_inFile)
		cerr << "input file invalid \n";
}
