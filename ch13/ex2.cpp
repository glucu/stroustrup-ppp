#include "Simple_window.h"
#include "Box.h"

int main()
{
    try {
       
        const Point tl{100,100};

        Simple_window win{tl, 600, 400, "Chapter 13: Exercise 2"};

        Box box({200,200}, 100, 100, 15); 

        win.attach(box);
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
