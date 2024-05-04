#include "Simple_window.h"
#include "Graph.h"

int main()
{
    try {

        const Point tl{ 100, 100 };
		Simple_window win{ tl, 600, 400, "Chapter 12: exercise 3" };

		Open_polyline g;
		g.add(Point{ 200, 250 });
		g.add(Point{ 150, 250 });
		g.add(Point{ 150, 300 });
		g.add(Point{ 200, 300 });
		g.add(Point{ 200, 275 });
		g.add(Point{ 175, 275 });
		g.set_style(Line_style{ Line_style::solid, 5 });
		g.set_color(Color::red);

		Open_polyline l;
		l.add(Point{ 250, 250 });
		l.add(Point{ 250, 300 });
		l.add(Point{ 300, 300 });
		l.set_style(Line_style{ Line_style::solid, 5 });
		l.set_color(Color::blue);

		win.attach(g);
		win.attach(l);
		win.wait_for_button();

        return 0;
    }
    catch(runtime_error &e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Oops: something went wrong\n";
        return 2;
    }
}
