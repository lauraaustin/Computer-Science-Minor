//Laura Austin
//CSCE 121-506
//Due: February 8, 2016
//hw2pr3.cpp
#include "std_lib_facilities_4.h"
#include <cmath>
double my_cbrt_1(double n)
{
	// this formula is an approximation for cubed root
	double cbrt;
	cbrt = (-0.411665*n*n)+(1.03455*n) + 0.377113;
	return cbrt;
}
int main()
try
{
	double n, rep; //rep == relative error percent
	cout<< std::left << setw(21) << "n" //std::left aligns columns left
		<< setw(21) << "cbrt"			//setw aligns columns by character
		<< setw(21) << "my_cbrt_1"
		<< "relative error\n"
		<<"------------------------------------------"
		<<"------------------------------------\n";
	// printing n, cbrt, my_cbrt_1 and relative error percent
	// for values of n times 10 
	// raised to powers in k. 
	for(auto k : {-100, -10, -1, 0, 1, 10, 100})
	{
		n = M_PI * pow(10.0, k);
		rep = (( my_cbrt_1(n)-cbrt(n) ) /cbrt(n))*100;
		cout<< std::left << setw(21) << n << ""
			<< setw(21) << cbrt(n) <<""
			<< setw(21) << my_cbrt_1(n) << ""
			<< rep << "%\n";
	}
return 0; // 0 indicates success
}
catch (exception& e)
{
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1; // 1 indicates failure
}
catch(...)
{
	cerr<< "Oops: unknown exception!\n";
	keep_window_open();
	return 2; // 2 indicates failure
}