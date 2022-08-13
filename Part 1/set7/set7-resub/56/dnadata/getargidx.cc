#include "dnadata.ih"


int DNAData::getArgIdx(int argc, char **argv)
{
	if (argc < 4)
		return -1;
	for (int idx = 1; idx < argc; ++idx)
	{
		if (string { argv[idx] } == "-b")
			return idx;
	}
	return -1;
}