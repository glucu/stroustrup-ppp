#include "Simple_window.h"
#include "Graph.h"

int main()
{
    try {
       
        using namespace Graph_lib;

        const Point tl{100,100};
        Simple_window win{tl, 800, 1000, "Alex Loves Yoshi"};

        constexpr int x_max = 800;
        constexpr int y_max = 800;
        int x_grid = 100;
        int y_grid = 100;

        Lines grid{};
        for(int x{x_grid}; x != x_max; x+=x_grid) {
            grid.add({x,0}, {x, y_max});
        }
        for(int y{}; y != y_max; ++y) {
            grid.add({0, y_max}, {x_max, y_max});
        }
        grid.set_color(Color::black);
        win.attach(grid);

        Vector_ref<Rectangle> rects;
        Vector_ref<Image> imgs;

        for(int row{}; row != 8; ++row) {
            for(int col{}; col != 8; ++col) {
                rects.push_back(new Rectangle{{col*x_grid, row*x_grid}, 100, 100});
                imgs.push_back(new Image {{col*x_grid, row*x_grid}, "yoshi-run.png"});
                
                if(col == row) rects[rects.size()-1].set_fill_color(Color::red);
                win.attach(rects[rects.size()-1]);
            }
        }

        win.wait_for_button();

        for(int i{}; i != imgs.size(); ++i) {
            win.attach(imgs[i]);
            win.wait_for_button();
            imgs[i].move(1999, 0);
        }
        
        /*
        win.attach(yoshi1);
        win.attach(yoshi2);
        win.attach(yoshi3);
        */

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
