//Laura Austin
//CSCE 121-506
//Due: February 1, 2016
//hw1pr2.cpp
//I got the formula for the area of a segment from:
// http://www.mathopenref.com/segmentarea.html
#include "std_lib_facilities_4.h"

int main()
{
double c, r,PI,a,C,S;
// c is chord length
// radius
// a is area of circle of 14 inches
// C is central angle
// S is area of segment
int p;
// p is percentage of pizza left
	cout << "Pizza diameter is 14\".\n"; // the pizza size and diameter is constant.
	cout << "Enter chord length in inches: "; // user enters a number, can be a decimal.
	while(cin >> c) // computer stores a new value for chord length every loop and continues 
	{				// until the user ends the loop with a character or ctrl+C
	if ((c>14) || (c<0)) // user can't cut a negative pizza chord or larger chord than the diameter
		{
		cout << "The pizza can't get cut with that chord length, silly Billy!\n";
		}
	else if ((c>=0) && (c<=14)) // runs the calculation if the chord length falls between 0 and 14
		{
		r = 7; // diameter is 14 so radius is 7, constant
		PI = 3.14159265359; // defining PI manually
		a = PI*pow(r,2); // area of the pizza BEFORE cut
		C = 2*(asin(c/(2*r))); // central angle that corresponds to chord length
		S = (r*r/2) * (C-sin(C)); // Segment area formula
		p = 100 - S/a*100; // percentage of the whole pizza minus percent cut off
		cout << "That cut leaves " << p<< "% of pizza.\n";
	
		}
	cout << "Enter chord length in inches: ";
	}
	return 0; // if program succesfully runs, program ends
}