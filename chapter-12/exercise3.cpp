#include "Simple_window.h"
#include "Graph.h"

/* Chapter 12: exercise 3
 *
 * Draw your initials 150 pixels high. Use a thick line. Draw each initial in a different color.
 */

int main() {

	try {

		Point tl{ 100, 100 };
		Simple_window win{ tl, 600, 400, "Chapter 12: exercise 3" };
		win.wait_for_button();

		Open_polyline g;
		g.add(Point{ 200, 250 });
		g.add(Point{ 150, 250 });
		g.add(Point{ 150, 300 });
		g.add(Point{ 200, 300 });
		g.add(Point{ 200, 275 });
		g.add(Point{ 175, 275 });
		g.set_style(Line_style{ Line_style::solid, 5 });
		g.set_color(Color::red);
		win.attach(g);
		win.wait_for_button();

		Open_polyline l;
		l.add(Point{ 250, 250 });
		l.add(Point{ 250, 300 });
		l.add(Point{ 300, 300 });
		l.set_style(Line_style{ Line_style::solid, 5 });
		l.set_color(Color::blue);
		win.attach(l);
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