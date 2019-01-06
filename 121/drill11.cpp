#include "std_lib_facilities_4.h"

int main()
{
	ifstream in{"file.txt"};		// input file
	if (!in) cerr << "no file\n";
    
	regex pat {R"(\d{3}-(\d{2})-\d{3})"}; //social

	int lineno = 0;
	for(string line; getline(in,line);){	// read input line into input buffer
		++lineno;
		smatch matches;	// matched strings go here
		if (regex_search(line, matches, pat)) {
			cout << lineno << ": " << matches[0] << '\n';	// whole match
			if (1<matches.size() &&matches[1]=="00")
				cout  << "\t: This looks like a UIN" << '\n';	// sub-match
			if (1<matches.size() &&matches[1]!="00")
				cout  << "\t: This looks like a Social #" << '\n';	// sub-match
		}
	}
}