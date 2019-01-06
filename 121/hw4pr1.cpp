//Laura Austin
//CSCE 121-506
//Due: March 3, 2016
//hw4pr1.cpp
#include "std_lib_facilities_4.h"

int main()
try
{

	string firstatom, secondatom;
	double MW1,MW2,ratio1,ratio2,finalratio;
	double massnum1,massnum2,measuredval,theoretical,error;
	cout << "What is the symbol for your first atom? ";
	cin >> firstatom;
	cout << "What is the mass number of "
		 << firstatom << "? ";
	cin >> massnum1;
	cout << "What is the measured weight of "
		 << firstatom << " in grams? ";
	cin >> MW1;
	cout << "What is the symbol for your second atom? ";
	cin >> secondatom;
	cout << "What is the mass number of "
		 << secondatom << "? ";
	cin >> massnum2;
	cout << "What is the measured weight of "
		 << secondatom << " in grams? ";
	cin >> MW2;
	//first step: divide by molar masses
	ratio1 = MW1/massnum1;
	ratio2 = MW2/massnum2;
//-------------------------------------------------------------------
	int intval;
	measuredval = (ratio1)/(ratio2);
//-------------------------------------------------------------------
if (measuredval<1)
{
	double num, den;
	for(den=1; den<200; ++den)
	{
		for (num=1; num<=den;++num)
		{
			theoretical = num/den;
			// find error and compare
			error = (abs(measuredval-theoretical)/measuredval);
			if (error<0.01) break;
		}
		if (error<0.01) break;
	}	
// prints differently for a ratio less than one
		if ((num==1)&(den==1))
	{
		cout << "The simplest close ratio of "
			 << firstatom << " to "
			 << secondatom << " is "
			 << num << " to " << den << ", so "
			 << "the formula is "
			 << firstatom << secondatom << ".\n";
	}
	else if (num==1)
	{
		cout << "The simplest close ratio of "
			 << firstatom << " to "
			 << secondatom << " is "
			 << num << " to " << den << ", so "
			 << "the formula is "
			 << firstatom << secondatom << den << ".\n";
	}
	else if (den==1)
	{
		cout << "The simplest close ratio of "
			 << firstatom << " to "
			 << secondatom << " is "
			 << num << " to " << den << ", so "
			 << "the formula is "
			 << firstatom << num << secondatom << ".\n";
	}
	else
	{
		cout << "The simplest close ratio of "
			 << firstatom << " to "
			 << secondatom << " is "
			 << num << " to " << den << ", so "
			 << "the formula is "
			 << firstatom << num << secondatom << den << ".\n";
	}
}

if (measuredval>1)
{
	double num,den;
	measuredval=1/measuredval;
	for(den=1; den<200; ++den)
	{
// prints different for a ratio greater than 1
		for (num=1; num<=den;++num)
		{
			theoretical = num/den;
			// find error and compare
			error = (abs(measuredval-theoretical)/measuredval);
			if (error<0.01) break;
		}
		if (error<0.01) break;
	}	
//------------------------------------------------------------
		if ((num==1)&(den==1))
	{
		cout << "The simplest close ratio of "
			 << firstatom << " to "
			 << secondatom << " is "
			 << den << " to " << num << ", so "
			 << "the formula is "
			 << firstatom << secondatom << ".\n";
	}
	else if (num==1)
	{
		cout << "The simplest close ratio of "
			 << firstatom << " to "
			 << secondatom << " is "
			 << den << " to " << num << ", so "
			 << "the formula is "
			 << firstatom << den << secondatom << ".\n";
	}
	else if (den==1)
	{
		cout << "The simplest close ratio of "
			 << firstatom << " to "
			 << secondatom << " is "
			 << den << " to " << num << ", so "
			 << "the formula is "
			 << firstatom << secondatom << num << ".\n";
	}
	else
	{
		cout << "The simplest close ratio of "
			 << firstatom << " to "
			 << secondatom << " is "
			 << den << " to " << num << ", so "
			 << "the formula is "
			 << firstatom << den << secondatom << num << ".\n";
	}
}
return 0;
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