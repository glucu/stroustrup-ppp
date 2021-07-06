#include "Simple_window.h"
#include "Graph.h"

/* Chapter 12: exercise 12
 *
 * Look up superellipse on the web to get a better idea of what such shapes look
 * like. Write a program that draws "starlike" patters by connecting point on a
 * superellipse. Take a, b, m, n, and N as arguments. Select N point on the
 * superellipse defined by a, b, m, and, n. Make the point equally spaced for
 * some definition of 'equal'. Connect each of those point to one or more other
 * point (if you like you can make the number of point to which to connect a
 * point another argument or just use N-1, i.e., all the other point).
*/

constexpr double kPi{ 3.14159 };

double sgn(double d) {

	if (d > 0)
		return 1;
	if (d < 0)
		return -1;
	return 0;
}

int main() {

	try
	{
		int a{ 2 };
		int b{ 2 };
		int N = { 50 };
		double m{ 0.5 };
		double n{ 0.5 };

		a = 100 * a;
		b = 100 * b;

		Point p(100, 100);
		Simple_window win(p, a * 2.5, b * 2.5, "Chapter 12: exercise 12");
		win.wait_for_button();

		std::vector<Point> point;

		for (double angle{ }; angle < 2 * kPi; angle += 2 * kPi / N) {

			double x{ std::pow(abs(std::cos(angle)), 2 / m) * a * sgn(std::cos(angle)) + a + 10 };
			double y{ std::pow(abs(std::sin(angle)), 2 / n) * b * sgn(std::sin(angle)) + b + 10 };
			point.push_back(Point(x, y));
		}

		Closed_polyline super_ellipse;
		for (size_t i{}; i < point.size(); ++i)
			super_ellipse.add(point[i]);

		super_ellipse.set_style(Line_style(Line_style::solid, 4));
		win.attach(super_ellipse);
		win.wait_for_button();

		Open_polyline line;
		for (size_t i{}; i < point.size(); ++i) {

			line.add(point[i]);
			for (size_t j{ i }; j < point.size(); ++j) {

				if (i != j) {

					line.add(point[j]);
					line.add(point[i]);
				}
			}
		}
		win.attach(line);

		std::ostringstream oss;
		oss << "screen size: " << x_max() << '*' << y_max()
			<< "; window size: " << win.x_max() << '*' << win.y_max();
		Text sizes{ Point{140, 20}, oss.str() };
		win.attach(sizes);

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