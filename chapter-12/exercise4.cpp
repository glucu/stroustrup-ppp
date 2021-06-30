#include "Simple_window.h"
#include "Graph.h"

/* Chapter 12: exercise 4
 *
 * Draw a 3-by-3 tic-tac-toe board of alternating white and red squares.
 */

int main() {

	try {

		Point tl{ 100, 100 };
		Simple_window win{ tl, 600, 400, "Chapter 12: exercise 4" };
		win.wait_for_button();

		Graph_lib::Rectangle rect1(Point(100, 100), 100, 100);
		rect1.set_fill_color(Color::white);
		win.attach(rect1);
		win.wait_for_button();

		Graph_lib::Rectangle rect2(Point(200, 100), 100, 100);
		rect2.set_fill_color(Color::red);
		win.attach(rect2);
		win.wait_for_button();

		Graph_lib::Rectangle rect3(Point(300, 100), 100, 100);
		rect3.set_fill_color(Color::white);
		win.attach(rect3);
		win.wait_for_button();

		Graph_lib::Rectangle rect4(Point(100, 200), 100, 100);
		rect4.set_fill_color(Color::red);
		win.attach(rect4);
		win.wait_for_button();

		Graph_lib::Rectangle rect5(Point(200, 200), 100, 100);
		rect5.set_fill_color(Color::white);
		win.attach(rect5);
		win.wait_for_button();

		Graph_lib::Rectangle rect6(Point(300, 200), 100, 100);
		rect6.set_fill_color(Color::red);
		win.attach(rect6);
		win.wait_for_button();

		Graph_lib::Rectangle rect7(Point(100, 300), 100, 100);
		rect7.set_fill_color(Color::white);
		win.attach(rect7);
		win.wait_for_button();

		Graph_lib::Rectangle rect8(Point(200, 300), 100, 100);
		rect8.set_fill_color(Color::red);
		win.attach(rect8);
		win.wait_for_button();

		Graph_lib::Rectangle rect9(Point(300, 300), 100, 100);
		rect9.set_fill_color(Color::white);
		win.attach(rect9);

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