#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

/*
 * What happens when you draw a Shape that doesn’t fit inside its window?
 * The remaining shape that does not fit inside the window is not in view, but
 * it is stilled rendered if you expand the window. Which means it does not clip
 * and shape that extends outside the window.
 */


int main()
{
    try {
       
        using namespace Graph_lib;

        const Point tl{100,100};
        Simple_window win{tl, 600, 400, "Chapter 12: Exercise 6"};

        Line l{Point{100,100}, Point{700, 100}};
        l.set_color(Color::blue);

        win.attach(l);
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
