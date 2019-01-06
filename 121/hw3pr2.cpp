//Laura Austin
//CSCE 121-506
//Due: February 16, 2016
//hw3pr2.cpp
#include "std_lib_facilities_4.h"
#include <cmath>
double my_cbrt_1(double n)
{
	double cbrt;
	cbrt = (-0.411665*n*n)+(1.03455*n) + 0.377113;
	return cbrt;
}
double my_cbrt_2(double n)
{
	double result = 1;
	while (n>1.0)
		{
		result = result*2; 
		n= n/8;
		}
	// if n<0.125, divide result by 2 and multiply n by 8,
	// until n is greater than or equal to 0.125.
	while (n<0.125)
		{
		result = result/2.0; 
		n=n*8.0;
		}
return result*my_cbrt_1(n); // my_cbrt_2 is result times 
							// my_cbrt_1.
}
double my_cbrt_3(double n)
{
	double result =1;
	double x = my_cbrt_2(n);
	if (n==0)
		result = 0;
	else if (n<0)
		result = -my_cbrt_3(-n);
	else if (n>0)
	{
		for (int i = 0; i<10; ++i)
		{
			x = (2.0/3.0)*x + n/(3.0*x*x);
		}
		result =x;
	}
	return result;
}
int main()
try
{
	double n, rep; //rep == relative error percent
	cout<< "enter n\n";
	while(cin>>n)
	{
		rep = (( my_cbrt_3(n)-cbrt(n) ) /cbrt(n))*100;
		cout << "my_cbrt_3: " <<my_cbrt_3(n)<< '\n'
			<< "cbrt(n): "<<cbrt(n) <<'\n'
			<< "relative error percent: "<<rep<< "%\n";
		cout<<"enter n\n";
	}
	
return 0; // 0 indicates success
}
catch (exception& e)
{
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1; // 1 indicates success
}
catch(...)
{
	cerr<< "Oops: unknown exception!\n";
	keep_window_open();
	return 2; // 2 indicates success
}