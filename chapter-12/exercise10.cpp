#include "Simple_window.h"
#include "Graph.h"

/* Chapter 12: exercise 10
 * 
 * Draw the file diagram from 12.8
 */

/* COMMENT:
 * Sheesh... not that I don't know how to draw the diagram, but rather it being
 * too much to draw and time consuming. I only did the first three rectangles.
 */

int main() {

	try {

        Point tl{ 100, 100 };
        Simple_window win{ tl, 600, 800, "Chapter 12: exercise 10" };

        Text text1{ Point{52, 48}, "Point.h" };
        text1.set_font_size(16);
        text1.set_color(Color::black);
        win.attach(text1);

        Graph_lib::Rectangle r1{ Point{50, 50}, 150, 40 };
        r1.set_fill_color(Color::yellow);
        win.attach(r1);

        Text text2{ Point{52, 148}, "Graph.h" };
        text2.set_font_size(16);
        text2.set_color(Color::black);
        win.attach(text2);

        Graph_lib::Rectangle r2{ Point{50, 150}, 100, 60 };
        r2.set_fill_color(Color::yellow);
        win.attach(r2);

        Text text3{ Point{27, 288}, "Graph.cpp" };
        text3.set_font_size(16);
        text3.set_color(Color::black);
        win.attach(text3);

        Graph_lib::Rectangle r3{ Point{25, 290}, 70, 30 };
        r3.set_fill_color(Color::yellow);
        win.attach(r3);

        win.wait_for_button();

		return 0;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		std::cerr << "something went wrong.\n";
		return 2;
	}
}