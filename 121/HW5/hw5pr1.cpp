//Laura Austin
//CSCE 121-506
//Due: March 23, 2016
//hw5pr1.cpp
#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"


int main()
try
{
	Simple_window win(Point(100,100),600,400,"HOUSE");
	
	//-----------------------------
	//all the rectangles
	Rectangle house (Point(175,140),250,160);
	Rectangle chimney (Point(340,75),35,66);
	Rectangle door (Point(277,210),45,90);
	Rectangle windowleft (Point(200,225),40,45);
	Rectangle windowright (Point(355,225),40,45);
	
	house.set_fill_color(Color::green);
	chimney.set_fill_color(Color::blue);
	door.set_fill_color(Color::magenta);
	windowleft.set_fill_color(Color::cyan);
	windowright.set_fill_color(Color::cyan);
	
	windowleft.set_color(Color::white);
	windowright.set_color(Color::white);
	//-----------------------------
	// smoke and doorknob
	Circle smoke1 (Point(358,63),10); 
	Circle smoke2 (Point(358,42),15);
	Circle smoke3 (Point(358,25),20);
	Circle knob (Point(315,265),4);
	
	smoke1.set_fill_color(Color::white);
	smoke2.set_fill_color(Color::white);
	smoke3.set_fill_color(Color::white);
	knob.set_fill_color(Color::black);
	
	smoke1.set_color(Color::invisible);
	smoke2.set_color(Color::invisible);
	smoke3.set_color(Color::invisible);
	//-----------------------------
	//roof 
	Closed_polyline tri;
	tri.add(Point(300,73));
	tri.add(Point(445,140));
	tri.add(Point(155,140));
	tri.set_fill_color(Color::red);
	//-----------------------------
	//window lines
	Line horizontalleft(Point(200,247.5),Point(240,247.5));
	Line horizontalright(Point(355,247.5),Point(395,247.5));
	Line verticalleft(Point(220,225),Point(220,270));
	Line verticalright(Point(375,225),Point(375,270));
	
	horizontalleft.set_color(Color::white);
	horizontalright.set_color(Color::white);
	verticalleft.set_color(Color::white);
	verticalright.set_color(Color::white);
	//-----------------------------
	//attaching
	win.attach(chimney);
	win.attach(house);
	win.attach(smoke1);
	win.attach(smoke2);
	win.attach(smoke3);
	win.attach(tri);
	win.attach(door);
	win.attach(windowleft);
	win.attach(windowright);
	win.attach(knob);
	win.attach(verticalleft);
	win.attach(verticalright);
	win.attach(horizontalleft);
	win.attach(horizontalright);
	
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