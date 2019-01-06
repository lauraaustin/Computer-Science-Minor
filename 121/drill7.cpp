#include "std_lib_facilities_4.h"

class Date
{
	public:
	Date(){}
	
	void leap_year(int year)
	{
		if ((year % 4==0) || (year % 100 == 0) || (year % 400 == 0))
			cout << "its a leap year\n";
		else 
			cout << "its not a leap year\n";
		
		cout << "enter year: ";
	}
};

int main()
{
	int year;
	cout << "enter year: ";
	while (cin>>year)
	{
		Date now;
		now.leap_year(year);
	}
	return 0;
}