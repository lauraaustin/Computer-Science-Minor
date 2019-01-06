#include "std_lib_facilities_4.h"
int main()
{
	double number1, number2;
	string math;
	cout << "Enter a math operation:\n";
	cin >> number1;
	cin >> math;
	cin >> number2;
	if (math == "+")
	{
		double ans = number1 + number2;
		cout << "The sum of " << number1<<" and "<< number2<< " is " << ans <<".\n";
	}
	else if (math == "-")
	{
		double ans = number1 - number2;
		cout << "The subraction of " << number1<<" and "<< number2<< " is " << ans <<".\n";
	}
	else if (math == "*")
	{
		double ans = number1 * number2;
		cout << "The product of " << number1<<" and "<< number2<< " is " << ans <<".\n";
	}
	else if (math == "/")
	{
		double ans = number1 / number2;
		cout << "The quotient of " << number1<<" and "<< number2<< " is " << ans <<".\n";
	}
}