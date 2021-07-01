#include "Simple_window.h"
#include "Graph.h"

/* Chapter 12: exercise 5
 *
 * Draw a red 1/4-inch frame around a rectangle that is three-quarters the height of your screen and two-thirds the width.
 */

int main() {

	try {

		Point tl{ 100,100 };
		Simple_window win{ tl, 1920, 1080, "Chapter 12: exercise 5" };
		win.wait_for_button();

		Graph_lib::Rectangle r(Point{ 100, 100 }, 1280, 810);
		r.set_style(Line_style{ Line_style::solid, 15 });
		r.set_color(Color::blue);
		win.attach(r);

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