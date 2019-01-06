//Laura Austin
//CSCE 121-506
//Due: February 8, 2016
//hw2pr1.cpp
#include "std_lib_facilities_4.h"
#include <iomanip> // for setprecision- keeps numbers to
int main()			// 2 decimal places
try
{
	double income, give, save, live;
	cout << "Income in dollars? $";
	while(cin >> income) // repeats input until program ends
	{
	// Income can't be negative so this ends program
	if (income<0)
		simple_error("income can't be negative\n");
	else 
	// If income is nonnegative, dividing income up, 
	// 10% to give, 10% to save,
	// and 80% to live on
	{give = income * .1;
	save = income * .1;
	live = income * .8;
	cout<< "You should give away about $"
		<<fixed<<setprecision(2)<<give<<", save about $"
		<<fixed<<setprecision(2)<<save<<",\nand live on about $"
		<<fixed<<setprecision(2)<<live<<".\n";
	}
	cout << "Income in dollars? $";
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