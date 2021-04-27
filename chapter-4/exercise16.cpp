#include "../include/std_lib_facilities.h"

int find_mode(std::vector<int> vi) {

    sort(vi);

    int number{ vi[0] };
	int mode{ number };
	int count{ 1 };
	int count_mode{ 1 };

	for (size_t i{ 1 }; i < vi.size(); ++i) {

		if (vi[i] == number)
			++count;
		else {

			if (count > count_mode) {

				count_mode = count;
				mode = number;
			}

			count = 1;
			number = vi[i];
		}
	}

	return mode;
}
int main() {

    std::cout << "Please enter a series of integers followed by 'enter':\n";
    std::vector<int> vi;
    for(int number; std::cin >> number;) {
        vi.push_back(number);
    }

    std::cout << "The mode: " << find_mode(vi) << '\n';
}