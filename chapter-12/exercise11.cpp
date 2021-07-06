#include "Simple_window.h"
#include "Graph.h"

/* Chapter 12: exercise 11
 *
 * Draw a series of regular polygons, one inside the other. The innermost should be an equilateral triangle, 
 * enclosed by a square, enclosed by a pentagon, etc. For the mathematically adept only: let all the  points of each 
 * N-polygon touch sides of the (N+1)-polygon.
 */

int main() {

	try {

		Point tl{ 100, 100 };
		Simple_window win{ tl, 600, 400, "Chapter 12: exercise 11" };
		win.wait_for_button();

		constexpr double PI = 3.14159265;
		const int X = win.x_max() / 2 - 50;
		const int Y = win.y_max() / 2 - 50;

		Graph_lib::Polygon tri;
		int alt = std::sin(60 * PI / 180) * 100;
		tri.add(Point{ X, Y + alt });
		tri.add(Point{ X + 50, Y });
		tri.add(Point{ X + 100, Y + alt });
		tri.set_color(Color::red);
		win.attach(tri);

		Graph_lib::Rectangle sqr{ Point{X, Y}, 100, 100 };
		sqr.set_color(Color::green);
		win.attach(sqr);

		Graph_lib::Polygon pent;
		int pr = 50 / std::sin(36 * PI / 180);
		int px = 300;
		int py = 200 - pr;
		pent.add(Point{ px, py });

		px += std::sin(54 * PI / 180) * 100;
		py += std::cos(54 * PI / 180) * 100;
		pent.add(Point{ px, py });

		px -= std::cos(72 * PI / 180) * 100;
		py += std::sin(72 * PI / 180) * 100;
		pent.add(Point{ px, py });

		px -= 100;
		pent.add(Point{ px, py });

		px -= std::cos(72 * PI / 180) * 100;
		py -= std::sin(72 * PI / 180) * 100;
		pent.add(Point{ px, py });

		pent.set_color(Color::blue);
		win.attach(pent);

		Graph_lib::Polygon hex;
		int hx = 250;
		int hy = 200 - pr;
		int hr = std::cos(30 * PI / 180) * 100;
		hex.add(Point{ hx, hy });
		hex.add(Point{ hx + 100, hy });
		hex.add(Point{ hx + 150, hy + hr });
		hex.add(Point{ hx + 100, hy + 2 * hr });
		hex.add(Point{ hx, hy + 2 * hr });
		hex.add(Point{ hx - 50, hy + hr });
		hex.set_color(Color::black);
		win.attach(hex);

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