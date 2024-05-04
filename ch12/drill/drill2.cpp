#include "Simple_window.h"
#include "Graph.h"

int main()
{
    try {
        
        using namespace Graph_lib;

        const Point tl{100, 100};

        Simple_window win{tl, 600, 400, "Canvas"};

        Polygon poly;

        poly.add(Point{300, 200});
        poly.add(Point{350, 100});
        poly.add(Point{400, 200});

        poly.set_color(Color::red);
        poly.set_style(Line_style::dash);

        Axis xa{Axis::x, Point{20,300}, 280, 10, "x axis"};
        Axis xy{Axis::y, Point{20, 300}, 280, 10, "y axis"};
        xy.set_color(Color::cyan);
        xy.label.set_color(Color::dark_red);

        Function sine{sin, 0, 100, Point{20,150}, 1000, 50,50};
        sine.set_color(Color::blue);

        Rectangle r{Point{200, 200}, 100, 50};

        Closed_polyline poly_rect;
        poly_rect.add(Point{100,50});
        poly_rect.add(Point{200,50});
        poly_rect.add(Point{200,100});
        poly_rect.add(Point{100,100});
        poly_rect.add(Point{50, 75});

        r.set_fill_color(Color::yellow);
        poly.set_style(Line_style(Line_style::dash,4));
        poly_rect.set_style(Line_style(Line_style::dash,2));
        poly_rect.set_fill_color(Color::green);

        Text t{Point{150, 150}, "Hello, graphical world!"};
        t.set_font_size(20);

        Circle c{Point{100,200}, 50};
        Ellipse e{Point{100,200}, 75, 25};
        e.set_color(Color::dark_red);
        Mark m{Point{100,200}, 'x'};

        ostringstream oss;
        oss << "screen size: " << x_max() << "*" << y_max()
            << "; window size: " << win.x_max() << "*" << win.y_max();

        Text sizes{Point{100,20}, oss.str()};

        win.attach(poly);
        win.attach(xa);
        win.attach(xy);
        win.attach(sine);
        win.attach(r);
        win.attach(poly_rect);
        win.attach(t);
        win.attach(c);
        win.attach(e);
        win.attach(m);
        win.attach(sizes);

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
