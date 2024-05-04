#include "Simple_window.h"
#include "Graph.h"

int main()
{
    try {
        
        using namespace Graph_lib;

        const Point tl{100,100};
        Simple_window win{tl, 600, 400, "Chapter 12: Exercise 2"};

        Rectangle r{Point{300, 100}, 100, 30};
        
        int center_x = 300 + r.width() / 2;
        int center_y = 100 + r.height() / 2;

        Text msg{Point{center_x, center_y}, "Howdy!"};

        win.attach(r);
        win.attach(msg);

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
