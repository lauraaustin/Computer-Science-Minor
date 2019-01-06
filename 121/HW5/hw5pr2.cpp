//Laura Austin
//CSCE 121-506
//Due: March 23, 2016
//hw5pr2.cpp
#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
try
{
	Simple_window win(Point(1000,1000),600,400, "TEXAS FLAG");
	//-------------------
	Rectangle outline(Point(150,150),300,200);
	Rectangle blue(Point(150,150),100,200);
	Rectangle white(Point(250,150),200,100);
	Rectangle red(Point(250,250),200,100);
	
	blue.set_fill_color(Color::blue);
	white.set_fill_color(Color::white);
	red.set_fill_color(Color::red);
	
	blue.set_color(Color::invisible);
	white.set_color(Color::invisible);
	red.set_color(Color::invisible);
	
	
	//star 
	
	Closed_polyline star;
	star.add(Point(200,212.5)); //1
	star.add(Point(210.7,239.7)); //2
	star.add(Point(237.5,239.3)); //3
	star.add(Point(216.08,255.38)); //4
	star.add(Point(221.44,282.18)); //5
	star.add(Point(200,266.1)); //6
	star.add(Point(178.56,282.18)); //7
	star.add(Point(183.92,255.38)); //8
	star.add(Point(162.48,239.3)); //9
	star.add(Point(189.28,239.3)); //10
	
	star.set_fill_color(Color::white);
	star.set_color(Color::invisible);
	
	win.attach(outline);
	win.attach(blue);
	win.attach(white);
	win.attach(red);
	win.attach(star);
	
	win.wait_for_button();
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