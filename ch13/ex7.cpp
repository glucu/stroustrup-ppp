#include "Simple_window.h"
#include "Graph.h"

int main()
{
    try {

        using namespace Graph_lib;
        const Point tl{100,100};

        Simple_window win{tl, 600, 400, "Chapter 13: Exercise 7"};

        constexpr int color_size = 40;
        Vector_ref<Rectangle> color_chart;
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                color_chart.push_back(new Rectangle{ Point{ i * color_size, j * color_size}, color_size, color_size });
                color_chart[color_chart.size() - 1].set_fill_color(i * 16 + j);
                win.attach(color_chart[color_chart.size() - 1]);
            }
        }

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
