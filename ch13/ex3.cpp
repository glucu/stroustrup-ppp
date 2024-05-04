#include "Simple_window.h"
#include "Arrow.h"

int main()
{
    try {
       
        const Point tl{100,100};

        Simple_window win{tl, 600, 400, "Chapter 13: Exercise 3"};

        Arrow arrow1(Point(100,500),Point(400,450));
        win.attach(arrow1);
        Arrow arrow2(Point(500,500),Point(750,250));
        win.attach(arrow2);
        arrow2.set_color(Color::red);
        arrow2.set_fill_color(Color::green);
        arrow2.set_style(Line_style::dot);
        arrow2.set_style(Line_style(Line_style::solid,4));
        arrow2.move(50,50);
        Arrow arrow3(Point(100,500),Point(200,500));
        win.attach(arrow3);
        Arrow arrow4(Point(100,500),Point(100,300));
        win.attach(arrow4);
        Arrow arrow5(Point(100,500),Point(50,500));
        win.attach(arrow5);
        Arrow arrow6(Point(100,500),Point(75,550));
        win.attach(arrow6);
        arrow6.set_color(Color(Color::black,Color::invisible));
        win.wait_for_button();

        return 0;
    }
    catch(runtime_error &e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Oops: something went wrong\n";
        return 2;
    }
} 
