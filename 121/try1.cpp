#include "std_lib_facilities_4.h"

int main()
{
cout << "Enter the name of the person you want to write to:\n";
string first_name;
cin >> first_name;
cout << "Enter the name of another friend:\n";
string friend_name;
cin >> friend_name;
cout << "Gender of your friend? ('m' for male, 'f' for female):\n";
string gen_friend;
cin >> gen_friend;
if (gen_friend == "m");
{
	cout << "your friend is a boy.";
}
return 0;
}