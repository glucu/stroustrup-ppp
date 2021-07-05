#include "Simple_window.h"
#include "Graph.h"

/* Chapter 12: exercise 9
 *
 * Display an image on the screen, e.g., a photo of a friend.
 * Label the image both with a tiLle on the window and with a caption in the window.
 */

int main() {

	try {

		Point tl{ 100, 100 };
		Simple_window win{ tl, 600, 400, "Chapter 12: exercise 9" };
		win.wait_for_button();

		Point img_pos{ 200, 200 };
		Graph_lib::Image img{ img_pos, "one-piece.jpg" };
		win.attach(img);

		Graph_lib::Text text{ Point{210, 180}, "One Piece anime" };
		text.set_font_size(20);
		text.set_color(Color::blue);
		win.attach(text);

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