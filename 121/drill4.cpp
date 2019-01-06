#include "std_lib_facilities_4.h"

int main()
{
	double a,b;
	cout << "Enter 2 values (whole numbers please): \n";
	while(cin>>a>>b)
	{
		if ((abs(a-b) <= 0.01) )
		{
			cout << "The numbers are almost equal.\n";
		}
		else if (a<b)
		{
			cout << "The smaller value is: " << a << "\n";
			cout << "The larger value is: " << b << "\n";
		}
		else if (b<a)
		{
			cout << "The smaller value is: " << b << "\n";
			cout << "The larger value is: " << a << "\n";
		}
		else if (a==b)
		{
			cout << "The numbers are equal.\n";
		}
		else if ((a == '|') || (b == '|'))
		{
			return 0;
		}
		cout << "Enter 2 values (whole numbers please): \n";
	}
	return 0;
}