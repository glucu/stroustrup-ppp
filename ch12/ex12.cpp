#include "Simple_window.h"
#include "Graph.h"

#include <cmath>

constexpr int Xc = 300;
constexpr int Yc = 200;

int sgn(double w)
{
    if (w < 0) return -1;
    if (w > 0) return 1;
    if (w == 0) return 0;
}

vector<Point> superellipse(double a, double b, double m, double n, int N)
{
    const double PI{3.14159265};

    if((a <= 0 || b <= 0) || (m <= 0 || n <= 0)) error("superellipse: needs positive arguments");

    double p{2*PI/N};

    vector<Point> points;
    for(int i{1}; i <= N; ++i) {
        double t{p * i};
        double x{ pow(abs(cos(t)), 2/m) * a * sgn(cos(t)) };
        double y{ pow(abs(sin(t)), 2/n) * b * sgn(sin(t)) };
        points.push_back(Point{Xc + int(x), Yc + int(y)});
    }

    return points;
}

int main() {

    try {

        const Point tl {100, 100};
        Simple_window win{tl, 2*Xc, 2*Yc, "Chapter 12 - Exercise 12"};

        vector<Point> points = superellipse(200, 100, 0.5, 5, 30);

        Lines l;
        size_t half{points.size() / 2};
        for (size_t i{}; i != half; ++i)
            l.add(points[i], points[half + i]);

        l.set_color(Color::dark_green);

        win.attach(l);

        win.wait_for_button();
    }
    catch(exception& e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "something went wrong\n";
        return 2;
    }
}
