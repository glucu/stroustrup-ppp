#include "Simple_window.h"
#include "Graph.h"

/* Chapter 12: exercise 8
 *
 * Draw the Olympic five rings. If you can't remember the colors, look them up.
 */

int main() {

	try {

		Point tl{ 100, 100 };
		Simple_window win{ tl, 600, 400, "Chapter 12: exercise 8" };
		win.wait_for_button();

		// draw blue ring
		Point blue_pos{ 300, 350 };
		Graph_lib::Circle blue{ blue_pos, 50 };
		blue.set_color(Color::blue);
		blue.set_style(Line_style{ Line_style::solid, 7 });
		win.attach(blue);

		// draw black ring
		Point black_pos{ blue_pos.x + 110, blue_pos.y };
		Graph_lib::Circle black{ black_pos, 50 };
		black.set_color(Color::black);
		black.set_style(Line_style{ Line_style::solid, 7 });
		win.attach(black);

		// draw red ring
		Point red_pos{ black_pos.x + 110, black_pos.y };
		Graph_lib::Circle red{ red_pos, 50 };
		red.set_color(Color::red);
		red.set_style(Line_style{ Line_style::solid, 7 });
		win.attach(red);

		// draw yellow ring
		Point yellow_pos{ 360, 400 };
		Graph_lib::Circle yellow{ yellow_pos, 50 };
		yellow.set_color(Color::yellow);
		yellow.set_style(Line_style{ Line_style::solid, 7 });
		win.attach(yellow);

		// draw green ring
		Point green_pos{ yellow_pos.x + 110, yellow_pos.y };
		Graph_lib::Circle green{ green_pos, 50 };
		green.set_color(Color::green);
		green.set_style(Line_style{ Line_style::solid, 7 });
		win.attach(green);

		std::ostringstream oss;
		oss << "screen size: " << x_max() << '*' << y_max()
			<< "; window size: " << win.x_max() << '*' << win.y_max();
		Text sizes{ Point{140, 20}, oss.str() };
		win.attach(sizes);

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