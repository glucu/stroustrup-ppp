#include "Simple_window.h"
#include "Graph.h"

int main()
{
    try {
        
        using namespace Graph_lib;

        Simple_window win{Point{100,100}, 600, 400, "My window"};

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
