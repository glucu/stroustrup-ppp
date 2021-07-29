#include "Simple_window.h"
#include "Graph.h"

/* Chapter 13: exercise 3
 *
 * Define a class Arrow, which draws a line with an arrow head. 
 */

int main() {

	try {

		Point tl{ 100, 100 };
		Simple_window win{ tl, 600, 400, "Chapter 13: exercise 3" };

		Graph_lib::Arrow arrow(Point{ 200,300 }, Point{ 500, 300 });
		arrow.set_color(Color::black);
		arrow.set_fill_color(Color::red);
		arrow.set_style(Line_style{ Line_style::solid, 3 });
		win.attach(arrow);
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