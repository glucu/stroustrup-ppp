#include "Simple_window.h"
#include "Graph.h"

int main()
{
    try {
       
        using namespace Graph_lib;

        const Point tl{100,100};
        Simple_window win{tl, 1920, 1080, "Chapter 12 - Exercise 9"};
        
        Image img{Point{200,200}, "cat.jpg"};
        win.set_label("Black Cat");
        Text caption{Point{406, 190}, "Cat spills coffee. Oops!"};
        caption.set_font(Graph_lib::Font::helvetica);
        caption.set_font_size(20);

        win.attach(img);
        win.attach(caption);
        win.wait_for_button();

        return 0;
    }
    catch(exception &e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Oops: something went wrong\n";
        return 2;
    }
} 
