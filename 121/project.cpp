
#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"

struct splash_window : Simple_window {
    splash_window(Point xy, int w, int h, const string& title);

private:
    Button start_button;
  	Button next_button;  
	Button quit_button;
	Button back_button1;

	Text instruct_title{Point{255,75},"YOUR MISSION"};
    Image splash_back{Point{0,0},"splash_updated.jpg"};
    Image start_img{Point{100,200},"start_button_updated.jpg"};
    Image quit_img{Point{100,300},"quit_button_updated.jpg"};
	Image mercator{Point{0,0},"mercator_back.jpg"};
	Image play_img{Point{200,150},"play_button.jpg"};
	Image instructions_img{Point{0,0},"instructions.jpg"};
	Image next_button_img{Point{600,500},"next_button.jpg"};
	Image back_button_img{Point{50,500},"back_button.jpg"};
	
	In_box enter;
	//Out_box out;
	//Button Disp;
	Button showbut;
	
	void show()
	{
	getstr();
	cout<<s;
	}
	void getstr()
	{
	s = enter.get_string();
	}
    string s;
	void start();
    void quit();
	void next();
	void back();

};

splash_window::splash_window(Point xy, int w, int h, const string& title)
:Simple_window{xy,w,h,title},
start_button{Point{100,200}, 200, 70, "START",
    [](Address, Address pw) {reference_to<splash_window>(pw).start();}},
quit_button{Point{100,300}, 200, 70, "QUIT",
    [](Address, Address pw) {reference_to<splash_window>(pw).quit();}},
next_button{Point{600,500}, 150,70, "NEXT",
	[](Address, Address pw) {reference_to<splash_window>(pw).next();}},
back_button1{Point{50,500}, 150,70, "BACK",
	[](Address, Address pw) {reference_to<splash_window>(pw).back();}},
showbut{Point{50,300},90,35, "Show",
	[](Address, Address pw) {reference_to<splash_window>(pw).show();}}
enter(Point{100,200}, 200, 70, "Enter"),
//out(Point{600,200}, 200, 70, "Out",
	//[](Address, Address pw) {reference_to<splash_window>(pw) //error here bc button????
		//LOOK UP Out_box SHIT


{

    attach(splash_back);
    attach(start_img);
    attach(quit_img);
    attach(start_button);
    attach(quit_button);

}

void splash_window::next(){
	detach(next_button);
	detach(back_button1);
	detach(instructions_img);
	detach(instruct_title);
	detach(next_button_img);
	detach(back_button_img);
	
	attach(enter);
	//attach(out);
	attach(showbut);
	redraw();
}

void splash_window::back(){
	detach(next_button);
	detach(back_button1);
	detach(instructions_img);
	detach(instruct_title);
	detach(next_button_img);
	detach(back_button_img);
	
	attach(splash_back);
    attach(start_img);
    attach(quit_img);
    attach(start_button);
    attach(quit_button);
	
	redraw();
}

void splash_window::quit(){
    hide();
}

void splash_window::start(){
	detach(splash_back);
	detach(start_img);
	detach(quit_img);
	detach(start_button);
	detach(quit_button);
	
	instruct_title.set_color(Color::white);
    instruct_title.set_font_size(30);
    instruct_title.set_font(FL_COURIER_BOLD);
	
	attach(next_button);
	attach(back_button1);
	attach(instructions_img);
	attach(instruct_title);
	attach(next_button_img);
	attach(back_button_img);
	
    redraw();
}

int main()
try {
    splash_window win (Point(100,100),800,600,"TERRAFORM");
    return gui_main();

}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
