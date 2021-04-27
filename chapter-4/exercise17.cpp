#include "../include/std_lib_facilities.h"

const std::string find_mode(std::vector<std::string> &vs) {

    sort(vs);

    std::string number{ vs[0] };
	std::string mode{ number };
	int count{ 1 };
	int count_mode{ 1 };

	for (size_t i{ 1 }; i < vs.size(); ++i) {

		if (vs[i] == number)
			++count;
		else {

			if (count > count_mode) {

				count_mode = count;
				mode = number;
			}

			count = 1;
			number = vs[i];
		}
	}

	return mode;
}

const std::string find_min(const std::vector<std::string> &vs) {

    std::string min{vs[0]};
    for(size_t i{1}; i < vs.size(); ++i) {
        if(vs[i] < min) min = vs[i];
    }

    return min;
}

const std::string find_max(const std::vector<std::string> &vs) {

    std::string max{vs[0]};
    for(size_t i{1}; i < vs.size(); ++i) {
        if(vs[i] > max) max = vs[i];
    }

    return max;
}


int main() {

    std::cout << "Enter a series of strings followed by 'Ctrl+Z':\n";
    std::vector<std::string> test;
    for(std::string element; std::cin >> element;) {
        test.push_back(element);
    }

    if(test.size() == 0) {
        error("No strings were added");
    }
    else {

        std::string min{ find_min(test) };
        std::string max{ find_max(test) };
        std::string mode{ find_mode(test) };

        std::cout << "The minimum string is " << min << '\n';
        std::cout << "The maximum string is " << max << '\n';
        std::cout << "The mode string is    " << mode << '\n';
    }
}