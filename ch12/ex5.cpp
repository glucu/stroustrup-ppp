#include "Simple_window.h"
#include "Graph.h"

int main()
{
    try {
       
        using namespace Graph_lib;

        const Point tl{100,100};
        Simple_window win{tl, 1920, 1080, "Chapter 12: Exercise 5"};
        
        Rectangle r(Point{10, 10}, win.x_max()*(double(2)/3), win.y_max()*(double(3)/4));

        r.set_style(Line_style{Line_style::solid, 24});
        r.set_color(Color::red);

        win.attach(r);
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
