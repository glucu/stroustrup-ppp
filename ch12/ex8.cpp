#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

int main()
{
    try {
       
        using namespace Graph_lib;

        const Point tl{100,100};
        Simple_window win{tl, 600, 400, "Chapter 12: Exercise 8"};
        
        Circle r1{Point{150, 150}, 50};
        r1.set_style(Line_style{Line_style::solid, 4});
        r1.set_color(Color::blue);

        Circle c2{Point{200, 200}, 50};
        c2.set_style(Line_style{Line_style::solid, 4});
        c2.set_color(Color::yellow);

        Circle c3{Point{260, 150}, 50};
        c3.set_style(Line_style{Line_style::solid, 4});
        c3.set_color(Color::black);

        Circle c4{Point{310, 200}, 50};
        c4.set_style(Line_style{Line_style::solid, 4});
        c4.set_color(Color::green);

        Circle c5{Point{370, 150}, 50};
        c5.set_style(Line_style{Line_style::solid, 4});
        c5.set_color(Color::red);

        win.attach(r1);
        win.attach(c2);
        win.attach(c3);
        win.attach(c4);
        win.attach(c5);
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
