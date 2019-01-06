//Laura Austin
//CSCE 121-506
//Due: February 1, 2016
//hw1pr3.cpp
#include "std_lib_facilities_4.h"
int main()
{
	int square,grains, totgrains; 		// defining type for my variables
	grains = 0; 						// start all grains, squares and totgrains at 0
	square = 0;
	totgrains = 0;
	while(totgrains < 1000) 			// loop will continue until squares evaluated for at least
	{									// 1000 grains of rice
		grains = pow(2,square);			// value of grains in each square is 2 raised to the power
		++square;						// of the current square, add 1 square each loop
		totgrains = totgrains + grains; // total grains are added as each square's grains 
	}									// calculated						
	
	cout << "Square number for 1000 grains of rice is " << square << ".\n";
	while(totgrains < 1000000) 			// loop continues as the previous did, but for 1 million
	{									// grains instead
		grains = pow(2,square);
		square = ++square;
		totgrains = totgrains + grains;
	}
	cout << "Square number for 1000000 grains of rice is " << square << ".\n";
	while(totgrains < 1000000000) 		// loop continues as the first loop did, but for
	{									// 1 billion grains instead		
		grains = pow(2,square);
		square = ++square;
		totgrains = totgrains + grains;
	}
	cout << "Square numbers for 1000000 grains of rice is " << square << ".\n";
return 0; 		// if program runs successfully then the program ends
}