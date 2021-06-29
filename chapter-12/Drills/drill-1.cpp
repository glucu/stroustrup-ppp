#include "Graph.h"
#include "Simple_window.h"


/* Chapter 12: Drill 1
 *
 * Get an empty Simple_window with the size 600 by 400 and a label My window compiled, linked, and run. 
 * Note that you have to link the FLTK library as described in Appendix D; #include Graph.h, Window.h, and GUI.h 
 * in your code; and include Graph.cpp and Window.cpp in your project.
 */

int main() {

	try {

		Simple_window win{ Point{100, 100}, 600, 400, "My window" };

		win.wait_for_button();

		return 0;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		std::cerr << "something went wrong.\n";
		return 2;
	}
}