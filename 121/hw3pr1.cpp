//Laura Austin
//Laura Austin
//CSCE 121-506
//Due: February 16, 2016
//hw3pr1.cpp
// Standard deviation formula from
// https://www.mathsisfun.com/data/standard-deviation-formulas.html
#include "std_lib_facilities_4.h"

int main()
try
{
	cout << "Enter each number followed by an enter\n";
	double n;
	vector<double>V;
while(cin >> n)
{
	V.push_back(n);
}

double sum = 0;
double numerator = 0;

for (int i = 0;i<V.size();++i)
	sum += V[i];

for (int i = 0;i<V.size();++i)
	numerator += pow((V[i]-(sum/V.size())),2.0);
	
cout<< "Mean: " << sum/V.size() << '\n';

double sdev = sqrt(numerator/V.size());

cout << "Standard deviation: " << sdev << '\n';

return 0;
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