#include "Graph.h"
#include "Simple_window.h"


/* Chapter 12: Drill 2
 *
 * Now add the examples from §12.7 one by one, testing between each added subsection example. 
 */

int main() {

	using namespace Graph_lib;

	try {

		Point tl{ 100,100 };		// top left corner of the window

		Simple_window win{ tl, 600, 400, "Canvas" };
		// screen coordinate tl for top left corner
		// window size (600*400)
		// title: Canvas
		win.wait_for_button();		// display

		// Axis object
		Axis xa{ Axis::x, Point{20,300}, 280, 10, "x axis" };
		// an Axis is a kind of Shape
		// Axis::x means horizontal
		// starting at (20, 300)
		// 280 pixels long
		// 10 "notches"
		// label the axis "x axis"
		win.attach(xa);					// attach xa to the window win
		win.set_label("Canvas #2");		// relabel the window
		win.wait_for_button();			// display!

		Axis ya{ Axis::y, Point{20,300}, 280, 10, "y axis" };
		ya.set_color(Color::cyan);				// choose a colour
		ya.label.set_color(Color::dark_red);	// choose a colour for the text
		win.attach(ya);
		win.set_label("Canvas #3");
		win.wait_for_button();

		// Function object
		Function sine{ sin, 0, 100, Point{20,150}, 1000, 50, 50 };
		// plot sin() in the range [0:100] with (0,0) at (20,150)
		// using 1000 points; scale x values *50, scale y values *50
		win.attach(sine);
		win.set_label("Canvas #4");
		win.wait_for_button();

		sine.set_color(Color::blue);		// we changed our minds about sines color
		Graph_lib::Polygon poly;			// a polygon; a Polygon is a kind of Shape
		poly.add(Point{ 300,200 });			// three points to make a triangle
		poly.add(Point{ 350,100 });
		poly.add(Point{ 400,200 });
		poly.set_color(Color::red);
		poly.set_style(Line_style::dash);
		win.attach(poly);
		win.set_label("Canvas #5");
		win.wait_for_button();

		// Rectangle object
		Graph_lib::Rectangle r{ Point{200,200}, 100, 50 };
		win.attach(r);
		win.set_label("Canvas #6");
		win.wait_for_button();

		// Closed_polyline object
		Closed_polyline poly_rect;
		poly_rect.add(Point{ 100,50 });
		poly_rect.add(Point{ 200,50 });
		poly_rect.add(Point{ 200,100 });
		poly_rect.add(Point{ 100,100 });
		poly_rect.add(Point{ 50,75 });
		win.attach(poly_rect);
		win.set_label("Canvas #6.2");
		win.wait_for_button();

		r.set_fill_color(Color::yellow);		// colour the inside of the rectangle
		poly.set_style(Line_style(Line_style::dash, 4));
		poly_rect.set_style(Line_style(Line_style::dash, 2));
		poly_rect.set_fill_color(Color::green);
		win.set_label("Canvas #7");
		win.wait_for_button();

		// Text object
		Text t{ Point{150,150}, "Hello, graphical world!" };
		win.attach(t);
		win.set_label("Canvas #8");
		win.wait_for_button();

		t.set_font(Font::times_bold);
		t.set_font_size(20);
		win.set_label("Canvas #9");
		win.wait_for_button();

		// Image object
		Image ii{ Point(100, 50), "image.jpg" };	// 225*225-pixel jpg
		win.attach(ii);
		win.set_label("Canvas #10");
		win.wait_for_button();

		ii.move(100, 200);
		win.set_label("Canvas #11");
		win.wait_for_button();

		// Circle object
		Circle c{ Point{100,200}, 50 };
		Graph_lib::Ellipse e{ Point{100,200}, 75, 25 };
		e.set_color(Color::dark_red);
		Mark m{ Point{100,200}, 'x' };

		std::ostringstream oss;
		oss << "Screen size: " << x_max() << "*" << y_max() << "; window size: " <<
			win.x_max() << "*" << win.y_max();
		Text sizes{ Point{100, 20}, oss.str() };

		Image cal{ Point{225, 225}, "debug.jpg" };      // 512*512-pixels jpg
		cal.set_mask(Point{ 40,40 }, 200, 150);		    // display centre part of image

		win.attach(c);
		win.attach(m);
		win.attach(e);
		win.attach(sizes);
		win.attach(cal);
		win.set_label("Canvas #12");
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