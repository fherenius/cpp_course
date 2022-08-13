#include "dnadata/dnadata.h"

using namespace std;

int main(int argc, char **argv)
{
	DNAData dnaData(argc, argv);
	dnaData.translate();
}
