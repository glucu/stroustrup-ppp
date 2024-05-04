#include "Simple_window.h"
#include "Graph.h"

int main()
{
    try {
       
        const Point tl{100,100};

        Simple_window win{tl, 600, 400, "Chapter 12: Exercise 1"};

        Rectangle r{Point{300, 100}, 100, 50};
        r.set_color(Color::blue);

        Polygon poly;
        poly.add(Point{300, 200});
        poly.add(Point{400, 200});
        poly.add(Point{400, 250});
        poly.add(Point{300, 250});
        poly.set_color(Color::red);

        win.attach(r);
        win.attach(poly);

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
