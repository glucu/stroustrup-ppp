#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

/*
 * What happens when you draw a Window that doesn’t fit on your screen?
 * The window still fits in the screen without any overlapping onto my second monitor, but
 * the label within the "Next" button begins to leak outside.
 *
 */


int main()
{
    try {
       
        using namespace Graph_lib;

        const Point tl{100,100};
        Simple_window win{tl, 2000, 2000, "Chapter 12: Exercise 6"};

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
