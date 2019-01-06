#include "std_lib_facilities_4.h"
#include <iostream>

struct Point
{
	double x, y;
};

ostream& operator << (ostream& os, Point p)
{
	os << "(" << p.x << "," << p.y << ")" << endl;
	return os;
}
// open with wordpad for proof of \n !!!
istream& operator >> (istream& is, Point p)
{
	is >> p.x >> p.y;
	return is;
}
int main()
{
	cout<< "Enter 7 pairs for (x,y) (eg 2 3): " << endl;
	vector<Point>original_points;
	double x, y;
	Point p;
	
	ifstream ist{"MyData.txt"};
	vector<Point> processed_points;
	for (int i = 0; i<7; ++i)
	{
		cin >> p.x >> p.y;
		original_points.push_back(p);
		processed_points.push_back(p);
	}
	ofstream ofs {"MyData.txt"};
	for(int i = 0; i < original_points.size(); ++i)	//the whole original_points
	{
		ofs << original_points[i];
	}
	ofs.close();
	cout << "Print from file: "
		 << endl;
	for (int i = 0; i < processed_points.size(); ++i) 
	{
		cout << processed_points[i] << endl;
	}
	cin.clear();
	cin.ignore();
	keep_window_open();
	return 0;
}