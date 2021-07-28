#include "Simple_window.h"
#include "Graph.h"

int main() {

    try {
		
    	Point tl{ 100, 100 };
	Simple_window win{ tl, 800, 1000, "Drill 1" };
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
