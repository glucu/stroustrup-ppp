#include "Simple_window.h"
#include "Graph.h"

/* Chapter 13: exercise 1
 *
 * Define a class Arc, which draws a part of an ellipse. Hint: fl_arc(). 
 */

int main() {

	try {

		Point tl { 100, 100 };
		Simple_window win{ tl, 600, 400, "Chapter 13: exercise 1" };

		Graph_lib::Arc arc(Point{ 200, 200 }, 100, 100, 90, 180);
		arc.set_color(Color::black);
		arc.set_fill_color(Color::red);
		win.attach(arc);
		win.wait_for_button();

		arc.change_angle(210, 350);
		arc.set_color(Color::blue);
		win.wait_for_button();

		return 0;
	}
	catch (const exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		std::cerr << "something went wrong\n";
		return 2;
	}
}