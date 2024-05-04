#include "Simple_window.h"
#include "Graph.h"

int main()
{
    try {
       
        Simple_window win{Point{100,100}, 600, 400, "Function graphing"};


        win.attach(orig);
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
