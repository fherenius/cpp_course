#include "dnadata/dnadata.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    // fix: added two lines to check if args are valid before 
	// construction
	if (argc < 3 || argc > 4)							// invalid args
	{
		cerr 	<<	"not enough args, give: \n"
				<<	" [-b] inpath outpath or \n"
				<<	" inpath outpath [-b] \n ";
		return 0;
	}
	DNAData dnaData(argc, argv);
	dnaData.translate();
}
