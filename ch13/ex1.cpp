#include "Simple_window.h"
#include "Arc.h"

int main()
{
    try {
       
        const Point tl{100,100};

        Simple_window win{tl, 600, 400, "Chapter 13: Exercise 1"};

        Arc arc1(Point{200,200},100,90,180);
        arc1.set_color(Color::black);
        arc1.set_fill_color(Color::cyan);
        win.attach(arc1);
        win.wait_for_button();

        Arc arc2{{400, 200}, 100, 210, 350};
        arc2.set_color(Color::red);
        win.attach(arc2);
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
