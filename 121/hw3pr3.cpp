//Laura Austin
//CSCE 121-506
//Due: February 16, 2016
//hw3pr3.cpp
#include "std_lib_facilities_4.h"

vector<double>fibonacci(double x, double y, int n)
{
	vector<double>v;
for (int i = 0; i<n; ++i)
{
	if (i==0)
		v.push_back(x);
	else if (i==1)
		v.push_back(y);
	else
		v.push_back((v[i-2])+v[i-1]);
	//takes last element in vector and adds to previous
	//element 
}
return v;
}
int main()
try
{
	vector<double>v;
	cout << "input x y n: \n";
	double x;
	double y;
	int n;
	// x is first element, y is second element, n is size
	// of vector
	cin >> x >> y >> n;
	v=fibonacci(x,y,n);
	double ratio = (v[v.size()-1])/(v[v.size()-2]);
	// ratio closer to golden mean as described in hw
	cout << '\n'<<ratio;
}
catch (exception& e)
{
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1; // 1 indicates success
}
catch (...)
{
	cerr<< "Oops: unknown exception!\n";
	keep_window_open();
	return 2; // 2 indicates success
}