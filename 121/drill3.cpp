#include "std_lib_facilities_4.h"

int main()
{
	cout << "Enter the first name of the person you want to write to (followed by 'enter'):\n";
string fname;
cin >> fname;

cout << "Enter the name of another friend (followed by 'enter'):\n";
string friendname;
cin >> friendname;

cout << "Gender of your friend? ('m' for male, 'f' for female):\n";
string  gender;
cin >> gender;

cout <<  "Age of the recipient:\n";
int age;
cin >> age;

if ( (age <= 0) || (age >= 110) )
{
	simple_error("You're kidding!");
}

cout << "\nDear " << fname << ",\n\n";

cout << "\tHow are you? I am fine. I miss you. ";

cout << "Have you seen " << friendname << " lately?";

if (gender == "m")
{
	cout << " If you see " << friendname << " please ask him to call me.";
}
else if (gender == "f")
{
	cout << " If you see " << friendname << " please ask her to call me.";
}

if ( (age <=12) && (age >0 ) ) 
{
	cout << " Next year you will be " << age+1 << "!\n";
}
else if (age == 17)
{
	cout << " Next year you will be able to vote!\n";
}
else if ( (age >=70) && (age < 110) )
{
	cout << " I hope you are enjoying retirement.\n";
}
else if ( (age > 17) && (age < 70) )
{
	cout << " I hope you are loving your life. You rock.\n";
}
else if ( (age > 12) && (age <17) )
{
	cout << " I really hope middle school and high school are going well";
	cout << " for you. Those are the years you physically grow most!\n";
}

cout << "I sure do hope you tell the family hello. I really miss their SWEET faces!\n";

cout << "\nSincerely,\n\nLaura\n";
return 0;
}

