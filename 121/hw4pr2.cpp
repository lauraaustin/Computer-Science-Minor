//Laura Austin
//CSCE 121-506
//Due: March 3, 2016
//hw4pr2.cpp
#include "std_lib_facilities_4.h"

int main()
try
{
	
	// Open dictionary file
	ifstream ifs {"/usr/share/dict/american"};
	if (!ifs) error("Can't open input file ", "/usr/share/dict/american");
	string a = ""; 			// every word in dictionary
	string str1 = "Cei"; 	// defining strings to find
	string str2 = "cei";
	string str3 = "Cie";
	string str4 = "cie";
	int number1 = 0;
	int number2 = 0;
	int number3 = 0;
	int number4 = 0;
	while (ifs >> a)
	{
		if (a.find(str1)<a.size()) 		// finds string in the word and
			++number1;					// adds to the total number of
		else if(a.find(str2)<a.size())	// that string found
			++number2;
		else if(a.find(str3)<a.size())
			++number3;
		else if(a.find(str4)<a.size())
			++number4;
	}
//----------------------------------------------------------------
	cout << "\n\nThere are " << number1+number2 << " \"cei\" and "
		 << number3+number4 << " \"cie\" words.\n\n";
	
	
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