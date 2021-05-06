#include "../include/std_lib_facilities.h"

int main() {

    int squares{1}, curr{1}, prev{};

	while(squares <= 64) {

		std::cout << "Square: " << squares << '\n';
        std::cout << "Number of Grains: " << curr << '\n';
        std::cout << "Running Amount: " << (prev + curr) << "\n\n";
		++squares;
		prev += curr;
		curr *= 2;
	}

    return 0;
}