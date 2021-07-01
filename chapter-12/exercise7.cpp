#include "Simple_window.h"
#include "Graph.h"

/* Chapter 12: exercise 7
 *
 * Draw a two-dimensional house seen from the front, the way a child would: with a door, two windows, and a roof with a chimney.
 * Feel free to add details; maybe have "smoke" come out of the chimney.
 */

int main() {

	try {

		Point tl{ 100, 100 };
		Simple_window win{ tl, 600, 400, "Chapter 12: exercise 7" };
		win.wait_for_button();

		// draw house structure
		Point house_pos{ 200, 200 };
		Graph_lib::Rectangle house{ house_pos, 150, 200 };
		house.set_fill_color(Color::dark_red);
		house.set_style(Line_style{ Line_style::solid, 2 });
		win.attach(house);
		win.wait_for_button();

		// draw left window
		Point left_win_pos{ house_pos.x + 15, house_pos.y + 50 };
		Graph_lib::Rectangle left_win{ left_win_pos, 40, 40 };
		left_win.set_fill_color(Color::blue);
		left_win.set_style(Line_style{ Line_style::solid, 2 });
		win.attach(left_win);

		// draw right window
		Point right_win_pos{ left_win_pos.x + 80, left_win_pos.y };
		Graph_lib::Rectangle right_win{ right_win_pos, 40, 40 };
		right_win.set_fill_color(Color::blue);
		right_win.set_style(Line_style{ Line_style::solid, 2 });
		win.attach(right_win);

		// draw door
		Point door_pos{ 250, house_pos.y + 140 };
		Graph_lib::Rectangle door{ door_pos, 50, 60 };
		door.set_fill_color(Color::green);
		door.set_style(Line_style{ Line_style::solid, 2 });
		win.attach(door);

		// draw door knob
		Graph_lib::Circle knob{ Point{door_pos.x + 35, door_pos.y + 35},5 };
		knob.set_fill_color(Color::black);
		win.attach(knob);

		// draw roof
		Graph_lib::Polygon roof;
		roof.add(Point{ 200, 200 });
		roof.add(Point{ 275, 100 });
		roof.add(Point{ 350, 200 });
		roof.set_fill_color(Color::dark_blue);
		roof.set_style(Line_style{ Line_style::solid, 3 });
		win.attach(roof);

		// draw chimney
		Graph_lib::Polygon chim;
		chim.add(Point{ 200, 75 });
		chim.add(Point{ 250, 75 });
		chim.add(Point{ 250, 130 });
		chim.add(Point{ 200, 200 });
		chim.set_fill_color(Color::black);
		chim.set_style(Line_style{ Line_style::solid, 2 });
		win.attach(chim);

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