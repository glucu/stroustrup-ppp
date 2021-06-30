#include "Simple_window.h"
#include "Graph.h"

/* Chapter 12: exercise 2
 *
 * Draw a 100-by-30 Rectangle and place the text "Howdy!" inside it.
 */

int main() {

	try {

		Point tl{ 100, 100 };
		Simple_window win{ tl, 600, 400, "Chapter 12: exercise 2" };
		win.wait_for_button();

		// Draw a Rectangle with a Text object inside of it.
		Graph_lib::Rectangle r{ Point{200, 200}, 100, 30 };
		r.set_color(Color::blue);
		win.attach(r);
		win.wait_for_button();

		Graph_lib::Text greet{ Point{225, 220}, "Howdy!" };
		greet.set_font(Font::helvetica_bold);
		greet.set_font_size(15);
		win.attach(greet);
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