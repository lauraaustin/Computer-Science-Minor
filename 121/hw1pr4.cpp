#include "std_lib_facilities_4.h"

int main()
{
	int square;
	unsigned long long grains;	// grains are that type because of long number
	square = 0; 				// square number begins at 0
	grains = 0;					// grain number begins at 0
	while (square < 64) 		// this prints squares for 0 to 64 and ends at 64
	{
		grains = pow(2,square); // grain number equals 2 raised to the power of square number
		++square; 				// square = square + 1
		cout << square<< "  =  " <<grains<< "\n"; // prints the square and the
												  // associated grain number
	}
	return 0; // stops program
}