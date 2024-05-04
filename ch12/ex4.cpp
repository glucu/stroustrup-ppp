#include "Simple_window.h"
#include "Graph.h"

#include <vector>

/* 
 * COMMENT:
 * A couple of insights to meantion here. First I know Graph.h contains a <b>Grid</b> class
 * that will make this easier. But because Chapter 12 never went over it (I assume he does not expect us to use it?)
 * I decided to go and use several Rectangle objects to construct this 3-by-3 tic-tac-toe board. 
 *
 * But there's a problem. class Rectangle derives from class Shape, which in turn, has its copy/move constructors deleted.
 * This makes it harder to construct Rectangle objects of different kinds inside the inner for-loop. So what can be done?
 * One solution I thought about was to make the rect object defined and initialized inside the inner-loop a static object.
 * I quickly realized this only initializes the object ONCE and does not go out of scope until the program terminates. My second solution,
 * to utialize dynamic memory which also involves pointers. Somrthing that was not covered yet...feels like its cheating.
 *
 * But of course, I think Stroustrup wanted us to initialize different Rectangle objects on the stack. But I found that to be a 
 * boring and tedious task.
 */

int main()
{
    try {

        const Point tl{ 100, 100 };
		Simple_window win{ tl, 600, 400, "Chapter 12: Exercise 4" };
        
        const Point rp{100,100};
        Rectangle board{rp, 150, 150};

        vector<Rectangle*> rects;
        int r_x = rp.x;
        int r_y = rp.y;
        const int max_row = 3;
        const int max_col = 3;

        bool is_red{};
        for(int i{}; i != max_row; ++i) {
            for(int j{}; j != max_col; ++j) {
                Rectangle *rect = new Rectangle{Point{r_x,r_y}, board.width()/3, board.height()/3};
                if(is_red) { rect->set_fill_color(Color::red); is_red = false; }
                else       { rect->set_fill_color(Color::white); is_red = true; }

                rects.push_back(rect);

                r_x = r_x + board.width() / 3;
            }
            r_x = rp.x;
            r_y += board.height() / 3;
        }

        for(Rectangle *rect : rects) {
            win.attach(*rect);
        }

        win.attach(board);
		win.wait_for_button();

        for(const Rectangle *rect : rects) {
            delete rect;
        }

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
