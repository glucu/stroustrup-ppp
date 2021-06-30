#include "Simple_window.h"
#include "Graph.h"

/* Chapter 12: exercise 1
 *
 * Draw a rectangle as a Rectangle and as a Polygon. Make the lines of the Polygon red and the lines of the Rectangle blue.
 */

int main() {

	try {

		Point tl{ 100, 100 };
		Simple_window win{ tl, 600, 400, "Chapter 12: exercise 1" };
		win.wait_for_button();

		// Draw blue Rectangle object.
		Graph_lib::Rectangle rect1{ Point{200, 200}, 100, 50 };
		rect1.set_color(Color::blue);
		win.attach(rect1);
		win.wait_for_button();

		// Draw red Polygon rectangle object.
		Graph_lib::Polygon rect2;
		rect2.add(Point{ 200, 300 });
		rect2.add(Point{ 300, 300 });
		rect2.add(Point{ 300, 350 });
		rect2.add(Point{ 200, 350 });
		rect2.set_color(Color::red);
		win.attach(rect2);
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