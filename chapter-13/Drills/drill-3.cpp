#include "Simple_window.h"
#include "Graph.h"

int main() {

    try {

	Point tl{ 100, 100 };
	Simple_window win{ tl, 800, 1000, "Drill 3" };

	constexpr int x_size{ 800 };
	constexpr int y_size{ 800 };
	constexpr int x_grid{ 100 };
	constexpr int y_grid{ 100 };
	Graph_lib::Lines grid{};

	for (int x{ x_grid }; x < x_size; x += x_grid) {
	    grid.add(Point{ x, 0 }, Point{ x, y_size });
	}

	for (int y{ y_grid }; y < y_size; y += y_grid) {
	    grid.add(Point{ 0,y }, Point{ x_size, y });
	}

	grid.set_color(Color::black);

	win.attach(grid);
	win.wait_for_button();

	Vector_ref<Graph_lib::Rectangle> vr;
	for (int i{}; i < x_size; i += x_grid) {
	    vr.push_back(new Graph_lib::Rectangle{ Point{i,i}, Point{i + x_grid,i + x_grid} }); vr[vr.size() - 1].set_color(Color::invisible);
	    vr[vr.size() - 1].set_fill_color(Color::red);
	    win.attach(vr[vr.size() - 1]);
	}

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
