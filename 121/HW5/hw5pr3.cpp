//Laura Austin
//CSCE 121-506
//Due: March 23, 2016
//hw5pr3.cpp
#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
// moss green 173, 223, 173
// cherryblossom 255, 183, 197
int main()
try
{
	Simple_window win(Point(100,100),600,400, "chess board");
	Color cherry_blossom(fl_rgb_color(225,183,197));
	Color moss_green(fl_rgb_color(173,223,173));
	//-----------------
	Vector_ref<Rectangle> sq;
	Point cornerchess(50,50); //upper left hand corner of chessboard
	int width = 8; //width of each square
	int height = 8; //height of each square
	int square_side = 30;
	for (int i; i<width;i++)
	{
		for (int j=0; j<height;++j)
		{
			int move_over_eachloop = square_side*(j%1);
			Rectangle *square = new Rectangle(Point(cornerchess.x+square_side*i+move_over_eachloop,cornerchess.y+square_side*j),square_side,square_side);
			win.attach(*square);
			sq.push_back(square);
			square->set_fill_color(cherry_blossom);
			square->set_color(Color::invisible);
			if ((j%2==0 && i%2!=0) || (i%2==0 && j%2!=0)) //puts color in right spots
			{
				square->set_fill_color(moss_green);
				square->set_color(Color::invisible);
			}
		}
	}
//------------
//chess pieces
int r = 11;
// top of board shadows 
//row1
Circle p1(Point(95,65),r);
Circle p2(Point(95+60,65),r);
Circle p3(Point(95+120,65),r);
Circle p4(Point(95+180,65),r);
p1.set_fill_color(Color::black);
p2.set_fill_color(Color::black);
p3.set_fill_color(Color::black);
p4.set_fill_color(Color::black);
//row2
Circle p5(Point(65,95),r);
Circle p6(Point(65+60,95),r);
Circle p7(Point(65+120,95),r);
Circle p8(Point(65+180,95),r);
p5.set_fill_color(Color::black);
p6.set_fill_color(Color::black);
p7.set_fill_color(Color::black);
p8.set_fill_color(Color::black);
//row3
Circle p9(Point(95,125),r);
Circle p10(Point(95+60,125),r);
Circle p11(Point(95+120,125),r);
Circle p12(Point(95+180,125),r);
p9.set_fill_color(Color::black);
p10.set_fill_color(Color::black);
p11.set_fill_color(Color::black);
p12.set_fill_color(Color::black);
win.attach(p1);
win.attach(p2);
win.attach(p3);
win.attach(p4);
win.attach(p5);
win.attach(p6);
win.attach(p7);
win.attach(p8);
win.attach(p9);
win.attach(p10);
win.attach(p11);
win.attach(p12);
//---------------------------------
// top of board red pieces
//row1
int r2=10;
Circle pr1(Point(95,65),r2);
Circle pr2(Point(95+60,65),r2);
Circle pr3(Point(95+120,65),r2);
Circle pr4(Point(95+180,65),r2);
pr1.set_fill_color(Color::red);
pr2.set_fill_color(Color::red);
pr3.set_fill_color(Color::red);
pr4.set_fill_color(Color::red);
//row2
Circle pr5(Point(65,95),r2);
Circle pr6(Point(65+60,95),r2);
Circle pr7(Point(65+120,95),r2);
Circle pr8(Point(65+180,95),r2);
pr5.set_fill_color(Color::red);
pr6.set_fill_color(Color::red);
pr7.set_fill_color(Color::red);
pr8.set_fill_color(Color::red);
//row3
Circle pr9(Point(95,125),r2);
Circle pr10(Point(95+60,125),r2);
Circle pr11(Point(95+120,125),r2);
Circle pr12(Point(95+180,125),r2);
pr9.set_fill_color(Color::red);
pr10.set_fill_color(Color::red);
pr11.set_fill_color(Color::red);
pr12.set_fill_color(Color::red);
win.attach(pr1);
win.attach(pr2);
win.attach(pr3);
win.attach(pr4);
win.attach(pr5);
win.attach(pr6);
win.attach(pr7);
win.attach(pr8);
win.attach(pr9);
win.attach(pr10);
win.attach(pr11);
win.attach(pr12);
//--------------------------------
//bottom of board shadows

//row1 (bottom)
Circle pp1(Point(95,215),r);
Circle pp2(Point(95+60,215),r);
Circle pp3(Point(95+120,215),r);
Circle pp4(Point(95+180,215),r);
pp1.set_fill_color(Color::black);
pp2.set_fill_color(Color::black);
pp3.set_fill_color(Color::black);
pp4.set_fill_color(Color::black);
//row2 (bottom)
Circle pp5(Point(65,245),r);
Circle pp6(Point(65+60,245),r);
Circle pp7(Point(65+120,245),r);
Circle pp8(Point(65+180,245),r);
pp5.set_fill_color(Color::black);
pp6.set_fill_color(Color::black);
pp7.set_fill_color(Color::black);
pp8.set_fill_color(Color::black);
//row3 (bottom)
Circle pp9(Point(95,275),r);
Circle pp10(Point(95+60,275),r);
Circle pp11(Point(95+120,275),r);
Circle pp12(Point(95+180,275),r);
pp9.set_fill_color(Color::black);
pp10.set_fill_color(Color::black);
pp11.set_fill_color(Color::black);
pp12.set_fill_color(Color::black);
win.attach(pp1);
win.attach(pp2);
win.attach(pp3);
win.attach(pp4);
win.attach(pp5);
win.attach(pp6);
win.attach(pp7);
win.attach(pp8);
win.attach(pp9);
win.attach(pp10);
win.attach(pp11);
win.attach(pp12);
//---------------------------------
//bottom of board white pieces
Circle pw1(Point(95,215),r2);
Circle pw2(Point(95+60,215),r2);
Circle pw3(Point(95+120,215),r2);
Circle pw4(Point(95+180,215),r2);
pw1.set_fill_color(Color::red);
pw2.set_fill_color(Color::red);
pw3.set_fill_color(Color::red);
pw4.set_fill_color(Color::red);
//row2 (bottom)
Circle pw5(Point(65,245),r2);
Circle pw6(Point(65+60,245),r2);
Circle pw7(Point(65+120,245),r2);
Circle pw8(Point(65+180,245),r2);
pw5.set_fill_color(Color::red);
pw6.set_fill_color(Color::red);
pw7.set_fill_color(Color::red);
pw8.set_fill_color(Color::red);
//row3 (bottom)
Circle pw9(Point(95,275),r2);
Circle pw10(Point(95+60,275),r2);
Circle pw11(Point(95+120,275),r2);
Circle pw12(Point(95+180,275),r2);
pw9.set_fill_color(Color::red);
pw10.set_fill_color(Color::red);
pw11.set_fill_color(Color::red);
pw12.set_fill_color(Color::red);
win.attach(pw1);
win.attach(pw2);
win.attach(pw3);
win.attach(pw4);
win.attach(pw5);
win.attach(pw6);
win.attach(pw7);
win.attach(pw8);
win.attach(pw9);
win.attach(pw10);
win.attach(pw11);
win.attach(pw12);
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