#include "Simple_window.h"
#include "Graph.h"

/* Chapter 13: exercise 2
 *
 * Draw a box with rounded corners. Define a class Box, consisting of four 
 * lines and four arcs. 
 */

int main() {

	try {

		Point tl{ 100, 100 };
		Simple_window win{ tl, 600, 400, "Chapter 13: exercise 2" };

		Graph_lib::Box box{ Point{30, 30}, 300, 200 };
		box.set_color(Color::dark_green);
		box.set_fill_color(Color::white);

		win.attach(box);
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