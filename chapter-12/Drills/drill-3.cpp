#include "Graph.h"
#include "Simple_window.h"

/* Chapter 12: Drill 3
 *
 * Go through and make one minor change (e.g., in color, in  location, or in number of points) 
 * to each of the subsection examples.
 */

int main() {

	using namespace Graph_lib;

	try {

		Simple_window win{ Point{100, 100}, 600, 400, "Time Complexity" };
		win.wait_for_button();

		Axis xa{ Axis::x, Point{20, 350}, 280, 0, "Number of Elements" };
		xa.set_color(Color::black);
		win.attach(xa);
		win.wait_for_button();

		Axis ya{ Axis::y, Point{20, 350}, 280, 0, "Number of Steps" };
		ya.set_color(Color::black);
		win.attach(ya);
		win.wait_for_button();

		Line l1{ Point{20, 330}, Point{380, 20} };
		l1.set_color(Color::black);
		win.attach(l1);
		win.wait_for_button();

		Text lt{ Point{320, 100}, "O(n)" };
		win.attach(lt);
		win.wait_for_button();

		Line l2{ Point{20, 330}, Point{400,330} };
		win.attach(l2);
		win.wait_for_button();

		Text ct{ Point{350, 350}, "O(1)" };
		win.attach(ct);
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