#include <iostream>

using namespace std;	

struct BitFieldSizes							   // set sizes bitfield
{
	size_t a:   1;						
	size_t b:	3;
	size_t c:	4;
	size_t d:	5;
	size_t e:	4;
	size_t f:	4;
	size_t g:	4;
	size_t h:	4;
	size_t i:	4;
	size_t j:	5;
	size_t k:	2;
};							

union BitField							
{		
	BitFieldSizes bitFieldSizes;							
	size_t word;						
};

int main()
{	
	// initialize union with bit values
	BitField bitField = {0, 7, 15, 10, 6, 7, 15, 15, 7, 0, 3}; 
	
	// output word as hexadecimal value
	cout << hex << bitField.word << '\n';		
}
